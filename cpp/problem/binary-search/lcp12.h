//
// Created by zhengxiaojian on 2021/2/1.
//

#ifndef CPP_LCP12_H
#define CPP_LCP12_H

#include <vector>

using namespace std;

class Solution {
public:
    int minTime(vector<int> &time, int m) {
        int n = time.size();
        if (m >= n) return 0;

        int left = 0, right = 0;
        for (auto t : time) {
            right += t;
        }

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinish(time, m, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool canFinish(vector<int> &time, int m, int mid) {
        int r = mid;
        int maxn = 0;
        --m;
        for (int i = 0; i < time.size(); ++i) {
            int t = time[i];
            r -= t;
            if (t > maxn) {
                r = r - maxn + t;
                maxn = t;
            }
            if (r < 0) {
                --m;
                --i;
                r = mid;
                maxn = 0;
            }
            if (m < 0) return false;
        }
        return m >= 0;
    }
};

#endif //CPP_LCP12_H
