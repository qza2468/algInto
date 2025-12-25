//
// Created by qza2468 on 2025/12/25.
//

#include "../weHead.h"

// 整理i所指子树
void heapManage(vector<int> &arr, int i, size_t size) {
    int j = i;
    while (true) {
        int swapFlag = 0;
        int left = 2 * j + 1, right = 2 * j + 2;
        if (left < size && arr[left] > arr[j]) { // 判断左边
            swapFlag += 1;
        }
        if (right < size && arr[right] > arr[j]) { // 判断右边
            swapFlag += 2;
        }
        if (swapFlag == 1 || swapFlag == 2) { // 只有一边有节点
            swap(arr[j], arr[j * 2 + swapFlag]);

            j = j * 2 + swapFlag;
        } else if (swapFlag == 3) { // 两边都有节点，比较判断
            if (arr[left] > arr[right]) {
                swap(arr[j], arr[left]);
                j = left;
            } else {
                swap(arr[j], arr[right]);
                j = right;
            }
        }else {
            break; // 该节点已完成
        }
    }
}

void heapSort(vector<int> &arr) {
    // 建堆
    for (int i = arr.size() / 2; i >= 0; i--) {
        heapManage(arr, i, arr.size());
    }
    // printVector(arr);
    for (auto i = 0; i < arr.size(); i++) {
        swap(arr[arr.size() - 1 - i],arr[0]);
        heapManage(arr, 0, arr.size() - i - 1);
    }
}