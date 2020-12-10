//
// Created by zhengxiaojian on 2020/12/8.
//

#ifndef CPP_72_2_H
#define CPP_72_2_H

#include <string>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        return backtrack(0, 0, word1, word2);
    }

    int backtrack(int i, int j, string &word1, string &word2) {
        if (i == word1.size() || j == word2.size()) {
            return word1.size() - i + word2.size() - j;
        }

        if (word1[i] == word2[j])
            return backtrack(i + 1, j + 1, word1, word2);
        return min(backtrack(i, j + 1, word1, word2),
                   min(backtrack(i + 1, j, word1, word2),
                       backtrack(i + 1, j + 1, word1, word2))) + 1;
    }
};

#endif //CPP_72_2_H
