//
// Created by zhengxiaojian on 2020/12/8.
//

#ifndef CPP_72_3_H
#define CPP_72_3_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> memo;

    int minDistance(string word1, string word2) {
        memo.assign(word1.size(), vector(word2.size(), -1));
        return backtrack(0, 0, word1, word2);
    }

    int backtrack(int i, int j, string &word1, string &word2) {
        if (i == word1.size() || j == word2.size()) {
            return word1.size() - i + word2.size() - j;
        }

        if (memo[i][j] != -1) return memo[i][j];

        int s;
        if (word1[i] == word2[j])
            s = backtrack(i + 1, j + 1, word1, word2);
        else {
            s = min(backtrack(i, j + 1, word1, word2),
                    min(backtrack(i + 1, j, word1, word2),
                        backtrack(i + 1, j + 1, word1, word2))) + 1;
        }
        memo[i][j] = s;
        return s;
    }
};

#endif //CPP_72_3_H
