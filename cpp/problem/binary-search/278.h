//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_278_H
#define CPP_278_H

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (!isBadVersion(mid)) left = mid + 1;
            else {
                if (mid > 1 && !isBadVersion(mid - 1)) return mid;
                right = mid - 1;
            }
        }

        return 1;
    }
};

#endif //CPP_278_H
