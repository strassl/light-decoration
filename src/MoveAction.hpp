#pragma once

#include "FastLED.h"

template <int NumLeds>
class MoveAction
{
private:
  CRGB (&_leds)
  [NumLeds];
  int _position;

public:
  MoveAction(CRGB (&leds)[NumLeds]) : _leds(leds), _position(0)
  {
  }

  void operator()()
  {
    fill_solid(_leds, NumLeds, CRGB::Black);
    _leds[_position] = CHSV(0, 0, 255);
    FastLED.show();
    _position = (_position + 1) % NumLeds;
  }
};