//
// Created by zhengxiaojian on 2020/12/14.
//

#ifndef CPP_39_H
#define CPP_39_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> tmp;

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        backtrack(0, 0, candidates, target);
        return result;
    }

    void backtrack(int start, int sum, vector<int> &candidates, int target) {
        if (sum == target) {
            result.push_back(tmp);
            return;
        }

        if (sum > target) return;

        for (int i = start; i < candidates.size(); ++i) {
            tmp.push_back(candidates[i]);
            backtrack(i, sum + candidates[i], candidates, target);
            tmp.pop_back();
        }
    }
};

#endif //CPP_39_H
