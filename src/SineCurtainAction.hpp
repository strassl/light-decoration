#pragma once

#include "FastLED.h"
#include "Math.hpp"

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
        /*
        int sineIdx = row + column + _time;
        auto sineA = sine(sineIdx + 0);
        auto sineB = sine(sineIdx + 4);
        auto sineC = sine(sineIdx + 8);

        auto index = coordinates_to_index<uint8_t, Rows, Columns>(row, column);
        _leds[index] = CHSV(sineA, sineB, 255);
        */
        /*
        auto sineA = sine(row + 0) + sine(column + 0) + sine(_time + 0);
        auto sineB = sine(row + 4) + sine(column + 4) + sine(_time + 4);
        auto sineC = sine(row + 8) + sine(column + 8) + sine(_time + 8);

        auto index = coordinates_to_index<uint8_t, Rows, Columns>(row, column);
        _leds[index] = CHSV(sineA, sineB, 255);
        */
        /*
        int sineIdx = row + column + _time;
        auto sineA = sine(sineIdx + 0);
        auto sineB = sine(sineIdx + 4);
        auto sineC = sine(sineIdx + 8);

        auto index = coordinates_to_index<uint8_t, Rows, Columns>(row, column);
        _leds[index] = CRGB(sineA, sineB, sineC);
        */
        // Right bottom to left top
        auto sineA = sine(row + _time) + sine(column + _time);
        // Right top to left bottom
        auto sineB = sine(row + _time) + sine((Columns - column) + _time);
        // Left bottom to right top
        auto sineC = sine((Rows - row) * 3 + _time) + sine(column * 3 + _time);
        // Left top to right bottom
        auto sineD = sine((Rows - row) * 3 + _time) + sine((Columns - column) * 3 + _time);

        auto index = coordinates_to_index<uint8_t, Rows, Columns>(row, column);
        auto h = (sineA + sineC) % 255;
        auto s = sine(_time * 2) / 2 + 128;
        auto v = sine(row + column + _time);
        _leds[index] = CHSV(h, s, v);
      }
    }

    _time = _time + 1;

    FastLED.show();
  }
};