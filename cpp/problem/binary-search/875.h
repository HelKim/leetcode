//
// Created by zhengxiaojian on 2021/1/27.
//

#ifndef CPP_875_H
#define CPP_875_H

#include <vector>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int H) {
        int left = 1, right = 1;

        for (auto p : piles) {
            right = max(right, p);
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, H, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return right + 1;
    }

    bool canFinish(vector<int> &piles, int H, int speed) {
        for (auto p : piles) {
            H -= (p - 1) / speed + 1;
        }
        return H >= 0;
    }
};

#endif //CPP_875_H
