//
// Created by zhengxiaojian on 2020/11/26.
//

#ifndef CPP_17_H
#define CPP_17_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> result;
    vector<vector<char>> table = {{},
                                  {},
                                  {'a', 'b', 'c'},
                                  {'d', 'e', 'f'},
                                  {'g', 'h', 'i'},
                                  {'j', 'k', 'l'},
                                  {'m', 'n', 'o'},
                                  {'p', 'q', 'r', 's'},
                                  {'t', 'u', 'v'},
                                  {'w', 'x', 'y', 'z'}};

    vector<string> letterCombinations(string digits) {
        string str;
        backtrack(0, digits, str);
        return result;
    }

    void backtrack(int start, string &digits, string &str) {
        if (start == digits.length()) {
            if (str.length() > 0) result.push_back(str);
            return;
        }
        int idx = stoi(digits.substr(start, 1));
        for (char i : table[idx]) {
            str += i;
            backtrack(start + 1, digits, str);
            str.erase(str.size() - 1);
        }
    }
};

#endif //CPP_17_H
