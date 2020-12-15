//
// Created by zhengxiaojian on 2020/12/13.
//

#ifndef CPP_OFFER38_H
#define CPP_OFFER38_H

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<string> result;
    string tmp;
    vector<bool> visit;

    vector<string> permutation(string s) {
        visit.assign(s.size(), false);
        backtrack(s);
        return vector(result.begin(), result.end());
    }

    void backtrack(string &s) {
        if (tmp.size() == s.size()) {
            result.insert(tmp);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (visit[i]) continue;
            visit[i] = true;
            tmp += s[i];
            backtrack(s);
            tmp.pop_back();
            visit[i] = false;
        }
    }
};

#endif //CPP_OFFER38_H
