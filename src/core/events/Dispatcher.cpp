#include "Dispatcher.hpp"
#include "Listener.hpp"

namespace Ballistic {
    namespace Core {
        namespace Events {
            void Dispatcher::addListener(std::string eventName, void *target) {
                eventListeners.insert(std::pair<std::string, void*>(eventName, target));
            }
            
            void * Dispatcher::dispatch(void *e) {
                using namespace std;
                pair<multimap<string, void *>::iterator, multimap<string, void*>::iterator> ii;
                ii = eventListeners.equal_range(((Event *)e)->getName());
                multimap<string, void *>::iterator it; 
                for(it=ii.first; it!=ii.second; it++) {
                    Listener *listener = (Listener *)it->second;
                    listener->processEvent(e);
                }
                
                return e;
            }
            
            void * Dispatcher::dispatchOnce(void *e, void *target) {
                ((Listener *)target)->processEvent(e);
                return e;
            }
            
            
        }
    }
}