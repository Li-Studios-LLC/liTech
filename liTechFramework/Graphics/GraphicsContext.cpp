#include "GraphicsContext.h"

liGraphicsContext::liGraphicsContext(SDL_Window* window) {
    this->window = window;
    Initialize();
}

liGraphicsContext::~liGraphicsContext() {
    Destroy();
}

void liGraphicsContext::Initialize() {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    this->context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);
    gladLoadGLES2((GLADloadfunc)SDL_GL_GetProcAddress);
    SetVsync();
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