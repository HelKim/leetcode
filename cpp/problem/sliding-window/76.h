//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_76_H
#define CPP_76_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        for (auto c : t) need[c]++;

        int left = 0, right = 0;
        int valid = 0;

        int start = 0, len = INT_MAX;

        while (right < s.size()) {
            char c = s[right];
            ++right;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }

            while (valid == need.size()) {
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }

                char d = s[left];

                ++left;

                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};

#endif //CPP_76_H
