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

class CounterState  // abstract base class
{
  public:
    static CounterState* init(Counter& entity);
    // should be called first, returns new state
    virtual CounterState* handle(Counter& entity, CounterCtrl::Event e) = 0;
    // returns new state
  protected:
    virtual void entryAction(Counter& entity) {};
    virtual void exitAction(Counter& entity) {};
    typedef void (CounterState::*Action)(Counter& entity);   // ptr to action function
    CounterState* changeState(Counter& entity, Action ptransAction, CounterState* pnewState);

    // transition actions
    void emptyAction(Counter& entity) {};
    void showCounter(Counter& entity);
    void countUp(Counter& entity);
    void countDown(Counter& entity);
};

class IdleState : public CounterState // it's a singleton
{
  public:
    static IdleState* getInstance();
    CounterState*  handle(Counter& entity, CounterCtrl::Event e) override;
  protected:
    void entryAction(Counter& entity) override;
    void exitAction(Counter& entity) override;
  private:
    IdleState() {};
};

class CountUpState : public CounterState // it's a singleton
{
  public:
    static CountUpState* getInstance();
    CounterState*  handle(Counter& entity, CounterCtrl::Event e) override;
  protected:
    void entryAction(Counter& entity) override;
    void exitAction(Counter& entity) override;
  private:
    CountUpState() {};
};

class CountDownState : public CounterState // it's a singleton
{
  public:
    static CountDownState* getInstance();
    CounterState*  handle(Counter& entity, CounterCtrl::Event e) override;
  protected:
    void entryAction(Counter& entity) override;
    void exitAction(Counter& entity) override;
  private:
    CountDownState() {};
};
#endif
