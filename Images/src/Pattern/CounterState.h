//
// CounterState.h
//
// implements an up/down-Counter
// this file contains all classes of the state machine
// it may make sense to have separate files for each state
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, 13.10.2020
//

#ifndef COUNTERSTATE_H__
#define COUNTERSTATE_H__


#include "CounterCtrl.h"

class CounterState {
public:
  virtual CounterState* handle(Counter& entity, 
                               CounterCtrl::Event e) = 0;
    
protected:
  CounterState* changeState(Counter& entity, 
                            CounterState* pnewState);
};

class CountDownState : public CounterState {
public:

  static CountDownState* getInstance() {
    static CountDownState instance;
    return &instance;
  }

  CounterState*  handle(Counter& entity,
                        CounterCtrl::Event e) override {
      if (CounterCtrl::evCount == e) {
        // transition actions
        entity.count(-1);
        // state transition
        return changeState(entity, CountDownState::getInstance());
      }
      else if (CounterCtrl::evStop == e) {
        // transition actions
        // state transition
        return changeState(entity, IdleState::getInstance());
      }

      return this;
    }
  
private:
  CountDownState() {};
};

// [..] other states

#endif
