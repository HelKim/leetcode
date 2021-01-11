//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_57_H
#define CPP_57_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval) {
        int n = intervals.size();
        if (n == 0) return {newInterval};

        vector<vector<int>> res;

        int i;
        for (i = 0; i < n && intervals[i][1] < newInterval[0]; ++i) {
            res.push_back(intervals[i]);
        }
        if (i == n) {
            res.push_back(newInterval);
            return res;
        }
        if (newInterval[1] < intervals[i][0]) {
            intervals.insert(intervals.begin() + i, newInterval);
            return intervals;
        }

        int s = min(intervals[i][0], newInterval[0]);
        int e = max(intervals[i][1], newInterval[1]);

        while(i < n && newInterval[1] >= intervals[i][0]) {
            e = max(e, intervals[i][1]);
            ++i;
        }

        res.push_back({s, e});
        while(i < n) res.push_back(intervals[i++]);

        return res;
    }
};

#endif //CPP_57_H
