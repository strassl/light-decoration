#pragma once

#include "FastLED.h"
#include "Math.hpp"

template <uint8_t Rows, uint8_t Columns>
class RainbowCurtainAction
{
private:
  CRGB (&_leds)
  [Rows * Columns];
  uint8_t _position;
  uint8_t _hue;

  static constexpr uint8_t NumLeds = Rows * Columns;

public:
  RainbowCurtainAction(CRGB (&leds)[NumLeds]) : _leds(leds), _position(0), _hue(0)
  {
  }

  void operator()()
  {
    fill_solid(_leds, NumLeds, CRGB::Black);
    for (uint8_t row = 0; row < Rows; row++)
    {
      for (uint8_t i = 0; i < 4; i++)
      {
        auto index = coordinates_to_index<uint8_t, Rows, Columns>(row, wrapping_sub(_position, i, Columns));
        _leds[index] = CHSV(_hue, 255, 255 - i * 64);
      }
    }

    _hue = _hue + 8;
    _position = (_position + 1) % Columns;

    FastLED.show();
  }
};