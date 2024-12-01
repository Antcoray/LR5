#include <iostream>

#include "pch.h"

int findcounter(int** array, int N, int K) {
  int counter = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      if (array[i][j] % 2 != 0 && (j + 1) % 2 == 0) {
        ++counter;
      }
    }
  }
  return counter;
}

int* OddEvenNums(int** array, int N, int K, int counter) {
  int* OddEvenArray = new int[counter];
  int k = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      if (array[i][j] % 2 != 0 && (j + 1) % 2 == 0) {
        OddEvenArray[k] = array[i][j];
        ++k;
      }
    }
  }
  return OddEvenArray;
}

double countMean(int* array, int counter) {
  int Sum = 0;
  for (int i = 0; i < counter; ++i) {
    Sum += array[i];
  }
  return static_cast<double>(Sum) / 2;
}

TEST(GeneralTest, UsualInput_1_to_12) {
  int N = 3, K = 4;
  int A = 1;

  int** array = new int*[N];
  for (int i = 0; i < N; ++i) {
    array[i] = new int[K];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      array[i][j] = A;
      ++A;
    }
  }

  int counter = findcounter(array, N, K);
  if (counter != 0) {
    int* NewArray = OddEvenNums(array, N, K, counter);

    double mean = countMean(NewArray, counter);

    delete[] NewArray;
  }
  for (int i = 0; i < N; ++i) {
    delete[] array[i];
  }
  delete[] array;

  EXPECT_EQ(counter, 0);
}
// краевыми будут такие наборы данных, при которых среднее арифметическое либо
// существует либо, нет
TEST(EdgeTest, Input_2_to_13) {
  int N = 3, K = 4;
  int A = 2;

  int** array = new int*[N];
  for (int i = 0; i < N; ++i) {
    array[i] = new int[K];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      array[i][j] = A;
      ++A;
    }
  }
  double mean = 0;
  int counter = findcounter(array, N, K);
  if (counter != 0) {
    int* NewArray = OddEvenNums(array, N, K, counter);

    mean = countMean(NewArray, counter);

    delete[] NewArray;
  }
  for (int i = 0; i < N; ++i) {
    delete[] array[i];
  }
  delete[] array;

  EXPECT_EQ(counter, 6);
  EXPECT_EQ(mean, 24);
}

TEST(EdgeTest, Input_11_to_22) {
  int N = 3, K = 4;
  int A = 11;

  int** array = new int*[N];
  for (int i = 0; i < N; ++i) {
    array[i] = new int[K];
  }
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      array[i][j] = A;
      ++A;
    }
  }
  double mean = 0;
  int counter = findcounter(array, N, K);
  if (counter != 0) {
    int* NewArray = OddEvenNums(array, N, K, counter);

    mean = countMean(NewArray, counter);

    delete[] NewArray;
  }
  for (int i = 0; i < N; ++i) {
    delete[] array[i];
  }
  delete[] array;

  EXPECT_EQ(counter, 0);
}