//
// Created by zhengxiaojian on 2020/12/11.
//

#ifndef CPP_354_H
#define CPP_354_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = envelopes.size();
        if (n == 0) return 0;

        sort(envelopes.begin(), envelopes.end(),
             [](vector<int> &v1, vector<int> &v2) {
                 return v1[0] == v2[0]
                        ? v1[1] < v2[1]
                        : v1[0] < v2[0];
             });

        vector<int> dp(n, 1);

        int ans = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(dp[i], ans);
        }

        return ans;
    }
};

#endif //CPP_354_H
