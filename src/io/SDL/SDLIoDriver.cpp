#include "SDLIoDriver.hpp"
namespace Ballistic {
    namespace IO {
        namespace SDL {
            using namespace Ballistic::IO::System;
            void SDLIoDriver::initialize(void *data) {
                SDL_Init(SDL_INIT_EVERYTHING);
                SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_OPENGL, &window, &displayRenderer);
                screen = SDL_GetWindowSurface(window);
            }



            void *SDLIoDriver::poolEvent() {
                
                while (SDL_PollEvent(& event)) {
                    return  (void *)&event;
                }
            }
            
            void SDLIoDriver::transform(void *rawEvent, Ballistic::IO::System::IoEvent *event) {
                SDL_Event *sdlEvent = (SDL_Event *)rawEvent;
                
                switch(sdlEvent->type) {
                    case SDL_QUIT:
                        event->type = IoEventType::IOEVENT_EXIT;
                        break;
                }
            }

            void SDLIoDriver::destroy() {

            }
        }
    }
}