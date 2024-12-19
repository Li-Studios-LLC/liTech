#include <liTechFramework/Typedefs.h>
#include <liTechFramework/Game.h>
#include <liTechFramework/FileSystem.h>
#include <liTechFramework/GraphicsContext.h>
#include <liTechFramework/InputManager.h>

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

#if defined(LITECH_DEBUG)
int main(int argc, char** argv) {
#elif defined(LITECH_WIN32) && !defined(LITECH_DEBUG)
int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
#endif
	liMemory& memory = liMemory::Instance();
	{
		SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
		liStr title = liStr("liTech ") + liStr(LITECH_MAJOR) + "." + liStr(LITECH_MINOR) + "." + liStr(LITECH_REVISION);
		SDL_Window* window = SDL_CreateWindow(title.CStr(), 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
		bool windowRunning = true;

		liFileSystem* filesystem = liFileSystem::Instance();
		liGraphicsContext* graphicsContext = liNew<liGraphicsContext>();
		graphicsContext->Initialize(window);
		liInputManager* inputManager = liInputManager::Instance();
		inputManager->Initialize();

		liRunner* game = liNew<liRunner>();
		game->Initialize();

		while (windowRunning || game->IsRunning()) {
			liMouse* mouse = inputManager->GetMouse();
			liKeyboard* keyboard = inputManager->GetKeyboard();

			SDL_Event ev;
			while (SDL_PollEvent(&ev)) {
				switch (ev.type) {
				case SDL_EVENT_QUIT:
					windowRunning = false;
					game->Quit();
					break;
				case SDL_EVENT_KEY_DOWN:
					keyboard->_SetKeyDown(ev.key.scancode);
					break;
				case SDL_EVENT_KEY_UP:
					keyboard->_SetKeyUp(ev.key.scancode);
					break;
				case SDL_EVENT_MOUSE_MOTION:
					mouse->_SetPosition(ev.motion.x, ev.motion.y);
					break;
				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					mouse->_SetButtonDown(ev.button.button);
					break;
				case SDL_EVENT_MOUSE_BUTTON_UP:
					mouse->_SetButtonUp(ev.button.button);
					break;
				}
			}

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			game->Render();
			game->Update();
			graphicsContext->Swap();
			inputManager->Update();
		}

		liDelete(game);
		liDelete(graphicsContext);
		LITECH_DELETE_INSTANCE(liInputManager);
		LITECH_DELETE_INSTANCE(liFileSystem);
		SDL_DestroyWindow(window);
		SDL_Quit();
	}
	return 0;
}