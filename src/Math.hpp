#pragma once
template <typename Num>
inline Num pos_mod(Num i, Num n)
{
  return (i % n + n) % n;
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