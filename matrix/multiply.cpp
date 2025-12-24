//
// Created by qza2468 on 2025/12/24.
//

#include "../weHead.h"

#include "matrix.h"

MyMat::MyMat(int row, int col) {
    data.resize(row * col);
    r = row; c = col;
}

ostream& operator<<(ostream& os, const MyMat& p) {
    for (int i = 0; i < p.r; i++) {
        os << "[" << " ";
        for (int j = 0; j < p.c; j++) {
            os << p.data[i * p.c + j] << " ";
        }
        os << "]" << endl;
    }

    return os;
}

bool MyMat::operator==(const MyMat &p) const {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (data[i * p.c + j] != p.data[i * p.c + j]) {
                return false;
            }
        }
    }

    return true;
}

MyMat MyMat::operator*(const MyMat &y) const {
    auto res = MyMat(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int l = i * c + j;
            int temp1 = i * c, temp2 = j;
            res.data[l] = 0;
            for (int k = 0; k < c; k++) {
                res.data[l] += data[temp1++] * y.data[temp2];
                temp2 += c;
            }
        }
    }

    return res;
}

void threadDo(const MyMat &x, const MyMat &y, MyMat &res, int start, int end) {\
    for (int i = start; i < end; i++) {
        for (int j = 0; j < y.c; j++) {
            int l = i * x.c + j;
            int temp1 = i * x.c, temp2 = j;
            res.data[l] = 0;
            for (int k = 0; k < x.c; k++) {
                res.data[l] += x.data[temp1++] * y.data[temp2];
                temp2 += y.c;
            }
        }
    }
}


MyMat multiThreads(const MyMat x, const MyMat &y, int thread_num) {
    MyMat res(x.r, y.c);
    if (x.r < thread_num) {
        return x * y;
    }
    std::vector<std::thread> threads;

    int count = x.r / thread_num;

    int  start = 0;
    for (int i = 0; i < thread_num; i++) {
        int end = start + count;
        end = i < x.r % thread_num ? end + 1 : end;

        threads.emplace_back(threadDo, ref(x), ref(y), ref(res), start, end);
        start = end;
    }

    for (auto& t : threads) {
        t.join();
    }

    return res;
}


