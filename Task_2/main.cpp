#include <Windows.h>

#include <iostream>

int main() {
  setlocale(LC_ALL, "Russian");
  typedef int (*inputN)();
  inputN inpN = (inputN)GetProcAddress(LoadLibrary(L"DynamicLibraryTask_2.dll"),
                                       "correctInputN");

  typedef double* (*cr1DA)(int N);
  cr1DA create1DArray = (cr1DA)GetProcAddress(
      LoadLibrary(L"DynamicLibraryTask_2.dll"), "create1DArray");

  typedef void (*del1DA)(double* array, int N);
  del1DA delete1DArray = (del1DA)GetProcAddress(
      LoadLibrary(L"DynamicLibraryTask_2.dll"), "delete1DArray");

  typedef void (*fill1DA)(double* array, int N);
  fill1DA fill1DArray = (fill1DA)GetProcAddress(
      LoadLibrary(L"DynamicLibraryTask_2.dll"), "fill1DArray");

  typedef bool (*check)(double* array, int N);
  check checkForCondition = (check)GetProcAddress(
      LoadLibrary(L"DynamicLibraryTask_2.dll"), "checkForCondition");

  std::cout
      << "������� 2. �������� ���������� ����� ���������. ������� 7.\n ��� "
         "��������� ���������� ��������� ���������� ������ �������� N �� \n"
         "������������ ������� ((Aij)^2 + 2)^1/3 < 10.\n ������� N = 0, "
         "����� �����\n";

  while (true) {
    int N = inpN();
    if (N == 0) {
      break;
    }
    double* array = create1DArray(N);
    fill1DArray(array, N);
    bool condition = checkForCondition(array, N);

    if (condition) {
      std::cout << "������ ������� ���������� \n";
    } else {
      std::cout << "������ ������� �� ���������� \n";
    }
  }
  return 0;
}