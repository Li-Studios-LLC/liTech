#include <liTechFramework/Typedefs.h>
#include <liTechFramework/Game.h>
#include <liTechFramework/FileSystem.h>

class liRunner : public liGame {
public:
	~liRunner() {
	}

	void Initialize() override {
	}

	void Render() override {
	}

	void Update() override {
	}
private:
};

#if defined(LITECH_WIN32) && defined(LITECH_DEBUG)
int main(int argc, char** argv) {
#else
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
#endif
	liMemory& memory = liMemory::Instance();
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
		liStr title = liStr("liTech ") + liStr(LITECH_MAJOR) + "." + liStr(LITECH_MINOR) + "." + liStr(LITECH_REVISION);
		SDL_Window* window = SDL_CreateWindow(title.CStr(), 1280, 720, SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);
		bool windowRunning = true;
		liFileSystem* filesystem = liFileSystem::Instance();

		liRunner* game = liNew<liRunner>();
		game->Initialize();

		while (windowRunning || game->IsRunning()) {
			SDL_Event ev;
			while (SDL_PollEvent(&ev)) {
				switch (ev.type) {
				case SDL_EVENT_QUIT:
					windowRunning = false;
					game->Quit();
					break;
				}
			}

			game->Render();
			game->Update();
		}

		liDelete(game);
		LITECH_DELETE_INSTANCE(liFileSystem);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	return 0;
}