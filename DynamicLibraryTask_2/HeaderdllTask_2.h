#pragma once
extern "C" __declspec(dllexport) int correctInputN();
extern "C" __declspec(dllexport) double correctInputx();
extern "C" __declspec(dllexport) double* create1DArray(int N);
extern "C" __declspec(dllexport) void delete1DArray(double* array, int N);
extern "C" __declspec(dllexport) void fill1DArray(double* array, int N);
extern "C" __declspec(dllexport) bool checkForCondition(double* array, int N);