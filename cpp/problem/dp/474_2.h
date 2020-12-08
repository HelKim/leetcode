//
// Created by zhengxiaojian on 2020/12/7.
//

#ifndef CPP_474_2_H
#define CPP_474_2_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findMaxForm(vector<string> &strs, int m, int n) {
        int size = strs.size();

        vector<vector<int>> dp(m + 1, vector(n + 1, 0));


        for (int i = 0; i < size; ++i) {
            auto p = calc(strs[i]);
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    if (j - p.first >= 0 && k - p.second >= 0) {
                        dp[j][k] = max(dp[j][k], dp[j - p.first][k - p.second] + 1);
                    }
                }
            }
        }

        return dp[m][n];
    }

    pair<int, int> calc(const string &str) {
        int x = 0, y = 0;
        for (auto &s : str) {
            switch (s) {
                case '0':
                    ++x;
                    break;
                case '1':
                    ++y;
                    break;
            }
        }
        return {x, y};
    }
};

#endif //CPP_474_2_H
