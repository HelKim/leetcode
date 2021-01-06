//
// Created by zhengxiaojian on 2021/1/6.
//

#ifndef CPP_978_H
#define CPP_978_H

#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int> &arr) {
        if (arr.size() < 2) return arr.size();

        int left = 0, right = 1;
        int len = 0;

        while (right < arr.size()) {
            if (right - left > 1 &&
                (arr[right] > arr[right - 1] && arr[right - 1] < arr[right - 2]
                 || arr[right] < arr[right - 1] && arr[right - 1] > arr[right - 2])) {
                ++right;
            } else {
                left = right - (arr[right] == arr[right - 1] ? 0 : 1);
                right += 1;
            }
            len = max(len, right - left);
        }

        return len;
    }
};

#endif //CPP_978_H
