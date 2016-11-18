#include <iostream>
#include <SDL2/SDL.h>

#include "pipeline/Pipeline.hpp"
#include "modules/ModuleManager.hpp"
#include "modules/Module.hpp"

 

using namespace Ballistic::Core::Modules;
using namespace Ballistic::Core::Pipeline;

class SdlIo : public Module {
protected:
    SDL_Surface *screen;
    SDL_Renderer* displayRenderer;
    SDL_Window *window;

    virtual void initialize() {
        SDL_Init(SDL_INIT_EVERYTHING);
        SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_OPENGL, &window, &displayRenderer);
        screen = SDL_GetWindowSurface(window);
    }

    virtual void destroy() {

    }
    
    bool exit;

public:
    SdlIo() {
        exit = false;
    }
    
    void mainLoop() {
        SDL_Event event;
        while (!exit) {
            while (SDL_PollEvent(& event)) {

                if (event.type == SDL_QUIT) {
                    exit = true;
                }

                if (event.type == SDL_KEYDOWN) {

                }


            }

        }
    }
};



int main() {

    ModuleManager *m = ModuleManager::get();
    SdlIo sdlio, *p;
    m->addModule("sdlIo", &sdlio);
    m->initialize("sdlIo");
    p = (SdlIo*)m->getModule("sdlIo");
    p->mainLoop();
    return 0;
}