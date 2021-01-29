//
// Created by zhengxiaojian on 2021/1/26.
//

#ifndef CPP_1128_2_H
#define CPP_1128_2_H

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        unordered_map<string, int> map;

        for (auto &dom : dominoes) {
            if (dom[0] > dom[1]) swap(dom[0], dom[1]);
            map[to_string(dom[0]) + "_" + to_string(dom[1])]++;
        }

        int ans = 0;

        for (auto &iter : map) {
            ans += iter.second * (iter.second - 1) / 2;
        }

        return ans;
    }

};

#endif //CPP_1128_2_H
