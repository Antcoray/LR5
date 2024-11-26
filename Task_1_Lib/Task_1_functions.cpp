#include <iostream>

int correctInputk() {
  std::cout << "Введите число k --- размерность матрицы << '\n'";
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "Некорректный ввод. Введите число k" << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

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

void OutputInput(double** array, int k, char type, double sum) {
  std::cout << "Матрица " << type << " выглядит так : " << '\n';
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      std::cout << '[' << array[i][j] << "] ";
    }
    std::cout << '\n';
  }
  std::cout << "Сумма на диагоналях матрицы С равна " << sum << '\n';
}

void intro() {
  std::cout << "Задание 1. Выполнил Колесников Антон Сергеевич. Вариант 7"
            << '\n';
  std::cout
      << "Эта программа считает сумму элементов, расположенных на главной и \n"
         "побочной диагоналях, для каждой матрицы С и D размерностью k*k.\n "
         "Значения элементов cij определяются как (i * i + j * j) / (i + j + "
         "1),\n значения элементов dij определяются выражением i * i + j * j, "
         "\n"
         "если j <= 8 или (i * i + j * j) / 2, если j > 8"
      << '\n';
  std::cout << "*Введите k = 0 чтобы выйти* \n";
}