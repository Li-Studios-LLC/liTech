#define SDL_MAIN_USE_CALLBACKS
#include <SDL3/SDL_main.h>
#include <liTechFramework/Typedefs.h>
#include <liTechFramework/Utility/Heap.h>
#include <liTechFramework/Graphics/GraphicsContext.h>

struct runtime_t {
    SDL_Window* window;
    liGraphicsContext* context;
    int width, height;
} rt;

SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv) {
    liHeap* heap = liHeap::Instance();
    rt.width = 1280;
    rt.height = 720;
    std::string title = "liTech " + std::to_string(LITECH_MAJOR) + '.' + std::to_string(LITECH_MINOR) + '.' + std::to_string(LITECH_REVISION);
    SDL_Init(SDL_INIT_VIDEO);
    rt.window = SDL_CreateWindow(title.c_str(), rt.width, rt.height, SDL_WINDOW_OPENGL);
    rt.context = liNew<liGraphicsContext>(rt.window);

    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void* appstate) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    rt.context->Swap();
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event) {
    switch (event->type) {
    case SDL_EVENT_QUIT:
        return SDL_APP_SUCCESS;
    default:
        return SDL_APP_CONTINUE;
    }
}

void SDL_AppQuit(void* appstate, SDL_AppResult result) {
    liDelete(rt.context);
    LITECH_DELETE_INSTANCE(liHeap);
}