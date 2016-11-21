#ifndef DUMMYRENDERER_HPP
#define DUMMYRENDERER_HPP

#include <iostream>
#include "../RendererInterface.hpp"

using namespace std;

namespace Ballistic {
    namespace Rendering {
        namespace Renderers {

            class DummyRenderer : public RendererInterface {
            public:
                virtual void initialize() {
                    cout << "Dummy init\n";
                    cout.flush();
                };
                virtual void destroy() {
                    cout << "Dummy destroy\n";
                    cout.flush();
                };
                virtual void resize(int w, int h) {};
                virtual void start() {
                    cout << "Dummy start\n";
                    cout.flush();
                };
                virtual void end() {
                    cout << "Dummy end\n";
                    cout.flush();
                };
            };
        }
    }
}

#endif 

