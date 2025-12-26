//
// Created by qza2468 on 2025/12/22.
//

#ifndef ALGINTO_WEHEAD_H
#define ALGINTO_WEHEAD_H

#include <iostream>
#include <random>
#include <vector>
#include <benchmark/benchmark.h>
#include <eigen3/Eigen/Dense>
#include <memory>
#include <thread>
#include <stack>
#include <list>

#include "utils/utils.h"

using namespace std;

void insertSort(vector<int> &arr);
void mergeSort(vector<int> &arr);
void bubbleSort(vector<int> &arr);
void heapSort(vector<int> &arr);
void quickSort(vector<int> &arr);
#endif //ALGINTO_WEHEAD_H