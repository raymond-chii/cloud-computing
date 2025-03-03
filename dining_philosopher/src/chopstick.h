#ifndef CHOPSTICK_H
#define CHOPSTICK_H

#include <mutex>

class Chopstick {
private:
  std::mutex m;

public:
  bool try_pickup();
  void put_down();
  bool is_available();
};

#endif