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

// 插入排序测试
static void BM_insertSort(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        vector<int> arr;
        for (int i = 0; i < state.range(0); i++) {
            arr.push_back(i);
        }
        if (state.range(1)) {
            ranges::shuffle(arr, std::mt19937(std::random_device()()));
        }
        state.ResumeTiming();

        insertSort(arr);

        state.PauseTiming();
        assert(is_sorted(arr.begin(), arr.end()));
        state.ResumeTiming();
    }
}
BENCHMARK(BM_insertSort)->ArgsProduct( {
    {100, 1000, 10000},
    {false, true}
})->Iterations(20);