//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_452_H
#define CPP_452_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>> &points) {
        sort(points.begin(), points.end(), [](vector<int> &v1, vector<int> &v2) {
            return v1[0] == v2[0] ? v1[1] < v2[1] : v1[0] < v2[0];
        });

        int s = 0;
        int pre = 0;
        for (int i = 0; i < points.size(); ++i) {
            if (i > 0 && points[i][0] <= points[pre][1]) {
                if (points[i][1] < points[pre][1]) pre = i;
                continue;
            }
            ++s;
            pre = i;
        }

        return s;
    }
};

#endif //CPP_452_H
