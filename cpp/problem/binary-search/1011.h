//
// Created by zhengxiaojian on 2021/1/28.
//

#ifndef CPP_1011_H
#define CPP_1011_H

#include <vector>

using namespace std;

class Solution {
public:
    int shipWithinDays(vector<int> &weights, int D) {
        int left = 0, right = 0;
        for (auto weight : weights) {
            left = max(left, weight);
            right += weight;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinish(weights, D, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool canFinish(vector<int> &weights, int D, int t) {
        int x = t;
        for (auto weight : weights) {
            if (weight > x) {
                --D;
                x = t;
            }
            x -= weight;
        }

        return D > 0;
    }
};

#endif //CPP_1011_H
