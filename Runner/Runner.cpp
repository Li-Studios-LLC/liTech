#include <liTechBase/Typedefs.h>
#include <SDL3/SDL.h>

#if defined(LITECH_WIN32) && defined(LITECH_DEBUG)
int main(int argc, char** argv) {
#else
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
#endif
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow("Test Window", 1280, 720, SDL_WINDOW_RESIZABLE);
	bool running = true;

	while (running) {
		SDL_Event ev;
		while (SDL_PollEvent(&ev)) {
			switch (ev.type) {
			case SDL_EVENT_QUIT:
				running = false;
				break;
			}
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}