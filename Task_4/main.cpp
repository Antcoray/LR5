#include <iostream>

void intro() {
  std::cout
      << "������� 4. �������� ���������� ����� ���������. ��� ��������� \n"
         "������� ��������� ������������ ������ ������������ �����.\n "
         "����������, ����������� �� ����� ��� �������� � ������� \n"
         "���������.���� ����������� ����� ��������, �� ���������� �� \n"
         "������� � ����� ����������. ������������ �������� ����� \n"
         "������� � �������� ������� � ������� �� �����.\n ������� ������ "
         "������� N ��� K = 0, ����� �����\n";
}

int correctInputN() {
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "������������ ����." << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
    if (x < 0) {
      std::cout << "������������ ����." << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

double correctInputx(int N, int K) {
  std::cout << "������� " << N << "-� ������� " << K << "-� ������" << '\n';
  double x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n') {
      std::cin.clear();
      std::cout << "������������ ����." << std::endl;
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
  std::cout << "����� ������� �������� ���: " << '\n';
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
    std::cout << "������� ������ N �������" << '\n';
    int N = correctInputN();
    if (N == 0) {
      break;
    }

    std::cout << "������� ������ K �������" << '\n';
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
      std::cout << "����� ���������� 0 ����� " << NumberOfZeros << "\n";
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