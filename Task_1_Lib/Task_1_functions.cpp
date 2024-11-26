#include <iostream>

int correctInputk() {
  std::cout << "������� ����� k --- ����������� ������� << '\n'";
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "������������ ����. ������� ����� k" << std::endl;
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
  std::cout << "������� " << type << " �������� ��� : " << '\n';
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < k; ++j) {
      std::cout << '[' << array[i][j] << "] ";
    }
    std::cout << '\n';
  }
  std::cout << "����� �� ���������� ������� � ����� " << sum << '\n';
}

void intro() {
  std::cout << "������� 1. �������� ���������� ����� ���������. ������� 7"
            << '\n';
  std::cout
      << "��� ��������� ������� ����� ���������, ������������� �� ������� � \n"
         "�������� ����������, ��� ������ ������� � � D ������������ k*k.\n "
         "�������� ��������� cij ������������ ��� (i * i + j * j) / (i + j + "
         "1),\n �������� ��������� dij ������������ ���������� i * i + j * j, "
         "\n"
         "���� j <= 8 ��� (i * i + j * j) / 2, ���� j > 8"
      << '\n';
  std::cout << "*������� k = 0 ����� �����* \n";
}