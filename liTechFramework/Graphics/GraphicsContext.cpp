#include "GraphicsContext.h"

liGraphicsContext::liGraphicsContext(SDL_Window* window) {
    this->window = window;
    Initialize();
}

liGraphicsContext::~liGraphicsContext() {
    Destroy();
}

void liGraphicsContext::Initialize() {
#ifdef LITECH_OPENGLES
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
#endif

    this->context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);
    gladLoadGLES2((GLADloadfunc)SDL_GL_GetProcAddress);
    SetVsync();

    std::string info = "GPU specs:\n\t" + Renderer() + "\n\t" + Version();
    liTechPrint("%s", info.c_str());
}

void liGraphicsContext::Destroy() {
    SDL_GL_DestroyContext(context);
}

void liGraphicsContext::Swap() {
    SDL_GL_SwapWindow(window);
}

void liGraphicsContext::SetVsync(bool vsync) {
    this->vsync = vsync;
    SDL_GL_SetSwapInterval(vsync);
}

std::string liGraphicsContext::Renderer() const {
    return std::string((const char*)glGetString(GL_RENDERER));
}

std::string liGraphicsContext::Vendor() const {
    return std::string((const char*)glGetString(GL_VENDOR));
}

std::string liGraphicsContext::Version() const {
    return std::string((const char*)glGetString(GL_VERSION));
}