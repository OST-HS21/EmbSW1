//
// CounterCtrl.h
//
// implements the Finite State Machine (FSM) of an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Oct. 2017
//

#ifndef COUNTERCTRL_H__
#define COUNTERCTRL_H__


#include "Counter.h"

class CounterState;

class CounterCtrl {
  public:
    enum Event{evUp,   
               evDown, 
               evCount,
               evStop};
               
    CounterCtrl(int initValue = 0): 
      entity(initValue), 
      pState(IdleState::getInstance()) {
    }   
    
    void process(Event e) {
      pState =  pState->handle(entity, e);
    }
    
  private:
    Counter entity;
    CounterState* pState;
};
#endif
