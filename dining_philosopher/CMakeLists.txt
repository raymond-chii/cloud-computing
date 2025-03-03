cmake_minimum_required(VERSION 3.10)
project(Dining_Philosophers)

set(CMAKE_CXX_STANDARD 17)

# Explicitly set include and library paths for SFML
set(SFML_INCLUDE_DIR "/opt/homebrew/Cellar/sfml/3.0.0_1/include")
set(SFML_LIBRARY_DIR "/opt/homebrew/Cellar/sfml/3.0.0_1/lib")

# Find SFML with explicit hints
find_package(SFML 3.0 COMPONENTS Graphics Window System
             HINTS ${SFML_LIBRARY_DIR}/cmake/SFML)

# Add include directories directly
include_directories(${SFML_INCLUDE_DIR})

# Add link directories explicitly
link_directories(${SFML_LIBRARY_DIR})

# Print debug information
message(STATUS "SFML Include Dir: ${SFML_INCLUDE_DIR}")
message(STATUS "SFML Library Dir: ${SFML_LIBRARY_DIR}")

# Add the executable
add_executable(dining 
    src/main.cpp
    src/philosopher.cpp
    src/chopstick.cpp
)

# Link SFML libraries directly by name
target_link_libraries(dining
    sfml-graphics
    sfml-window
    sfml-system
)