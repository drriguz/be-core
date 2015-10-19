#include "EventRule.h"

using namespace bd;

EventRule::EventRule(Module* parent):Rule(parent){

}

EventRule::~EventRule(){

}

bool EventRule::invoke(Context &context, Event eventType){
    return true;
}

