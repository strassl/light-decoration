#pragma once

#include "FastLED.h"
#include "Math.hpp"

template <int Rows, int Columns>
class RainbowCurtainAction
{
private:
  CRGB (&_leds)
  [Rows * Columns];
  int _position;
  uint8_t _hue;

  static constexpr int NumLeds = Rows * Columns;

public:
  RainbowCurtainAction(CRGB (&leds)[NumLeds]) : _leds(leds), _position(0), _hue(0)
  {
  }

  void operator()()
  {
    fill_solid(_leds, NumLeds, CRGB::Black);
    for (int row = 0; row < Rows; row++)
    {
      for (int i = 0; i < 4; i++)
      {
        auto index = coordinates_to_index<int, Rows, Columns>(row, pos_mod(_position - i, Columns));
        _leds[index] = CHSV(_hue, 255, 255 - i * 32);
      }
    }

    _hue = _hue + 8;
    _position = pos_mod(_position + 1, Columns);

    FastLED.show();
  }
};