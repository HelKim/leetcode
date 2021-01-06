//
// Created by zhengxiaojian on 2021/1/5.
//

#ifndef CPP_421_2_H
#define CPP_421_2_H

#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

struct TrieNode {
    vector<TrieNode *> children = vector<TrieNode *>(2, nullptr);
};

class Solution {
public:
    int findMaximumXOR(vector<int> &nums) {
        int maxNum = nums[0];
        for (int num : nums) maxNum = max(maxNum, num);
        int L = to_binary_string(maxNum).size();

        vector<string> strNums(nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            strNums[i] = to_binary_string(nums[i], L);
        }

        auto *root = new TrieNode;
        int maxXor = 0;
        for (auto &num : strNums) {
            auto *cur = root, *xorNode = root;
            int currXor = 0;

            for (auto bit : num) {
                if (cur->children[bit - '0'] == nullptr)
                    cur->children[bit - '0'] = new TrieNode;
                cur = cur->children[bit - '0'];

                int toggledBit = bit == '1' ? 0 : 1;

                if (xorNode->children[toggledBit]) {
                    currXor = (currXor << 1) | 1;
                    xorNode = xorNode->children[toggledBit];
                } else {
                    currXor = currXor << 1;
                    xorNode = xorNode->children[bit - '0'];
                }
            }
            maxXor = max(maxXor, currXor);
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

    };

    string to_binary_string(int num, int count) {
        auto n = (unsigned) num;

        string ans;
        for (int i = count - 1; i >= 0; --i) {
            int bit = (n & (1 << i)) == 0 ? 0 : 1;
            ans += to_string(bit);
        }

        return ans;
    }
};

#endif //CPP_421_2_H
