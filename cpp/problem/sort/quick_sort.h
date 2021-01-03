//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_QUICK_SORT_H
#define CPP_QUICK_SORT_H

#include <vector>

using namespace std;

class Solution {
public:
    void quick_sort(vector<int> &arr) {
        quick_sort(0, arr.size() - 1, arr);
    }

    void quick_sort(int s, int e, vector<int> &arr) {
        if (s >= e) return;
        int pivot = arr[s];
        int i = s, j = e;

        while (i < j) {
            while (i < j && arr[j] >= pivot) --j;
            arr[i] = arr[j];
            while (i < j && arr[i] <= pivot) ++i;
            arr[j] = arr[i];
        }

        arr[i] = pivot;
        quick_sort(s, i - 1, arr);
        quick_sort(i + 1, e, arr);
    }
};

#endif //CPP_QUICK_SORT_H
