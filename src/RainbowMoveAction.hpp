#pragma once

#include "FastLED.h"
#include "Math.hpp"

template <int NumLeds>
class RainbowMoveAction
{
private:
  CRGB (&_leds)
  [NumLeds];
  int _position;
  uint8_t _hue;

public:
  RainbowMoveAction(CRGB (&leds)[NumLeds]) : _leds(leds), _position(0), _hue(0)
  {
  }

  void operator()()
  {
    fill_solid(_leds, NumLeds, CRGB::Black);

    for (int i = 0; i < 4; i++)
    {
      _leds[pos_mod(_position - i, NumLeds)] = CHSV(_hue, 255, 255 - i * 32);
    }
    FastLED.show();
    _hue = _hue + 8;
    _position = pos_mod(_position + 1, NumLeds);
  }
};