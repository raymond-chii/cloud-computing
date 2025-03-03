#include "chopstick.h"
#include <mutex>

bool Chopstick::try_pickup() { return m.try_lock(); };

void Chopstick::put_down() { m.unlock(); };

bool Chopstick::is_available() {
  if (m.try_lock()) {
    m.unlock();
    return true;
  } else {
    return false;
  }
};
