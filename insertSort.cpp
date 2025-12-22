//
// Created by qza2468 on 2025/12/22.
//
#include "weHead.h"

void insertSort(vector<int> &arr) {
    if (arr.size() < 2) return ;
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i]; // 记录当前元素值
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] > key) {
                arr[j + 1] = arr[j]; // 大于key, 往后移
                if (j == 0) {
                    arr[j] = key;
                }
            } else {
                arr[j + 1] = key;
                break;
            }
        }
    }
}

