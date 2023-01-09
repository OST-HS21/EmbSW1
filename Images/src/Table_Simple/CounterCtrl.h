//
// CounterCtrl.h
//
// implements the Finite State Machine (FSM) of an up/down-Counter as a simple table
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
    
    typedef void (CounterCtrl::*Action)(void);  
  
    // action functions
    void actionIdleUp(void);
    void actionIdleDown(void);
    void actionDoNothing(void);
    void actionUpUp(void);
    void actionDownDown(void);
    
    struct Transition {
      State currentState;  
      Event ev;            
      Action pAction;      
      State nextState;     
    };
    static const Transition fsm[];
};
#endif
