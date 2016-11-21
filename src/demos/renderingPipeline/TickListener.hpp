#ifndef TICKHANDLER_HPP
#define TICKHANDLER_HPP
#include "events/Listener.hpp"

using namespace Ballistic::Core::Events;

class TickListener : public Listener {
      virtual void processEvent(void *e);
};

#endif 

