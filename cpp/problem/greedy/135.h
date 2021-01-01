//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_135_H
#define CPP_135_H

#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int> &ratings) {
        vector<int> left(ratings.size(), 1);
        for (int i = 1; i < ratings.size(); ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        int sum = 0;
        int right = 1;
        for (int i = ratings.size() - 1; i >= 0; --i) {
            if (i + 1 < ratings.size() && ratings[i] > ratings[i + 1]) {
                right++;
            } else right = 1;
            sum += max(left[i], right);
        }

        return sum;
    }
};

#endif //CPP_135_H
