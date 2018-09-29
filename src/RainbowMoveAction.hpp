#pragma once

#include "FastLED.h"
#include "Math.hpp"

template <uint8_t NumLeds>
class RainbowMoveAction
{
private:
  CRGB (&_leds)
  [NumLeds];
  uint8_t _position;
  uint8_t _hue;

public:
  RainbowMoveAction(CRGB (&leds)[NumLeds]) : _leds(leds), _position(0), _hue(0)
  {
  }

  void operator()()
  {
    fill_solid(_leds, NumLeds, CRGB::Black);

    for (uint8_t i = 0; i < 4; i++)
    {
      _leds[wrapping_sub(_position, i, NumLeds)] = CHSV(_hue, 255, 255 - i * 64);
    }
    FastLED.show();
    _hue = _hue + 8;
    _position = (_position + 1) % NumLeds;
  }
};