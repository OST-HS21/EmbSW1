//
// CounterCtrl.cpp
//
// implements the Finite State Machine (FSM) of an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2017
//

#include <iostream>


#include "CounterCtrl.h"
#include "Counter.h"

CounterCtrl::CounterCtrl(int initValue) : 
  currentState(idleState),
  myCounter(initValue) {
}

void CounterCtrl::process(Event e) {
  switch (currentState) {      
    case countDownState:
      if (evCount == e) {
        // actions
        myCounter.count(-1);
        // state transition
      }
      else if (evStop == e) {
        // actions
        // state transition
        currentState = idleState;
      }
      break;
      
    // [..] other states
      
    default:
      break;
  }
}

