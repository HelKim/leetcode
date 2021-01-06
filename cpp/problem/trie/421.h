//
// Created by zhengxiaojian on 2021/1/5.
//

#ifndef CPP_421_H
#define CPP_421_H

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int maxNum = nums[0];
        for (auto num : nums) maxNum = max(maxNum, num);
        int L = to_binary_string(maxNum).size();

        int maxXor = 0, currXor;
        unordered_set<int> prefixes;

        for (int i = L - 1; i > -1; --i) {
            maxXor <<= 1;
            currXor = maxXor | 1;
            prefixes.clear();

            for (auto num : nums) prefixes.insert(num >> i);

            for (auto p : prefixes) {
                if (prefixes.count(currXor ^ p)) {
                    maxXor = currXor;
                    break;
                }
            }
        }

        return maxXor;
    }

    string to_binary_string(int num) {
        auto n = (unsigned) num;

        string ans;
        bool first = true;
        for (int i = 31; i >= 0; --i) {
            int bit = (n & (1 << i)) == 0 ? 0 : 1;
            if (bit == 0 && first) continue;
            first = false;
            ans += to_string(bit);
        }

        return ans;
    }
};

#endif //CPP_421_H
