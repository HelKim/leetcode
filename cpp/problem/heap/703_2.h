//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_703_2_H
#define CPP_703_2_H

#include <vector>
#include <queue>

using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<>> q;

    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (int i = 0; i < k && i < nums.size(); ++i) {
            q.push(nums[i]);
        }
        for (int i = k; i < nums.size(); ++i) {
            if (nums[i] > q.top()) {
                q.pop();
                q.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if (k == q.size() && q.top() < val) {
            q.pop();
            q.push(val);
        } else if (k > q.size()) {
            q.push(val);
        }
        return q.top();
    }
};

#endif //CPP_703_2_H
