#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
#include <optional>
#include <atomic>
#include <mutex>
#include "philosopher.h"
#include "chopstick.h"

int Philosopher::total_eat = 0;

int main() {
    sf::Vector2u windowSize(1280, 720);
    sf::RenderWindow window(sf::VideoMode(windowSize), "Dining Philosophers");
    window.setFramerateLimit(60);
    
    const int num_philosopher = 5;
    std::vector<Chopstick> chopsticks(num_philosopher);
    std::vector<Philosopher> philosophers;
    std::vector<std::thread> threads;
    std::atomic<bool> simulation_done(false);
    

    for (int i = 0; i < num_philosopher; i++) {
        int left_index = i;
        int right_index = (i + 1) % num_philosopher;
        philosophers.push_back(Philosopher(i, chopsticks[left_index], chopsticks[right_index]));
    }
    

    for (int j = 0; j < num_philosopher; j++) {
        threads.push_back(std::thread([j, &philosophers, &simulation_done, num_philosopher]() {
            while (!simulation_done && Philosopher::total_eat < num_philosopher) {
                philosophers[j].think();
                philosophers[j].eat();
                

                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        }));
    }
    

    // while (window.isOpen()) {
    //     std::optional<sf::Event> eventOpt = window.pollEvent();
        
    //     while (eventOpt) {
    //         const sf::Event& event = *eventOpt;
            
    //         if (event.is<sf::Event::Closed>()) {
    //             window.close();
    //             simulation_done = true;
    //         }
            
    //         eventOpt = window.pollEvent();
    //     }
        
    //     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
    //         window.close();
    //         simulation_done = true;
    //     }
        

    //     if (Philosopher::total_eat >= num_philosopher) {
    //         std::cout << "All philosophers have eaten once. Simulation complete!" << std::endl;
    //         simulation_done = true;
    //     }
        
    //     window.clear(sf::Color::Black);
        


        
    //     window.display();
        

    //     if (simulation_done && window.isOpen()) {
    //         std::this_thread::sleep_for(std::chrono::seconds(2)); 
    //         window.close();
    //     }
    // }
    // simulation_done = true;
    for (auto& t : threads) {
        t.join();
    }
    

    std::cout << "Total successful eat operations: " << Philosopher::total_eat << std::endl;
    std::cout << "Individual philosopher eating status:" << std::endl;
    for (int i = 0; i < num_philosopher; i++) {
        std::cout << "Philosopher " << i << ": " 
                  << (philosophers[i].hasEaten() ? "Has eaten" : "Has NOT eaten") 
                  << std::endl;
    }
    
    return 0;
}