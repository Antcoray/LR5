#include <iostream>

void intro() {
  std::cout
      << "������� 5. �������� ���������� ����� ���������.\n ��� ��������� "
         "������� ������� �� �������� �����, ����������� � ������ �������� \n"
         "��������� �������, � ��������� �� ������� ��������������.\n ������� "
         "N ��� K = 0 ����� �����"
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
      std::cout << "������������ ����" << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
    if (x < 0) {
      std::cout << "������������ ����" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

int correctInputx(int N, int K) {
  std::cout << "������� " << K + 1 << "-� ������� " << N + 1 << "-� ������"
            << '\n';
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "������������ ����" << std::endl;
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
    std::cout << "������� ������ N ������� " << '\n';
    int N = correctInputN();
    if (N == 0) {
      break;
    }

    std::cout << "������� ������ K ������� " << '\n';
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
      std::cout << "������� ��������� ��� \n";
      continue;
    }
    int* NewArray = OddEvenNums(array, N, K, counter);

    double mean = countMean(NewArray, counter);

    std::cout << "������� �������������� ������� ��������� ����� " << mean
              << '\n';
    for (int i = 0; i < N; ++i) {
      delete[] array[i];
    }
    delete[] array;
    delete[] NewArray;
  }
  return 0;
}