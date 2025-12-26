//
// Created by qza2468 on 2025/12/24.
//

#ifndef ALGINTO_MATRIX_H
#define ALGINTO_MATRIX_H
#include "../../weHead.h"


class MyMat {
public:
    MyMat(int row, int col);

    vector<int> data;
    int r, c;

    friend std::ostream& operator<<(std::ostream& os, const MyMat& p);

    MyMat operator*(const MyMat& p) const;
    bool operator==(const MyMat& p) const;

};

MyMat multiThreads(const MyMat x, const MyMat &y, int thread_num = 4);


#endif //ALGINTO_MATRIX_H