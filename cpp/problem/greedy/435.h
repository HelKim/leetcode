//
// Created by zhengxiaojian on 2020/12/31.
//

#ifndef CPP_435_H
#define CPP_435_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &v1, vector<int> &v2) {
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
        });

        int need_remove = 0;
        int pre = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[pre][1]) {
                ++need_remove;
                if (intervals[pre][1] > intervals[i][1]) {
                    pre = i;
                }
            }
            else pre = i;
        }

        return need_remove;
    }
};

#endif //CPP_435_H
