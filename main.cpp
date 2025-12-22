
#include "weHead.h"

// 插入排序测试
static void BM_Sort(benchmark::State& state) {
    for (auto _ : state) {
        state.PauseTiming();
        vector<int> arr;
        for (int i = 0; i < state.range(0); i++) {
            arr.push_back(i);
        }
        if (state.range(2)) {
            ranges::shuffle(arr, std::mt19937(std::random_device()()));
        }
        state.ResumeTiming();

        switch (state.range(1)) {
            case 0:
                insertSort(arr); break;
            case 1:
                mergeSort(arr); break;
            case 2:
                bubbleSort(arr); break;
            default: break;
        }

        state.PauseTiming();
        assert(is_sorted(arr.begin(), arr.end()));
        state.ResumeTiming();
    }
}

// 参数一：运行次数
// 参数二：排序方法
// 参数三：原始序列是否有序
BENCHMARK(BM_Sort)->ArgsProduct( {
    {100, 1000, 10000},
        {0},
    {false, true}
})->Iterations(20)->Name("插入排序")->ArgNames({"数量", "", "原数组无序"});

BENCHMARK(BM_Sort)->ArgsProduct( {
    {100, 1000, 10000},
        {1},
    {false, true}
})->Iterations(20)->Name("归并排序")->ArgNames({"数量", "", "原数组无序"});

BENCHMARK(BM_Sort)->ArgsProduct( {
    {100, 1000, 10000},
        {2},
    {false, true}
})->Iterations(20)->Name("冒泡排序")->ArgNames({"数量", "", "原数组无序"});

BENCHMARK_MAIN();
