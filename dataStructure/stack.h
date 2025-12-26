//
// Created by qza2468 on 2025/12/26.
//

#ifndef ALGINTO_STACK_H
#define ALGINTO_STACK_H

#include "../weHead.h"

class MyStack {
public:
    MyStack() = default;
    MyStack &push(int a);
    MyStack &pop();
    int peek() const;
    bool isEmpty() const;
    int size() const;

private:
    vector<int> stack;
};

class MyQueue {
public:
    MyQueue() = default;
    MyQueue& enqueue(int a);
    MyQueue& dequeue(int &res);
    int size() const;
private:
    list<int> queue;
};
#endif //ALGINTO_STACK_H