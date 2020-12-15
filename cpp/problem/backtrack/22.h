//
// Created by zhengxiaojian on 2020/12/14.
//

#ifndef CPP_22_H
#define CPP_22_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int left = 0;
    int right = 0;
    vector<string> result;
    string s;

    vector<string> generateParenthesis(int n) {
        if (n == 0) return {};

        left = n;
        backtrack();
        return result;
    }

    void backtrack() {
        if (left == 0 && right == 0) {
            result.push_back(s);
            return;
        }

        if (left > 0) {
            --left;
            ++right;
            s.push_back('(');
            backtrack();
            s.pop_back();
            ++left;
            --right;
        }
        if (right > 0) {
            --right;
            s.push_back(')');
            backtrack();
            s.pop_back();
            ++right;
        }
    }
};

#endif //CPP_22_H
