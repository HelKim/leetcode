//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_3_H
#define CPP_3_H

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> window;
        int left = 0, right = 0;
        int cnt = 0;

        while (right < s.size()) {
            char c = s[right++];

            while (window.count(c)) {
                window.erase(s[left++]);
            }

            window.insert(c);

            cnt = max(cnt, right - left);
        }

        return cnt;
    }
};

#endif //CPP_3_H
