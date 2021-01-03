//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_1714_2_H
#define CPP_1714_2_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> smallestK(vector<int> &arr, int k) {
        quick_select(0, arr.size() - 1, arr, k);
        return vector(arr.begin(), arr.begin() + k);
    }

    void quick_select(int s, int e, vector<int> &arr, int k) {
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
        if (i + 1 == k) return;
        else if (i + 1 < k) quick_select(i + 1, e, arr, k);
        else quick_select(s, i - 1, arr, k);
    }
};

#endif //CPP_1714_2_H
