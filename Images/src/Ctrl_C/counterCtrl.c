//
// counterCtrl.c
//
// implements the Finite State Machine (FSM) of an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2019
//

#include <stdio.h>
#include "counterCtrl.h"
#include "counter.h"

typedef enum {idleState,      
              countUpState,   
              countDownState} 
             State;

static State currentState = idleState;

void cnt_ctrlInit(int initValue) {
  currentState = idleState;
  cnt_init(initValue); // model initialize
}


void cnt_ctrlProcess(cnt_Event e) {
  switch (currentState) {
    case countDownState: 
      if (cnt_evCount == e) {
        // actions
        cnt_count(-1);
        // state transition
      }
      else if (cnt_evStop == e) {
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

