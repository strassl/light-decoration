#pragma once

#include "FastLED.h"

template <uint8_t NumLeds>
class ColorFadeAction
{
private:
  CRGB (&_leds)
  [NumLeds];

  uint8_t _time;

public:
  ColorFadeAction(CRGB (&leds)[NumLeds]) : _leds(leds), _time(0)
  {
  }

  void operator()()
  {
    fill_solid(_leds, NumLeds, CHSV(_time, 255, 255));
    _time = _time + 1;
    FastLED.show();
  }
};