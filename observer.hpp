#ifndef OBSERVER_HPP
#define OBSERVER_HPP

class Observer {

public:
    virtual ~Observer() {}
    virtual void update(int code) = 0;
};

#endif // OBSERVER_HPP
