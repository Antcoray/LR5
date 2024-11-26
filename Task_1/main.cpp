#include <iostream>

#include "..\Task_1_Lib\Task_1_header.h"

int main() {
  setlocale(LC_ALL, "Russian");
  intro();
  while (true) {
    int k = correctInputk();
    if (k == 0) {
      break;
    }
    double **C = create2dArray(k);
    double **D = create2dArray(k);
    fillArrayC(C, k);
    fillArrayD(D, k);
    double SumC = countDiagSum(C, k);
    double SumD = countDiagSum(D, k);
    OutputInput(C, k, 'C', SumC);
    OutputInput(D, k, 'D', SumD);
    delete2dArray(C, k);
    delete2dArray(D, k);
  }
  return 0;
}