//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_241_H
#define CPP_241_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        if (input.empty()) return res;

        for (int i = 0; i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                auto l = diffWaysToCompute(input.substr(0, i));
                auto r = diffWaysToCompute(input.substr(i + 1));

                for (auto a : l) {
                    for (auto b : r) {
                        switch (input[i]) {
                            case '+':
                                res.push_back(a + b);
                                break;
                            case '-':
                                res.push_back(a - b);
                                break;
                            case '*':
                                res.push_back(a * b);
                                break;
                        }
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input));
        return res;
    }
};

#endif //CPP_241_H
