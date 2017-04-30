#include "TickListener.hpp"
#include <iostream>
using namespace std;

TickListener::TickListener() {
    this->mgr = Ballistic::Core::Modules::ModuleManager::get();
    
}

void TickListener::processEvent(void *e) {
    ((RenderingPipeline *)this->mgr->getModule("rendering"))->runAll();
}