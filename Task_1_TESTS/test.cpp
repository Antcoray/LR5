#include <iostream>

#include "pch.h"

double** create2dArray(int k) {
  double** array = new double*[k];
  for (int i = 0; i < k; ++i) {
    array[i] = new double[k];
  }
  return array;
}

void delete2dArray(double** array, int k) {
  for (int i = 0; i < k; ++i) {
    delete[] array[i];
  }
  delete[] array;
}

void fillArrayC(double** array, int k) {
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      array[i][j] = (static_cast<double>(i * i + j * j)) / (i + j + 1);
      //
    }
  }
}

void fillArrayD(double** array, int k) {
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      if (j <= 8) {
        array[i][j] = i * i + j * j;

      } else {
        array[i][j] = (static_cast<double>(i * i + j * j)) / 2;
      }
    }
  }
}

double countDiagSum(double** array, int k) {
  double sum = 0;
  for (int i = 0; i < k; ++i) {
    sum += array[i][i];
  }
  for (int i = 0; i < k; ++i) {
    sum += array[k - i - 1][i];
  }
  return sum;
}

TEST(GeneralDiagonalSumTest, UsualTestByInputData) {
  int k = 2;
  double** array_C_pointer = create2dArray(k);
  fillArrayC(array_C_pointer, k);
  double sum_C = countDiagSum(array_C_pointer, k);
  double** array_D_pointer = create2dArray(k);
  fillArrayD(array_D_pointer, k);
  double sum_D = countDiagSum(array_D_pointer, k);
  delete2dArray(array_C_pointer, k);
  delete2dArray(array_D_pointer, k);
  ASSERT_EQ(sum_C * 3 / 5, 1);
  ASSERT_EQ(sum_D, 4);
}

TEST(EdgeDiagonalSumTest, k_equals_8_and_7) {
  int k = 8;
  double** array_C_pointer = create2dArray(k);
  fillArrayC(array_C_pointer, k);
  double sum_C = countDiagSum(array_C_pointer, k);
  double** array_D_pointer = create2dArray(k);
  fillArrayD(array_D_pointer, k);
  double sum_D = countDiagSum(array_D_pointer, k);
  delete2dArray(array_C_pointer, k);
  delete2dArray(array_D_pointer, k);
  ASSERT_EQ((int)sum_C, 60);
  ASSERT_EQ(sum_D, 560);
  int k1 = 7;
  double** array_C1_pointer = create2dArray(k1);
  fillArrayC(array_C1_pointer, k1);
  double sum_C1 = countDiagSum(array_C1_pointer, k1);
  double** array_D1_pointer = create2dArray(k1);
  fillArrayD(array_D1_pointer, k1);
  double sum_D1 = countDiagSum(array_D1_pointer, k1);
  delete2dArray(array_C1_pointer, k1);
  delete2dArray(array_D1_pointer, k1);
  ASSERT_EQ((int)sum_C1, 44);
  ASSERT_EQ(sum_D1, 364);
}
// k = 8, k = 7, k = 9 --- с наибльшей вероятностью могут привести к ошибке в
// логике программы т.к по условию при k <= 8 массив заполняется одним образом,
// а при k > 8 другим
TEST(EdgeDiagonalSumTest, k_equals_9) {
  int k = 9;
  double** array_C_pointer = create2dArray(k);
  fillArrayC(array_C_pointer, k);
  double sum_C = countDiagSum(array_C_pointer, k);
  double** array_D_pointer = create2dArray(k);
  fillArrayD(array_D_pointer, k);
  double sum_D = countDiagSum(array_D_pointer, k);
  delete2dArray(array_C_pointer, k);
  delete2dArray(array_D_pointer, k);
  ASSERT_EQ((int)sum_C, 77);
  ASSERT_EQ(sum_D, 816);
}
