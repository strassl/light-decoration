#pragma once

#include "FastLED.h"
#include "Math.hpp"

static constexpr uint8_t SineLength = 37;
static constexpr uint8_t Sine[SineLength] =
    {128, 150, 171, 191, 209, 225,
     238, 247, 253, 255, 253, 247,
     238, 225, 209, 191, 171, 150,
     128, 105, 84, 64, 46, 30,
     17, 8, 2, 0, 2, 8,
     17, 30, 46, 64, 84, 105,
     127};

template <uint8_t Rows, uint8_t Columns>
class SineCurtainAction
{
private:
  static constexpr uint8_t NumLeds = Rows * Columns;

  CRGB (&_leds)
  [NumLeds];

  uint8_t _time;

public:
  SineCurtainAction(CRGB (&leds)[NumLeds]) : _leds(leds), _time(0)
  {
  }

  void operator()()
  {
    fill_solid(_leds, NumLeds, CRGB::Black);
    for (uint8_t row = 0; row < Rows; row++)
    {
      for (uint8_t column = 0; column < Columns; column++)
      {
        int sineIdx = row + column + _time;
        auto sineA = Sine[sineIdx % SineLength];
        auto sineB = Sine[(sineIdx + 4) % SineLength];
        auto sineC = Sine[(sineIdx + 8) % SineLength];

        auto index = coordinates_to_index<uint8_t, Rows, Columns>(row, column);
        _leds[index] = CHSV(sineA, sineB, sineC);
      }
    }

    _time = _time + 1;

    FastLED.show();
  }
};