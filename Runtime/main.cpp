#include <liTechFramework/Typedefs.h>

int main(int argc, char** argv) {
    SDL_Init(SDL_INIT_VIDEO);
    std::string title = "liTech " + std::to_string(LITECH_MAJOR) + '.' + std::to_string(LITECH_MINOR) + '.' + std::to_string(LITECH_REVISION);
    int width = 1280;
    int height = 800;
    SDL_Window* window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_OPENGL);
    bool running = true;

    while(running) {
        SDL_Event ev;
        while (SDL_PollEvent(&ev)) {
            switch (ev.type) {
                case SDL_EVENT_QUIT:
                    running = false;
                    break;
                case SDL_EVENT_KEY_DOWN:
                case SDL_EVENT_KEY_UP:
                case SDL_EVENT_MOUSE_MOTION:
                case SDL_EVENT_MOUSE_BUTTON_DOWN:
                case SDL_EVENT_MOUSE_BUTTON_UP:
                    break;
            }
        }
    }
    
    SDL_Quit();
    return 0;
}