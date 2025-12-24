//
// Created by qza2468 on 2025/12/22.
//

#include "../weHead.h"

void bubbleSort(vector<int> &arr) {
    for (int i = 0; i < arr.size(); i++) {
        int flag = false;
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }
}