//
// Created by zhengxiaojian on 2020/12/30.
//

#ifndef CPP_88_H
#define CPP_88_H

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> v(m + n);
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                v[i + j] = nums1[i];
                ++i;
            } else {
                v[i + j] = nums2[j];
                ++j;
            }
        }
        while (i < m) {
            v[i + j] = nums1[i];
            ++i;
        }
        while (j < n) {
            v[i + j] = nums2[j];
            ++j;
        }

        for (i = 0; i < n + m; ++i) {
            nums1[i] = v[i];
        }
    }
};

#endif //CPP_88_H
