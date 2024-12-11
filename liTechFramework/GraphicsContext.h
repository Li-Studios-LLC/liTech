#ifndef LITECHFRAMEWORK_GRAPHICSCONTEXT_H
#define LITECHFRAMEWORK_GRAPHICSCONTEXT_H
#include "Typedefs.h"

class liGraphicsContext {
public:
	liGraphicsContext();
	liGraphicsContext(const liGraphicsContext&) = delete;
	~liGraphicsContext();

	void Initialize(SDL_Window* window);
	void Swap();
	void SetVsync(bool vsync = true);
private:
	SDL_Window* window;
	SDL_GLContext context;
	bool vsync;
};

#endif