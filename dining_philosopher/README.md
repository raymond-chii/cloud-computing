# Dining Philosophers Simulation

This project implements the classic Dining Philosophers problem with a visual interface using SFML.

## Problem Description

The Dining Philosophers problem is a classic synchronization problem in computer science:
- Five philosophers sit at a round table with five chopsticks
- Each philosopher needs two chopsticks to eat
- Philosophers alternate between thinking and eating
- A philosopher can only pick up chopsticks that are adjacent to them
- The challenge is to design a solution that allows each philosopher to eat without deadlock

## Features

- Thread-safe implementation using mutexes
- Deadlock prevention through resource acquisition with failure release
- Simulation ends when all philosophers have eaten once


## Building the Project

```bash
# Create a build directory
mkdir -p build
cd build

# Generate build files with CMake
cmake ..

# Build the project
make

# Run the simulation
./dining
```

## Implementation Details

- Each philosopher is represented by a thread
- Chopsticks are protected by mutexes to prevent simultaneous access
- Philosophers randomly decide which chopstick to pick up first to avoid deadlock
- When a philosopher can't acquire both chopsticks, they put down any chopstick they've picked up and try again later

## Exit Conditions

The simulation will end when:
- All philosophers have eaten once
- The user closes the window or presses the Escape key

## Project Structure

- `main.cpp`: Main entry point and simulation loop
- `philosopher.h/cpp`: Philosopher class implementation
- `chopstick.h/cpp`: Chopstick class implementation
- `CMakeLists.txt`: CMake build configuration
