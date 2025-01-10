#ifndef LITECHFRAMEWORK_GRAPHICSCONTEXT_H
#define LITECHFRAMEWORK_GRAPHICSCONTEXT_H
#include "Typedefs.h"

class liGraphicsContext {
public:
    liGraphicsContext(SDL_Window* window);
    ~liGraphicsContext();

    void Initialize();
    void Destroy();
    void Swap();
    void SetVsync(bool vsync = true);
private:
    SDL_Window* window;
    SDL_GLContext context;
    bool vsync;
};

#endif