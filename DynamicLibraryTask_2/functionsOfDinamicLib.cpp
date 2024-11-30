#include <cmath>
#include <iostream>
extern "C" __declspec(dllexport) int correctInputN() {
  std::cout << "Введите N --- количество элементов массива\n";
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "Некорректный ввод" << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

extern "C" __declspec(dllexport) double correctInputx() {
  std::cout << "Введите элемент массива" << std::endl;
  double x = 0;

  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите элемент массива " << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}
extern "C" __declspec(dllexport) double* create1DArray(int N) {
  double* array = new double[N];
  return array;
}

extern "C" __declspec(dllexport) void delete1DArray(double* array, int N) {
  delete[] array;
}

extern "C" __declspec(dllexport) void fill1DArray(double* array, int N) {
  for (int i = 0; i < N; ++i) {
    array[i] = correctInputx();
  }
}

extern "C" __declspec(dllexport) bool checkForCondition(double* array, int N) {
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