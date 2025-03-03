#ifndef PHILOSOPHER_H
#define PHILOSOPHER_H
#include "chopstick.h"

class Philosopher {
private:
    int id;
    enum State {Thinking, Hungry, Eating};
    State current_state;
    bool has_eaten;
    

    Chopstick& left_chopstick;
    Chopstick& right_chopstick;
    
public:

    static int total_eat;
    
    Philosopher(int philosopher_id, Chopstick& left, Chopstick& right);
    
    void think();
    void eat();
    bool trytoEat();
    void release_resource();
    bool hasEaten() const { return has_eaten; }
};

#endif