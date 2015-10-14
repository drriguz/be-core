#include "EventRule.h"

using namespace bd;

EventRule::EventRule(){

}

EventRule::~EventRule(){

}

bool EventRule::invoke(Context &context, Event eventType){
    return true;
}

