//
// Created by zhengxiaojian on 2020/12/14.
//

#ifndef CPP_OFFER38_3_H
#define CPP_OFFER38_3_H
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<string> result;

    vector<string> permutation(string s) {
        backtrack(0, s);
        return result;
    }

    void backtrack(int start, string &s) {
        if (start == s.size()) {
            result.push_back(s);
            return;
        }

        unordered_set<int> hashset;
        for (int i = start; i < s.size(); ++i) {
            if (hashset.find(s[i]) != hashset.end()) continue;
            hashset.insert(s[i]);
            swap(s[start], s[i]);
            backtrack(start + 1, s);
            swap(s[start], s[i]);
        }
    }
};
#endif //CPP_OFFER38_3_H
