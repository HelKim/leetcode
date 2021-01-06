//
// Created by zhengxiaojian on 2021/1/6.
//

#ifndef CPP_424_H
#define CPP_424_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> map(26, 0);
        int left = 0, right = 0;
        int history_char_max = 0;

        for (right = 0; right < s.size(); ++right) {
            int idx = s[right] - 'A';
            map[idx]++;
            history_char_max = max(history_char_max, map[idx]);
            if (right - left + 1 > history_char_max + k) {
                map[s[left] - 'A']--;
                ++left;
            }
        }

        return s.size() - left;
    }
};

#endif //CPP_424_H
