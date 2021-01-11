//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_69_H
#define CPP_69_H

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;

        while (left <= right) {
            double mid = left + (right - left) / 2;
            double square = x / mid;
            if (square == mid || square > mid && x / (mid + 1) < mid + 1) {
                return mid;
            }
            if (square > mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};

#endif //CPP_69_H
