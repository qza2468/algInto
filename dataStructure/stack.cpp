//
// Created by qza2468 on 2025/12/26.
//

#include "stack.h"

MyStack &MyStack::push(const int a) {
    stack.push_back(a);
    return *this;
}

MyStack &MyStack::pop() {
    if (!stack.empty()) {
        stack.pop_back();
    }

    return *this;
}

int MyStack::peek() const {
    if (!stack.empty()) {
        return stack.back();
    }

    return 0;
}

bool MyStack::isEmpty() const {
    return stack.empty();
}

int MyStack::size() const {
    return stack.size();
}

MyQueue &MyQueue::enqueue(int a) {
    queue.push_back(a);

    return *this;
}

MyQueue &MyQueue::dequeue(int &res) {
    if (!queue.empty()) {
        res = queue.back();
        queue.pop_back();
    }

    return *this;
}

int MyQueue::size() const {
    return queue.size();
}
