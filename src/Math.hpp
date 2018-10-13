#pragma once
template <typename Num>
inline Num pos_mod(Num i, Num n)
{
  return (i % n + n) % n;
}

// (x - y) % n but also works correctly for unsigned numbers when underflowing
template <typename Num>
inline Num wrapping_sub(Num x, Num y, Num n)
{
  return (x + (n - y % n)) % n;
}

/* Calculates the index into a "snake" ordered array from the actual coordinates
 * i.e.
 * 1  2  3  4
 * 8  7  6  5
 * 9  10 11 12
 */
template <typename Num, Num Rows, Num Columns>
inline Num coordinates_to_index(Num row, Num column)
{
  auto rowOffset = row * Columns;
  auto columnOffset = (row % 2 == 0) ? column : (Columns - column - 1);

  return rowOffset + columnOffset;
}

static constexpr uint8_t SineArrayLength = 37;
static constexpr uint8_t SineArray[SineArrayLength] =
    {128, 150, 171, 191, 209, 225,
     238, 247, 253, 255, 253, 247,
     238, 225, 209, 191, 171, 150,
     128, 105, 84, 64, 46, 30,
     17, 8, 2, 0, 2, 8,
     17, 30, 46, 64, 84, 105,
     127};

template <typename Num>
inline uint8_t sine(Num x)
{
  return SineArray[x % SineArrayLength];
}