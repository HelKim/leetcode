//
// Created by zhengxiaojian on 2020/12/14.
//

#ifndef CPP_46_H
#define CPP_46_H

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<bool> visit;
    vector<int> tmp;

    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return result;
        visit.assign(n, false);
        backtrack(nums);
        return result;
    }

    void backtrack(vector<int> &nums) {
        if (tmp.size() == nums.size()) {
            result.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (visit[i]) continue;
            visit[i] = true;
            tmp.push_back(nums[i]);
            backtrack(nums);
            tmp.pop_back();
            visit[i] = false;
        }
    }
};

#endif //CPP_46_H
