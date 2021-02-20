//
// Created by zhengxiaojian on 2021/2/4.
//

#ifndef CPP_480_H
#define CPP_480_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k) {
        vector<int> vec(k);
        int n = nums.size();

        vector<double> res(n - k + 1);

        for (int i = 0; i < k; ++i) {
            vec[i] = nums[i];
        }

        sort(vec.begin(), vec.end());
        int idx = 0;
        res[idx++] = getMid(vec);

        int right = k;
        while (right < n) {
            remove(vec, nums[right - k]);
            insert(vec, nums[right++]);
            res[idx++] = getMid(vec);
        }

        return res;
    }

    double getMid(vector<int> &vec) {
        int n = vec.size();
        if ((n & 1) == 1) return vec[n / 2];
        return ((double) vec[n / 2] + (double) vec[(n - 1) / 2]) / 2.0;
    }

    void remove(vector<int> &vec, int n) {
        int size = vec.size();
        int idx = 0;
        while (idx < size && vec[idx] != n) ++idx;
        while (idx < size - 1) {
            vec[idx] = vec[idx + 1];
            ++idx;
        }
    }

    void insert(vector<int> &vec, int n) {
        int size = vec.size();
        int idx = size - 2;
        while (idx >= 0 && vec[idx] > n) {
            vec[idx + 1] = vec[idx];
            --idx;
        }
        vec[idx + 1] = n;
    }
};

#endif //CPP_480_H
