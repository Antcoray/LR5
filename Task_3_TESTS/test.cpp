#include <iostream>

#include "pch.h"

int* BuildNewMatrix(int** array, int LastIndexM, int LastIndexN, int counter) {
  if (counter == 0) {
    return nullptr;
  }
  int* NewArray = new int[counter];
  int j = 0;
  for (int i = 0; i <= LastIndexM; ++i) {
    if (array[i][i] % 2 == 0) {
      NewArray[j] = array[i][i];
      ++j;
    }
  }
  return NewArray;
}

int findcounter(int** array, int LastIndexM, int LastIndexN) {
  int counter = 0;
  for (int i = 0; i <= LastIndexM; ++i) {
    for (int j = 0; j <= LastIndexN; ++j) {
      if (array[i][j] % 2 == 0 && i == j) {
        ++counter;
      }
    }
  }
  return counter;
}

int CountMultiplication(int* array, int counter) {
  int M = 1;
  if (array != nullptr) {
    for (int i = 0; i < counter; ++i) {
      M *= array[i];
    }
  }
  return M;
}

TEST(GeneralMultiplicationTest, UsualInput_1_to_16) {
  int** array = new int*[4];
  for (int i = 0; i < 4; ++i) {
    array[i] = new int[4];
  }
  int A = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      ++A;
      array[i][j] = A;
    }
  }
  int counter = findcounter(array, 3, 3);
  int* NewArray = BuildNewMatrix(array, 3, 3, counter);
  int M = CountMultiplication(NewArray, counter);
  EXPECT_EQ(M, 96);
  for (int i = 0; i < 4; ++i) {
    delete[] array[i];
  }
  delete[] array;
  delete[] NewArray;
}
// краевыми являются случаи, когда нужных элементов нет и когда элементы на
// главной диагонали отрицательные
TEST(EdgeMultiplicationTest, No_elements_found) {
  int** array = new int*[4];
  for (int i = 0; i < 4; ++i) {
    array[i] = new int[4];
  }
  int A = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (i = j) {
        array[i][j] = 1;
      } else {
        ++A;
        array[i][j] = A;
      }
    }
  }
  int counter = findcounter(array, 3, 3);
  int* NewArray = BuildNewMatrix(array, 3, 3, counter);
  int M = CountMultiplication(NewArray, counter);
  EXPECT_EQ(M, 1);
  for (int i = 0; i < 4; ++i) {
    delete[] array[i];
  }
  delete[] array;
  delete[] NewArray;
}

TEST(EdgeMultiplicationTest, All_less_then_zero) {
  int** array = new int*[4];
  for (int i = 0; i < 4; ++i) {
    array[i] = new int[4];
  }
  int A = 0;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      --A;
      array[i][j] = A;
    }
  }
  int counter = findcounter(array, 3, 3);
  int* NewArray = BuildNewMatrix(array, 3, 3, counter);
  int M = CountMultiplication(NewArray, counter);
  EXPECT_EQ(M, 96);
  for (int i = 0; i < 4; ++i) {
    delete[] array[i];
  }
  delete[] array;
  delete[] NewArray;
}