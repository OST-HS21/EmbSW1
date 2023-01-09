//
// CounterCtrl.cpp
//
// implements the Finite State Machine (FSM) of an up/down-Counter as a simple table
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2017
//

#include <iostream>

#include "CounterCtrl.h"
#include "Counter.h"

const CounterCtrl::Transition CounterCtrl::fsm[] = 
{//currentState     triggering event  action function                 next state
  {idleState,       evUp,             &CounterCtrl::actionIdleUp,     countUpState},
  {idleState,       evDown,           &CounterCtrl::actionIdleDown,   countDownState},
  {countUpState,    evCount,          &CounterCtrl::actionUpUp,       countUpState},
  {countUpState,    evStop,           &CounterCtrl::actionDoNothing,  idleState},
  {countDownState,  evCount,          &CounterCtrl::actionDownDown,   countDownState},
  {countDownState,  evStop,           &CounterCtrl::actionDoNothing,  idleState}
};

CounterCtrl::CounterCtrl(int initValue) : 
  currentState(idleState),
  myCounter(initValue) {
}

void CounterCtrl::process(Event e){
  for (size_t i = 0; i < sizeof(fsm) / sizeof(Transition); ++i) {
    if (fsm[i].currentState == currentState &&  fsm[i].ev == e) {
      (this->*fsm[i].pAction)();
      currentState = fsm[i].nextState;
      break;
    }
  }
}

void CounterCtrl::actionDownDown(void) {
  myCounter.count(-1);
}
