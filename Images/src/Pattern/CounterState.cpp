//
// CounterState.cpp
//
// implements all states of an up/down-Counter
// this file contains all classes of the state machine.
// it may make sense to have separate files for each state
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, 13.10.2020
//

#include <iostream>
#include "CounterState.h"
using namespace std;


// class CounterState
CounterState* CounterState::changeState(Counter& entity, CounterState* pnewState)
{
  return pnewState;
}

// class IdleState
IdleState* IdleState::getInstance()
{
  static IdleState instance; // local definition guarantees execution order
  return &instance;
}

CounterState* IdleState::handle(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: idleState" << endl;
  if (CounterCtrl::evUp == e)
  {
    // transition actions
    cout << "counter = " << entity.getCounter() << endl;
    // state transition
    return changeState(entity, CountUpState::getInstance());
  }
  else if (CounterCtrl::evDown == e)
  {
    // transition actions
    cout << "counter = " << entity.getCounter() << endl;
    // state transition
    return changeState(entity, CountDownState::getInstance());
  }
  return this;
}

// class CountUpState
CountUpState* CountUpState::getInstance()
{
  static CountUpState instance;
  return &instance;
}

CounterState* CountUpState::handle(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: countUpState" << endl;
  if (CounterCtrl::evCount == e)
  {
    // transition actions
    entity.count(1);
    cout << "counter = " << entity.getCounter() << endl;
    // state transition
    return changeState(entity, CountUpState::getInstance());
  }
  else if (CounterCtrl::evStop == e)
  {
    // transition actions
    // state transition
    return changeState(entity, IdleState::getInstance());
  }
  return this;
}


// class CountDownState
CountDownState* CountDownState::getInstance()
{
  static CountDownState instance;
  return &instance;
}

CounterState* CountDownState::handle(Counter& entity, CounterCtrl::Event e)
{
  cout << "State: countDownState" << endl;
  if (CounterCtrl::evCount == e)
  {
    // transition actions
    entity.count(-1);
    cout << "counter = " << entity.getCounter() << endl;
    // state transition
    return changeState(entity, CountDownState::getInstance());
  }
  else if (CounterCtrl::evStop == e)
  {
    // transition actions
    // state transition
    return changeState(entity, IdleState::getInstance());
  }
  return this;
}
