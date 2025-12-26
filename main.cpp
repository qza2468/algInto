
#include "weHead.h"

#include "dataStructure/matrix/matrix.h"

// 排序算法测试
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
            case 3:
                heapSort(arr); break;
            case 4:
                quickSort(arr); break;
            default: break;
        }

        state.PauseTiming();
        assert(is_sorted(arr.begin(), arr.end())); // 判断数组是否正确排序
        state.ResumeTiming();
    }
}

// 稠密矩阵计算测试(普通，eigen,多线程)
static void BM_MatMultiply(benchmark::State& state) {
    int r = 3, c = 3;
    auto x = MyMat(r, c), y = MyMat(c, r);
    auto x_Eigen = Eigen::MatrixXi(r, c), y_Eigen = Eigen::MatrixXi(r, c);

    for (auto _ : state) {
        state.PauseTiming();
        if (state.range(0) != r) {
            r = state.range(0);
            c = r;
            x = MyMat(r, c);
            y = MyMat(r, c);
            for (int i = 0; i < r * c; i++) {
                x.data[i] = i + 1;
                y.data[i] = i + 1;
            }
            x_Eigen = Eigen::MatrixXi(r, c); y_Eigen = Eigen::MatrixXi(r, c);
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    x_Eigen(i, j) = i * r + j + 1;
                    y_Eigen(i, j) = i * r + j + 1;
                }
            }
            if (r < 200 && state.range(1) == 2) {
                assert(x * y == multiThreads(x, y, 16));
            }
        }
        state.ResumeTiming();

        switch (state.range(1)) {
            case 0:
                x * y; break;
            case 1:
                x * y; break;
            case 2:
                multiThreads(x, y, 4); break;
            case 3:
                multiThreads(x, y, 8); break;
            case 4:
                multiThreads(x, y, 16); break;
            default: assert(false);
        }
    }

}

#define BENCHMARK_MATRIX
#ifdef BENCHMARK_SORT
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
    {true}
})->Iterations(20)->Name("归并排序")->ArgNames({"数量", "", "原数组无序"});

BENCHMARK(BM_Sort)->ArgsProduct( {
    {100, 1000, 10000},
        {2},
    {true}
})->Iterations(20)->Name("冒泡排序")->ArgNames({"数量", "", "原数组无序"});

BENCHMARK(BM_Sort)->ArgsProduct( {
    {10, 100, 1000, 10000},
        {3},
    {true}
})->Iterations(20)->Name("堆排序")->ArgNames({"数量", "", "原数组无序"});

BENCHMARK(BM_Sort)->ArgsProduct( {
    {10, 100, 1000, 10000},
        {4},
    {true}
})->Iterations(20)->Name("快速排序")->ArgNames({"数量", "", "原数组无序"});
#endif

#ifdef BENCHMARK_MATRIX
BENCHMARK(BM_MatMultiply)->ArgsProduct( {
    {10, 100, 500, 1000},
        {0}
})->Iterations(5)->Name("自己写的O(n**3)矩阵乘法")->ArgNames({"数量", ""});
BENCHMARK(BM_MatMultiply)->ArgsProduct( {
    {10, 100, 500, 1000},
        {1}
})->Iterations(5)->Name("Eigen矩阵乘法")->ArgNames({"数量", ""});
BENCHMARK(BM_MatMultiply)->ArgsProduct( {
    {10, 100, 500, 1000},
        {2}
})->Iterations(5)->Name("4线程矩阵乘法")->ArgNames({"数量", ""});
BENCHMARK(BM_MatMultiply)->ArgsProduct( {
    {10, 100, 500, 1000},
        {3}
})->Iterations(5)->Name("8线程矩阵乘法")->ArgNames({"数量", ""});

BENCHMARK(BM_MatMultiply)->ArgsProduct( {
    {10, 100, 500, 1000},
        {2}
})->Iterations(5)->Name("16线程矩阵乘法")->ArgNames({"数量", ""});
#endif

BENCHMARK_MAIN();
