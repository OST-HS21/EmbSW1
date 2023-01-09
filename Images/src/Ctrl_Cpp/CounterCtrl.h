//
// CounterCtrl.h
//
// implements the Finite State Machine (FSM) of an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2017
//

#ifndef COUNTERCTRL_H__
#define COUNTERCTRL_H__


#include "Counter.h"

class CounterCtrl {
  public:
    enum Event{evUp,       
               evDown,     
               evCount,    
               evStop};    
               
    CounterCtrl(int initValue = 0);
    
    void process(Event e);

  private:
    enum State{idleState,       
               countUpState,    
               countDownState}; 

    State currentState;         
    Counter myCounter;
};
#endif
