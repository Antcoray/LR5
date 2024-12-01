#include <iostream>

#include "pch.h"

bool checkForZeros(double** array, int N, int K) {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      if (array[i][j] == 0) {
        return true;
      }
    }
  }
  return false;
}

int countZeros(double** array, int N, int K) {
  int count = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      if (array[i][j] == 0) {
        ++count;
      }
    }
  }
  return count;
}

double** viceVersa(double** array, int N, int K) {
  double** viceVersaArray = new double*[N];
  for (int i = 0; i < N; ++i) {
    viceVersaArray[i] = new double[K];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      viceVersaArray[i][j] = array[N - i - 1][K - j - 1];
    }
  }
  return viceVersaArray;
}

TEST(GeneralTest, UsualInput_one_zero) {
  int N = 3, K = 4;
  int A = 0;

  double** array = new double*[N];
  for (int i = 0; i < N; ++i) {
    array[i] = new double[K];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      array[i][j] = A;
      ++A;
    }
  }
  int NumberOfZeros = 0;
  bool zerosIncluded = checkForZeros(array, N, K);
  if (zerosIncluded) {
    NumberOfZeros = countZeros(array, N, K);
  }

  double** NewArray = viceVersa(array, N, K);

  EXPECT_EQ(NumberOfZeros, 1);
  EXPECT_TRUE(zerosIncluded);
  ASSERT_EQ(NewArray[1][1], array[1][2]);
  EXPECT_TRUE(NewArray[1][2] != array[2][3]);

  for (int i = 0; i < N; ++i) {
    delete[] NewArray[i];
  }
  delete[] NewArray;

  for (int i = 0; i < N; ++i) {
    delete[] array[i];
  }
  delete[] array;
}
// краевые случаи - когда нулей нет и когда есть
TEST(EdgeTest, No_zeros) {
  int N = 3, K = 3;
  int A = 1;

  double** array = new double*[N];
  for (int i = 0; i < N; ++i) {
    array[i] = new double[K];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      array[i][j] = A;
      ++A;
    }
  }
  int NumberOfZeros = 0;
  bool zerosIncluded = checkForZeros(array, N, K);
  if (zerosIncluded) {
    NumberOfZeros = countZeros(array, N, K);
  }

  double** NewArray = viceVersa(array, N, K);

  EXPECT_EQ(NumberOfZeros, 0);
  EXPECT_TRUE(!zerosIncluded);
  ASSERT_EQ(NewArray[2][1], array[0][1]);
  EXPECT_TRUE(NewArray[0][2] != array[0][2]);

  for (int i = 0; i < N; ++i) {
    delete[] NewArray[i];
  }
  delete[] NewArray;

  for (int i = 0; i < N; ++i) {
    delete[] array[i];
  }
  delete[] array;
}

TEST(EdgeTest, All_zeros) {
  int N = 4, K = 3;

  double** array = new double*[N];
  for (int i = 0; i < N; ++i) {
    array[i] = new double[K];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      array[i][j] = 0;
    }
  }
  int NumberOfZeros = 0;
  bool zerosIncluded = checkForZeros(array, N, K);
  if (zerosIncluded) {
    NumberOfZeros = countZeros(array, N, K);
  }

  double** NewArray = viceVersa(array, N, K);

  EXPECT_EQ(NumberOfZeros, 12);
  EXPECT_TRUE(zerosIncluded);
  ASSERT_EQ(NewArray[2][1], array[0][1]);

  for (int i = 0; i < N; ++i) {
    delete[] NewArray[i];
  }
  delete[] NewArray;

  for (int i = 0; i < N; ++i) {
    delete[] array[i];
  }
  delete[] array;
}