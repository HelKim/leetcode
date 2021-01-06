//
// Created by zhengxiaojian on 2021/1/6.
//

#ifndef CPP_1052_H
#define CPP_1052_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int X) {
        int sum = 0;

        for (int i = 0; i < grumpy.size(); ++i) {
            if (grumpy[i] == 1) continue;
            sum += customers[i];
            customers[i] = 0;
        }

        int max_num = 0;
        for (int i = 0; i < X && i < customers.size(); ++i) max_num += customers[i];
        int left = 0, right = X;
        int s = max_num;

        while (right < customers.size()) {
            s += customers[right++] - customers[left++];
            max_num = max(max_num, s);
        }

        return sum + max_num;
    }
};

#endif //CPP_1052_H
