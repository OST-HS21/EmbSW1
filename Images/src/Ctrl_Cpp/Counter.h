//
// Counter.h
//
// implements an up/down-Counter
//
// (C) R. Bonderer, HSR Hochschule Rapperswil, Okt. 2017
//

#ifndef COUNTER_H__
#define COUNTER_H__

class Counter {
public:
    Counter(int val = 0);

    void count(int step);
    int getCounter() const;
    void setCounter(int val);

private:
    int countValue;
};

#endif
