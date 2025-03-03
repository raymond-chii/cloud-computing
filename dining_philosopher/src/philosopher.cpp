#include "philosopher.h"
#include <thread>
#include <iostream>
#include <mutex>

static std::mutex eat_mutex;

Philosopher::Philosopher(int philosopher_id, Chopstick& left, Chopstick& right)
    :id(philosopher_id),
     current_state(Thinking),
     has_eaten(false),
     left_chopstick(left),
     right_chopstick(right)
{};

void Philosopher::think() {
    current_state = Thinking;
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100)); // Shorter thinking time
    std::cout << "Philosopher " << id << " is thinking." << std::endl;
};

void Philosopher::eat() {

    if (has_eaten) {
        return;
    }
    
    if (trytoEat()) {
        current_state = Eating;
        
        // Critical section - only increment once per philosopher
        if (!has_eaten) {
            has_eaten = true;
            
            {
                std::lock_guard<std::mutex> lock(eat_mutex);
                total_eat++; 
            }
            
            std::cout << "Philosopher " << id << " is eating." << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
            
            release_resource();
            std::cout << "Philosopher " << id << " is finished." << std::endl;
        }
    }
};

bool Philosopher::trytoEat() {
    if (left_chopstick.try_pickup()) {
        std::cout << "Philosopher " << id << " picked up left chopstick." << std::endl;
        
        if (right_chopstick.try_pickup()) {
            std::cout << "Philosopher " << id << " picked up right chopstick." << std::endl;
            return true;
        } else {

            left_chopstick.put_down();
            return false;
        }
    }
    
    return false;
}

void Philosopher::release_resource() {
    left_chopstick.put_down();
    right_chopstick.put_down();
    std::cout << "Philosopher " << id << " released both chopsticks." << std::endl;
}