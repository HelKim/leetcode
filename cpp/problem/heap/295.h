//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_295_H
#define CPP_295_H

#include <queue>

using namespace std;

class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<>> min_heap;
    priority_queue<int, vector<int>, less<>> max_heap;

    /** initialize your data structure here. */
    MedianFinder() {
    }

    void addNum(int num) {
        if (min_heap.empty()) {
            min_heap.push(num);
            return;
        }
        if (num > min_heap.top()) {
            min_heap.push(num);
            if (min_heap.size() > max_heap.size() + 1) {
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        } else {
            max_heap.push(num);
            if (max_heap.size() > min_heap.size()) {
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
    }

    double findMedian() {
        return min_heap.size() == max_heap.size()
               ? (min_heap.top() + max_heap.top()) / 2.0
               : min_heap.top();
    }
};

#endif //CPP_295_H
