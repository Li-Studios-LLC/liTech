#include <liTechFramework/Typedefs.h>
#include <liTechFramework/Utility/Heap.h>
#include <liTechFramework/Graphics/GraphicsContext.h>

int main(int argc, char** argv) {
    liHeap* heap = liHeap::Instance();
    {
        SDL_Init(SDL_INIT_VIDEO);
        std::string title = "liTech " + std::to_string(LITECH_MAJOR) + '.' + std::to_string(LITECH_MINOR) + '.' + std::to_string(LITECH_REVISION);
        int width = 1280;
        int height = 800;
        SDL_Window* window = SDL_CreateWindow(title.c_str(), width, height, SDL_WINDOW_OPENGL);
        bool running = true;
        liGraphicsContext context = liGraphicsContext(window);

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

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            context.Swap();
        }
        
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
    LITECH_DELETE_INSTANCE(liHeap);
    return 0;
}