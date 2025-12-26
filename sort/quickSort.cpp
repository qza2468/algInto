//
// Created by qza2468 on 2025/12/25.
//

#include "../weHead.h"

void quickSort(vector<int> &arr) {
    std::stack<pair<int, int>> s;
    s.emplace(0, arr.size());
    while (!s.empty()) {
        int left = s.top().first, right = s.top().second;
        s.pop();
        if (right - left <= 1) {
            continue;
        }
        int j = left;

        for (auto i = left; i < right - 1; i++) {
            if (arr[i] <= arr[right - 1]) {
                swap(arr[i], arr[j]);
                j += 1;
            }
        }
        swap(arr[j], arr[right - 1]);

        s.emplace(left, j);
        s.emplace(j + 1, right);
    }
}