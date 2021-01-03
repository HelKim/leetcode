//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_438_H
#define CPP_438_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need, window;
        vector<int> res;
        for (auto c : p) need[c]++;

        int left = 0, right = 0;
        int valid = 0;

        while (right < s.size()) {
            char c = s[right++];

            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) ++valid;
            }

            while (right - left >= p.size()) {
                if (valid == need.size()) {
                    res.push_back(left);
                }
                char d = s[left++];
                if (need.count(d)) {
                    if (window[d] == need[d]) --valid
                    window[d]--;;
                }
            }
        }

        return res;
    }
};

#endif //CPP_438_H
