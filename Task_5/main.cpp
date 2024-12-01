#include <iostream>

void intro() {
  std::cout
      << "Задание 5. Выполнил Колесников Антон Сергеевич.\n Эта программа "
         "создает матрицу из нечетных чисел, находящихся в четных столбцах \n"
         "исходного массива, и вычисляет их среднее арифметическое.\n Введите "
         "N или K = 0 чтобы выйти"
      << '\n';
}

int correctInputN() {
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
    if (x < 0) {
      std::cout << "Некорректный ввод" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

int correctInputx(int N, int K) {
  std::cout << "Введите " << K + 1 << "-й элемент " << N + 1 << "-й строки"
            << '\n';
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

int main() {
  setlocale(LC_ALL, "Russian");
  intro();
  while (true) {
    std::cout << "Введите размер N матрицы " << '\n';
    int N = correctInputN();
    if (N == 0) {
      break;
    }

    std::cout << "Введите размер K матрицы " << '\n';
    int K = correctInputN();
    if (K == 0) {
      break;
    }

    int** array = new int*[N];
    for (int i = 0; i < N; ++i) {
      array[i] = new int[K];
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < K; ++j) {
        array[i][j] = correctInputx(i, j);
      }
    }

    int counter = findcounter(array, N, K);
    if (counter == 0) {
      std::cout << "Искомых элементов нет \n";
      continue;
    }
    int* NewArray = OddEvenNums(array, N, K, counter);

    double mean = countMean(NewArray, counter);

    std::cout << "Среднее арифметическое искомых элементов равно " << mean
              << '\n';
    for (int i = 0; i < N; ++i) {
      delete[] array[i];
    }
    delete[] array;
    delete[] NewArray;
  }
  return 0;
}