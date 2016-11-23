#ifndef SDLSYSTEM_HPP
#define SDLSYSTEM_HPP


#include <SDL2/SDL.h>
#include "Base/IoEvent.hpp"
#include "Base/IoDriver.hpp"

namespace Ballistic {
    namespace IO {
        namespace SDL {

            class SDLIoDriver : public Ballistic::IO::System::IoDriver {
            protected:
                virtual void initialize(void *data);
                virtual void destroy();
                //TODO: make ioevent an union
                virtual void transform(void *rawEvent, Ballistic::IO::System::IoEvent *event); 
                virtual bool pollEvent(void *event);
                virtual void * createEvent();
                virtual void flush();
                SDL_Surface *screen;
                SDL_Renderer* displayRenderer;
                SDL_Window *window;
                SDL_Event event;


            public:
                
            };
        }
    }
}


#endif 

