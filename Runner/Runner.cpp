#include <liTechBase/Lib.h>
#include <SDL3/SDL.h>

static struct runnerVariables_t {
	bool gameRunning;
} variables;

static void Initialize() {

}

static void MainLoop() {

}

static void Shutdown() {

}

#if defined(LITECH_WIN32) && defined(LITECH_DEBUG)
int main(int argc, char** argv) {
#else
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
#endif
	liMemory& memory = liMemory::Instance();
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
		SDL_Window* window = SDL_CreateWindow("liTech", 1280, 720, SDL_WINDOW_RESIZABLE);
		bool windowRunning = true;
		variables.gameRunning = true;
		Initialize();

		while (windowRunning || variables.gameRunning) {
			SDL_Event ev;
			while (SDL_PollEvent(&ev)) {
				switch (ev.type) {
				case SDL_EVENT_QUIT:
					windowRunning = false;
					variables.gameRunning = false;
					break;
				}
			}

			MainLoop();
		}

		Shutdown();
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	return 0;
}