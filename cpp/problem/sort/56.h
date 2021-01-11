//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_56_H
#define CPP_56_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
        });

        vector<vector<int>> res;
        int x = intervals[0][0], y = intervals[0][1];

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] > y) {
                res.push_back({x, y});
                x = intervals[i][0];
                y = intervals[i][1];
            } else {
                y = max(intervals[i][1], y);
            }
        }

        res.push_back({x, y});
        return res;
    }
};

#endif //CPP_56_H
