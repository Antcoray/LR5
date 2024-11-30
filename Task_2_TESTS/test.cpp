#include <cmath>
#include <iostream>

#include "pch.h"

bool checkForCondition(double* array, int N) {
  bool condition = false;

  if (N <= 2) {
    for (int i = 0; i < N; ++i) {
      if (pow(pow(array[i], 2) + 2, 1.0 / 3.0) < 10) {
        return true;
      }
    }
    return false;
  }

  int OneThird = N / 3;
  int TwoThird = N - OneThird;
  double* OneThirdOfArray = new double[OneThird];
  double* TwoThirdOfArray = new double[TwoThird];

  for (int i = 0; i < OneThird; ++i) {
    OneThirdOfArray[i] = array[i];
  }
  for (int i = 0; i < TwoThird; ++i) {
    int j = OneThird + i;
    TwoThirdOfArray[i] = array[j];
  }
  condition = checkForCondition(OneThirdOfArray, OneThird) ||
              checkForCondition(TwoThirdOfArray, TwoThird);
  delete[] OneThirdOfArray;
  delete[] TwoThirdOfArray;

  return condition;
}

TEST(GeneralConditionTest, UsualInputData) {
  double* array = new double[4];
  array[0] = 1000;
  array[1] = 100;
  array[2] = -100;
  array[3] = 61;
  EXPECT_FALSE(checkForCondition(array, 4));
}
// Aij по модулю меньшее 31,5911 обращает неравенство из условия в верное,
// поэтому тестируются значения из интервала (30;33) как окрестность точки
// 31,5911
TEST(EdgeConditionTest, Aij_equals_32) {
  double* array = new double[4];
  array[0] = 1000;
  array[1] = 32;
  array[2] = -100;
  array[3] = 61;
  EXPECT_FALSE(checkForCondition(array, 4));
  delete[] array;
}

TEST(EdgeConditionTest, Aij_equals_31_with_fractional_part) {
  double* array = new double[7];
  array[0] = 1000;
  array[1] = 31.123;
  array[2] = -100;
  array[3] = 61;
  array[4] = 67;
  array[5] = 50;
  array[6] = 61;
  EXPECT_TRUE(checkForCondition(array, 7));
  delete[] array;
}