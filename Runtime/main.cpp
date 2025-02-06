#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include <liTechFramework/Typedefs.h>
#include <liTechFramework/Utility/Heap.h>
#include <liTechFramework/Input/Keyboard.h>
#include <liTechFramework/Input/Mouse.h>
#include <liTechFramework/Graphics/GraphicsContext.h>
#include <liTechFramework/Utility/Resource.h>
#include <liTechFramework/Graphics/ShaderFactory.h>
#include <liTechFramework/Graphics/ShaderProgram.h>
#include <liTechFramework/Graphics/Mesh.h>
#include <liTechFramework/Math/Matrices.h>

extern "C" {
    LITECH_EXPORT unsigned long NvOptimusEnablement = 0x00000001;
    LITECH_EXPORT int AmdPowerXpressRequestHighPerformance = 1;
}

struct runtime_t {
    SDL_Window* window;
    liGraphicsContext* context;
    liMouse* mouse;
    liKeyboard* keyboard;
    int width, height;
    
    liShaderProgram* program;
    liMesh* mesh;
} rt;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv) {
    if(!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
        liTechPrint("Failed to initialize SDL!");
        return  SDL_APP_FAILURE;
    }
    liHeap* heap = liHeap::Instance();
    liResourceManager* resource = liResourceManager::Instance();
    rt.width = 1280;
    rt.height = 720;
    std::string title = "liTech " + std::to_string(LITECH_MAJOR) + '.' + std::to_string(LITECH_MINOR) + '.' + std::to_string(LITECH_REVISION);
    rt.window = SDL_CreateWindow(title.c_str(), rt.width, rt.height, SDL_WINDOW_OPENGL);
    liTechPrint("Running on %s with %d cores", LITECH_PLATFORM_NAME(), LITECH_CPU_COUNT());
    liTechPrint("Using SDL version %d.%d.%d", SDL_VERSIONNUM_MAJOR(SDL_VERSION), SDL_VERSIONNUM_MINOR(SDL_VERSION), SDL_VERSIONNUM_MICRO(SDL_VERSION));
    rt.context = liNew<liGraphicsContext>(rt.window);
    rt.keyboard = liNew<liKeyboard>();
    rt.mouse = liNew<liMouse>();
    
    liGeometry<>* geometry = liNew<liGeometry<>>();
    geometry->AddVertex({ { 0.5f, 0.5f, 0.0f }, });
    geometry->AddVertex({ { 0.5f, -0.5f, 0.0f }, });
    geometry->AddVertex({ { -0.5f, -0.5f, 0.0f }, });
    geometry->AddVertex({ { -0.5f, 0.5f, 0.0f }, });
    geometry->SetIndices({ 0, 1, 3, 1, 2, 3 });
    LITECH_ADD_RESOURCE(geometry);
    
    rt.mesh = liNew<liMesh>(geometry);
    LITECH_ADD_RESOURCE(rt.mesh);

    {
        liShaderFactory* factory = liNew<liShaderFactory>(shaderType_t::MAIN);
        factory->AddPixelModifier("vec4(1, 0, 1, 1)");
        factory->Generate();

        rt.program = liNew<liShaderProgram>();
        LITECH_ADD_RESOURCE(rt.program);

        liShader* vertex = liNew<liShader>(shaderDesignation_t::VERTEX);
        vertex->Compile(factory->VertexCode());
        rt.program->SetVertex(vertex);
        LITECH_ADD_RESOURCE(vertex);

        liShader* pixel = liNew<liShader>(shaderDesignation_t::PIXEL);
        pixel->Compile(factory->PixelCode());
        rt.program->SetVertex(pixel);
        LITECH_ADD_RESOURCE(pixel);

        liDelete(factory);
        rt.program->Link(factory->Type());

        rt.program->Bind();
        liMatrix4f projection, view, model;
        projection = liMatrix4f::Perspective(70.0f, (float)rt.width / (float)rt.height, -0.1f, 100000.0f);
        rt.program->Load("projection", projection);
        rt.program->Load("view", view);
        rt.program->Load("model", model);
    }

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.25f, 0.25f, 0.25f, 1);

    rt.program->Bind();
    rt.mesh->Draw();

    rt.context->Swap();
    rt.mouse->Update();
    rt.keyboard->Update();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
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
        return SDL_APP_CONTINUE;
    case SDL_EVENT_KEY_UP:
        rt.keyboard->keys[event->key.scancode] = (event->key.type == SDL_EVENT_KEY_DOWN);
    default:
        return SDL_APP_CONTINUE;
    }
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    liDelete(rt.mouse);
    liDelete(rt.keyboard);
    liDelete(rt.context);
    liDelete(liResourceManager::Instance());
    LITECH_DELETE_INSTANCE(liHeap);
}