#ifndef LITECHFRAMEWORK_GRAPHICS_CONTEXT_H
#define LITECHFRAMEWORK_GRAPHICS_CONTEXT_H
#include "Typedefs.h"

class liGraphicsContext {
public:
	static liGraphicsContext* Instance() {
		static liGraphicsContext* instance = nullptr;
		if (!instance) {
			instance = liNew<liGraphicsContext>();
		}
		return instance;
	}

	liGraphicsContext();
	liGraphicsContext(const liGraphicsContext&) = delete;
	~liGraphicsContext();

	void Initialize(SDL_Window* window);
	void Swap();
private:
	SDL_Window* window;
	SDL_GLContext context;
	bool vsync;
};

#endif