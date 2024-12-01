#include <iostream>

void intro() {
  std::cout << "������� 3. �������� ���������� ����� ���������" << '\n';
  std::cout
      << "��� ��������� �������� �� �������� ������� ������� n*k, \n"
         "�������, ��������� �� ������ ���������, ����������� �� �������\n "
         "��������� �������� �������.� ����� ��������� ������������\n "
         "��������� ���������� ������� \n";
  std::cout << "*������� n ��� k = 0 ����� �����*" << '\n';
}

int correctInputN() {
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "������������ ����. ������� ������� �������" << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
    if (x < 0) {
      std::cout << "������������ ����. ������� ������� �������" << std::endl;
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

int correctInputx(int indexM, int indexN) {
  std::cout << "������� " << indexN + 1 << "-� ������� " << indexM + 1
            << "-� ������" << '\n';
  int x = 0;
  bool incorrectInput = false;
  do {
    incorrectInput = false;
    std::cin >> x;
    if (std::cin.fail() || std::cin.peek() != '\n' || std::cin.peek() == '.') {
      std::cin.clear();
      std::cout << "������������ ����. ������� ����� ����� " << std::endl;
      std::cin.ignore(1000000, '\n');
      incorrectInput = true;
    }
  } while (incorrectInput);
  return x;
}

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

void OutputInput(int* array, int counter) {
  std::cout << "����� ������� �������� ���: " << '\n';
  for (int i = 0; i < counter; ++i) {
    std::cout << '[' << array[i] << "] ";
  }
}

int CountMultiplication(int* array, int counter) {
  int M = 1;
  for (int i = 0; i < counter; ++i) {
    M *= array[i];
  }
  return M;
}
int main() {
  setlocale(LC_ALL, "Russian");
  intro();
  while (true) {
    std::cout << "������� ����� n --- ������� �������" << '\n';
    int N = correctInputN();
    if (N == 0) {
      break;
    }

    // std::cout << "������� ����� k --- ������� �������" << '\n';
    int K = N;
    if (K == 0) {
      break;
    }

    int** array = new int*[N];
    for (int i = 0; i < N; ++i) {
      array[i] = new int[K];
    }
    for (int i = 0; i <= N - 1; ++i) {
      for (int j = 0; j <= K - 1; ++j) {
        array[i][j] = correctInputx(i, j);
        //
      }
    }
    int counter = findcounter(array, N - 1, K - 1);
    int* NewArray = BuildNewMatrix(array, N - 1, K - 1, counter);
    if (NewArray == nullptr) {
      std::cout << "������ ��������� ���\n";
      for (int i = 0; i < N; ++i) {
        delete[] array[i];
      }
      delete[] array;
      break;
    }

    OutputInput(NewArray, counter);

    std::cout << "������������ ��������� ������� ����� "
              << CountMultiplication(NewArray, counter) << '\n';

    for (int i = 0; i < N; ++i) {
      delete[] array[i];
    }
    delete[] array;
    delete[] NewArray;
  }
  return 0;
}