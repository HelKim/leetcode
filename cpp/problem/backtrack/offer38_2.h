//
// Created by zhengxiaojian on 2020/12/14.
//

#ifndef CPP_OFFER38_2_H
#define CPP_OFFER38_2_H
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> result;
    string tmp;
    vector<bool> visit;

    vector<string> permutation(string s) {
        visit.assign(s.size(), false);
        sort(s.begin(), s.end());
        backtrack(s);
        return result;
    }

    void backtrack(string &s) {
        if (tmp.size() == s.size()) {
            result.push_back(tmp);
            return;
        }

        for (int i = 0; i < s.size(); ++i) {
            if (visit[i]) continue;
            if (i > 0 && !visit[i - 1] && s[i] == s[i - 1]) continue;
            visit[i] = true;
            tmp += s[i];
            backtrack(s);
            tmp.pop_back();
            visit[i] = false;
        }
    }
};
#endif //CPP_OFFER38_2_H
