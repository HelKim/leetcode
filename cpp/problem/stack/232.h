//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_232_H
#define CPP_232_H

#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;

    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int s = peek();
        s2.pop();
        return s;
    }

    /** Get the front element. */
    int peek() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

#endif //CPP_232_H
