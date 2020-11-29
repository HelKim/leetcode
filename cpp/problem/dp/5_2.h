//
// Created by zhengxiaojian on 2020/11/29.
//

#ifndef CPP_5_2_H
#define CPP_5_2_H

#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); ++i) {
            auto[left1, right1] = expandAroundCenter(s, i, i);
            auto[left2, right2] = expandAroundCenter(s, i, i + 1);

            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }

        return s.substr(start, end - start + 1);
    }

    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
};

#endif //CPP_5_2_H
