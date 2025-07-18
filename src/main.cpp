#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include "pch.h"
#include <Engine/Tools/FileIO.h>
#include <Engine/Framework/Stopwatch.h>
#include <Engine/Input/Keyboard.h>
#include <Engine/Input/Mouse.h>
#include <Engine/Graphics/RenderPass.h>
#include <Engine/Graphics/PostProcessing.h>
#include <Engine/Framework/AssetManager.h>
#include <Engine/Graphics/RenderShader.h>
#include <Engine/Graphics/ShaderProgram.h>
#include "imgui/imgui_impl_sdl3.h"
#include "imgui/imgui_impl_opengl3.h"
#include "Runtime.h"

static struct runtime_t {
    SDL_Window* window;
    SDL_GLContext gl;
    int width, height;
    liStopwatch stopwatch;
    float elapsed;
    liKeyboard* keyboard;
    liMouse* mouse;
    liRenderPass* renderPass;
    liPostProcessing* post;
    liAssetManager* asset;

    uint_t modeIndex;
    std::vector<liGame*> modes;
} rt;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv) {
    *appstate = static_cast<void*>(&rt);
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMEPAD);

    rt.width = 1280;
    rt.height = 800;
    rt.window = SDL_CreateWindow("liTech", rt.width, rt.height, SDL_WINDOW_OPENGL | SDL_WINDOW_HIGH_PIXEL_DENSITY);
#if !(ANDROID || IOS)
    SDL_AddGamepadMappingsFromFile("./Assets/gamecontrollerdb.txt");
#endif
    rt.elapsed = 0.0f;
    rt.keyboard = new liKeyboard();
    rt.mouse = new liMouse();

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    rt.gl = SDL_GL_CreateContext(rt.window);
    SDL_GL_MakeCurrent(rt.window, rt.gl);
    gladLoadGLES2((GLADloadfunc)SDL_GL_GetProcAddress);
    rt.renderPass = new liRenderPass(rt.width, rt.height, true);
    rt.post = new liPostProcessing();
    rt.asset = new liAssetManager();

    ImGui::CreateContext();
    ImGui_ImplSDL3_InitForOpenGL(rt.window, rt.gl);
    ImGui_ImplOpenGL3_Init("#version 300 es");

    // Default 3d assets
    {
        liRenderShader* shader3d = new liRenderShader();
        std::string vertexSource, pixelSource;
        liFileIO::Read("./Assets/Shaders/standard.vert", vertexSource);
        liFileIO::Read("./Assets/Shaders/standard.frag", pixelSource);
        shader3d->CompileVertex(vertexSource);
        shader3d->CompilePixel(pixelSource);
        rt.asset->LoadAsset("DefaultShader3D", shader3d);
        
        liShaderProgram* program3d = new liShaderProgram();
        shader3d->Attach(program3d);
        program3d->Link({ { 0, "position" }, { 1, "texCoord" }, { 2, "normal" } });
        rt.asset->LoadAsset("DefaultShaderProgram3D", program3d);
    }

    gameContext_t context = {
        .keyboard = rt.keyboard,
        .mouse = rt.mouse,
        .renderPass = rt.renderPass,
        .post = rt.post,
        .assets = rt.asset
    };
    rt.modes.push_back(new liRuntime(context));
    rt.modeIndex = 0;

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    rt.stopwatch.Begin();
    double deltaTime = rt.stopwatch.Seconds();
    rt.elapsed += rt.stopwatch.Seconds();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplSDL3_NewFrame();
    ImGui::NewFrame();

    rt.renderPass->Begin(liColor(0.5f, 0.25f, 0.25f, 1.0f));

    rt.modes[rt.modeIndex]->Render();
    rt.modes[rt.modeIndex]->Update(deltaTime);

    rt.renderPass->End();
    glClear(GL_COLOR_BUFFER_BIT);
    rt.post->Process(rt.renderPass);

    rt.modes[rt.modeIndex]->ImGui();
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    SDL_GL_SwapWindow(rt.window);
    rt.keyboard->Update();
    rt.mouse->Update();
    rt.stopwatch.End();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    //ImGui_ImplSDL3_ProcessEvent(event);
    switch (event->type) {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    case SDL_EVENT_MOUSE_MOTION:
        rt.mouse->x = event->motion.x;
        rt.mouse->y = event->motion.y;
        return SDL_APP_CONTINUE;
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
    case SDL_EVENT_MOUSE_BUTTON_UP:
        rt.mouse->buttons[event->button.button] = (event->button.type == SDL_EVENT_MOUSE_BUTTON_DOWN);
        return SDL_APP_CONTINUE;
    case SDL_EVENT_KEY_DOWN:
    case SDL_EVENT_KEY_UP:
        rt.keyboard->keys[event->key.scancode] = (event->key.type == SDL_EVENT_KEY_DOWN);
    default:
        return SDL_APP_CONTINUE;
    }
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    for(ulong_t i = 0; i < rt.modes.size(); i++) {
        delete rt.modes[i];
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL3_Shutdown();
    ImGui::DestroyContext();

    delete rt.asset;
    delete rt.post;
    delete rt.renderPass;
    delete rt.mouse;
    delete rt.keyboard;
    SDL_GL_DestroyContext(rt.gl);
    SDL_DestroyWindow(rt.window);
}