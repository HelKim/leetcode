//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_OFFER59_H
#define CPP_OFFER59_H

#include <queue>

using namespace std;

class MaxQueue {
public:
    queue<int> q;
    deque<int> d;

    MaxQueue() {

    }

    int max_value() {
        return d.empty() ? -1 : d.front();
    }

    void push_back(int value) {
        while (!d.empty() && d.back() < value) {
            d.pop_back();
        }
        d.push_back(value);
        q.push(value);
    }

    int pop_front() {
        if (q.empty()) return -1;
        int v = q.front();
        q.pop();
        if (v == d.front()) d.pop_front();
        return v;
    }
};

#endif //CPP_OFFER59_H
