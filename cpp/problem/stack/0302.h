//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_0302_H
#define CPP_0302_H

#include <stack>

using namespace std;

class MinStack {
public:
    stack<int> s, ms;

    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        if (ms.empty() || ms.top() >= x)
            ms.push(x);
        s.push(x);
    }

    void pop() {
        if (s.empty()) return;

        if (s.top() == ms.top()) ms.pop();
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return ms.top();
    }
};

#endif //CPP_0302_H
