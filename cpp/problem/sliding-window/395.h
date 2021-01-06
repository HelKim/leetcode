//
// Created by zhengxiaojian on 2021/1/6.
//

#ifndef CPP_395_H
#define CPP_395_H

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> map;
        for (auto c : s) map[c]++;
        return longest(s, 0, s.size() - 1, k, map);
    }

    int longest(string &s, int start, int end, int k, unordered_map<char, int> &map) {
        if (start > end) return 0;

        char need_remove = '$';
        int sum = 0;
        for (auto &iter : map) {
            if (iter.second < k) {
                need_remove = iter.first;
            } else sum += iter.second;
        }
        if (need_remove == '$' || sum == 0) return sum;

        unordered_map<char, int> m1 = map;
        int i;
        for (i = start; i <= end; ++i) {
            if (--m1[s[i]] == 0) {
                m1.erase(s[i]);
            }
            if (s[i] == need_remove) break;
        }
        int j;
        for (j = end; j >= start; --j) {
            if (--map[s[j]] == 0) {
                map.erase(s[j]);
            }
            if (s[j] == need_remove) break;
        }

        return max(longest(s, i + 1, end, k, m1),
                   longest(s, start, j - 1, k, map));
    }
};

#endif //CPP_395_H
