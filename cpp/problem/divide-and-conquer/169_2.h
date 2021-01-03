//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_169_2_H
#define CPP_169_2_H

#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        return divide(0, nums.size() - 1, nums);
    }

    int divide(int s, int e, vector<int> &nums) {
        if (s == e) return nums[s];

        int mid = s + (e - s) / 2;

        int l = divide(s, mid, nums);
        int r = divide(mid + 1, e, nums);

        if (l == r) return l;

        int lcnt = count(s, e, l, nums);
        int rcnt = count(s, e, r, nums);

        return lcnt > rcnt ? l : r;
    }

    int count(int s, int e, int val, vector<int> &nums) {
        int cnt = 0;
        while (s <= e) {
            if (nums[s++] == val) ++cnt;
        }
        return cnt;
    }
};

#endif //CPP_169_2_H
