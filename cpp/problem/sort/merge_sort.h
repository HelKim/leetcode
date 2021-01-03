//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_MERGE_SORT_H
#define CPP_MERGE_SORT_H

#include <vector>

using namespace std;

class Solution {
public:
    void merge_sort(vector<int> &arr) {
        vector<int> tmp(arr.size());
        merge_sort(0, arr.size() - 1, arr,tmp);
    }

    void merge_sort(int s, int e, vector<int> &arr, vector<int> &tmp) {
        if (s >= e) return;
        int mid = s + (e - s) / 2;

        merge_sort(s, mid, arr, tmp);
        merge_sort(mid + 1, e, arr, tmp);

        merge(s, mid, e, arr, tmp);
    }

    void merge(int s, int mid, int e, vector<int> &arr, vector<int> &tmp) {
        int i = 0;
        int l = s;
        int r = mid + 1;
        while (l <= mid && r <= e) {
            if (arr[l] <= arr[r]) {
                tmp[i++] = arr[l++];
            } else {
                tmp[i++] = arr[r++];
            }
        }

        while (l <= mid) {
            tmp[i++] = arr[l++];
        }
        while (r <= e) {
            tmp[i++] = arr[r++];
        }

        for (int x = 0; x < i; ++x) {
            arr[s + x] = tmp[x];
        }
    }
};

#endif //CPP_MERGE_SORT_H
