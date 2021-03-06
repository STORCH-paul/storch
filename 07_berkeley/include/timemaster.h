#pragma once

#include <string>

#include "clock.h"
#include "channel.h"

class TimeMaster
{
private:
  Clock _clock;
  Channel *_channel1;
  Channel *_channel2;
  void berkeley_sync();

public:
  TimeMaster(std::string name, int hours, int minutes, int seconds, bool monotone);
  void set_clock_speed(int speed)
  {
    _clock.set_clock_speed_offset(speed);
  }
  void set_channel1(Channel *c)
  {
    _channel1 = c;
  }
  void set_channel2(Channel *c)
  {
    _channel2 = c;
  }
  void operator()();
};