#include <iostream>

void intro() {
  std::cout
      << "Задание 4. Выполнил Колесников Антон Сергеевич. Эта программа \n"
         "создает двумерный динамический массив вещественных чисел.\n "
         "Определяет, встречаются ли среди них элементы с нулевым \n"
         "значением.Если встречаются такие элементы, то определяет их \n"
         "индексы и общее количество. Переставляет элементы этого \n"
         "массива в обратном порядке и выводит на экран.\n Введите размер "
         "матрицы N или K = 0, чтобы выйти\n";
}

int correctInputN() {
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "Некорректный ввод." << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
    if (x < 0) {
      std::cout << "Некорректный ввод." << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

double correctInputx(int N, int K) {
  std::cout << "Введите " << N << "-й элемент " << K << "-й строки" << '\n';
  double x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cin.clear();
      std::cout << "Некорректный ввод." << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

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

void OutputInput(double** array, int N, int K) {
  std::cout << "Новая матрица выглядит так: " << '\n';
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      std::cout << '[' << array[i][j] << "] ";
    }
    std::cout << '\n';
  }
}

int countZeros(double** array, int N, int K) {
  int count = 0;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < K; ++j) {
      if (array[i][j] == 0) {
        ++count;
        std::cout << "array[" << i << "][" << j << "] = 0\n";
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

int main() {
  setlocale(LC_ALL, "Russian");
  intro();
  while (true) {
    std::cout << "Введите размер N матрицы" << '\n';
    int N = correctInputN();
    if (N == 0) {
      break;
    }

    std::cout << "Введите размер K матрицы" << '\n';
    int K = correctInputN();
    if (K == 0) {
      break;
    }

    double** array = new double*[N];
    for (int i = 0; i < N; ++i) {
      array[i] = new double[K];
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < K; ++j) {
        array[i][j] = correctInputx(i, j);
      }
    }

    bool zerosIncluded = checkForZeros(array, N, K);
    if (zerosIncluded) {
      int NumberOfZeros = countZeros(array, N, K);
      std::cout << "Общее количество 0 равно " << NumberOfZeros << "\n";
    }

    double** NewArray = viceVersa(array, N, K);

    OutputInput(NewArray, N, K);

    for (int i = 0; i < N; ++i) {
      delete[] NewArray[i];
    }
    delete[] NewArray;

    for (int i = 0; i < N; ++i) {
      delete[] array[i];
    }
    delete[] array;
  }
  return 0;
}