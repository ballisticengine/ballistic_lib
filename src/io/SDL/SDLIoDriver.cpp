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

            void * SDLIoDriver::createEvent() {
                return (void *)new SDL_Event;
            }
            
            bool SDLIoDriver::pollEvent(void *event) {
                return SDL_PollEvent((SDL_Event *)event);
            }
            
            void SDLIoDriver::transform(void *rawEvent, Ballistic::IO::System::IoEvent *event) {
                SDL_Event *sdlEvent = (SDL_Event *)rawEvent;
                
                switch(sdlEvent->type) {
                    case SDL_QUIT:
                        event->type = IoEventType::IOEVENT_EXIT;
                        break;
                    case SDL_KEYDOWN:
                        event->type = IoEventType::IOEVENT_KEYDOWN;
                        event->keyData.keycode = sdlEvent->key.keysym.sym;
                        event->keyData.scancode = sdlEvent->key.keysym.scancode;
                        break;
                    case SDL_KEYUP:
                        event->type = IoEventType::IOEVENT_KEYUP;
                        event->keyData.keycode = sdlEvent->key.keysym.sym;
                        event->keyData.scancode = sdlEvent->key.keysym.scancode;
                        break;
                    
                }
            }

            void SDLIoDriver::destroy() {

            }
            
            void SDLIoDriver::flush() {
                SDL_GL_SwapWindow(window);
            }
        }
    }
}