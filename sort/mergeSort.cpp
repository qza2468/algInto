//
// Created by qza2468 on 2025/12/22.
//

#include "../weHead.h"

void mergeSortHelper(vector<int> &arr, int low, int high, vector<int> &left, vector<int> &right) {
    if (high - low < 2) return;
    int mid = (low + high) / 2;
    mergeSortHelper(arr, low, mid, left, right);
    mergeSortHelper(arr, mid, high, left, right);

    left.resize(0); right.resize(0);
    for (int i = low; i < mid; i++) {
        left.push_back(arr[i]);
    }
    for (int i = mid; i < high; i++) {
        right.push_back(arr[i]);
    }

    int lefti = 0, righti = 0;
    for (int i = low; i < high; i++) {
        if (lefti == left.size()) {
            arr[i] = right[righti++];
            continue;
        }
        if (righti == right.size()) {
            arr[i] = left[lefti++];
            continue;
        }

        if (left[lefti] > right[righti]) {
            arr[i] = right[righti++];
        } else {
            arr[i] = left[lefti++];
        }
    }
}

void mergeSort(vector<int> &arr) {
    vector <int> left, right;
    left.reserve(arr.size() / 2 + 1);
    right.reserve(arr.size() / 2 + 1);

    mergeSortHelper(arr, 0, arr.size(), left, right);
}
