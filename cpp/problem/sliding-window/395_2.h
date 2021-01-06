//
// Created by zhengxiaojian on 2021/1/6.
//

#ifndef CPP_395_2_H
#define CPP_395_2_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return longest(s, k);
    }

    int longest(string_view s, int k) {
        vector<int> cnt(26, 0);
        for (auto c : s) {
            cnt[c - 'a']++;
        }
        int sum = 0;
        int need_remove = -1;
        for (int i = 0; i < cnt.size(); ++i) {
            if (cnt[i] < k && cnt[i] != 0) need_remove = i;
            else sum += cnt[i];
        }
        if (sum == 0 || need_remove == -1) return sum;

        int idx;
        for (idx = 0; idx < s.size(); ++idx) {
            if (s[idx] - 'a' == need_remove) break;
        }

        if (idx == 0) return longest(s.substr(1), k);
        if (idx == s.size() - 1) return longest(s.substr(0, s.size() - 1), k);

        return max(longest(s.substr(0, idx), k), longest(s.substr(idx + 1), k));
    }
};

#endif //CPP_395_2_H
