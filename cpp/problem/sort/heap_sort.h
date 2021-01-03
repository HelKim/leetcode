//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_HEAP_SORT_H
#define CPP_HEAP_SORT_H

#include <vector>

using namespace std;

class Heap {
public:

    vector<int> arr;

    Heap(vector<int> &a) {
        this->arr = a;
        make_heap();
    }

    void make_heap() {
        int n = arr.size() - 1;

        for (int i = (n - 1) / 2; i >= 0; --i) {
            sift_down(i, n);
        }
    }

    void sift_down(int s, int e) {
        if (s >= e) return;

        int val = arr[s];

        while (2 * s + 1 <= e) {
            int max_pos = 2 * s + 1;
            if (max_pos < e && arr[max_pos] < arr[max_pos + 1]) max_pos++;
            if (val >= arr[max_pos]) break;
            arr[s] = arr[max_pos];
            s = max_pos;
        }
        arr[s] = val;
    }

    void sift_up(int s) {
        int val = arr[s];

        while (s > 0) {
            int pos = (s - 1) / 2;
            if (arr[pos] >= val) break;
            arr[s] = arr[pos];
            s = pos;
        }

        arr[s] = val;
    }

    void push_back(int val) {
        arr.push_back(val);
        sift_up(arr.size() - 1);
    }

    int size() {
        return arr.size();
    }

    int pop_front() {
        int top = arr[0];
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();
        sift_down(0, arr.size() - 1);
        return top;
    }

    void sort() {
        for (int i = arr.size() - 1; i > 0; --i) {
            swap(arr[i], arr[0]);
            sift_down(0, i - 1);
        }
    }
};

class Solution {
public:
    void heap_sort(vector<int> &arr) {
        Heap h(arr);
        h.sort();
    }
};

#endif //CPP_HEAP_SORT_H
