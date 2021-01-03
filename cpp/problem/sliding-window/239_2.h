//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_239_2_H
#define CPP_239_2_H

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        unordered_map<int, int> window;
        priority_queue<int, vector<int>, less<>> q;

        int left = 0, right = 0;

        while (right < nums.size()) {
            q.push(nums[right]);
            window[nums[right]]++;

            if (right - left == k) {
                while (!q.empty()) {
                    int top = q.top();
                    if (window.count(top)) break;
                    q.pop();
                }
                res.push_back(q.top());
                window[nums[left]]--;
                ++left;
            }
        }

        return res;
    }
};

#endif //CPP_239_2_H
