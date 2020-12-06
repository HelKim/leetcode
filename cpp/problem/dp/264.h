//
// Created by zhengxiaojian on 2020/12/4.
//

#ifndef CPP_264_H
#define CPP_264_H

#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        auto cmp = [](unsigned long long a, unsigned long long b) {
            return a > b;
        };
        priority_queue<unsigned long long, vector<unsigned long long>, decltype(cmp)> que(cmp);
        unordered_set<unsigned int> has;

        que.push(1);
        has.insert(1);
        unsigned long long res = 0;

        while (n-- > 0) {
            res = que.top();
            que.pop();
            if (has.find(2 * res) == has.end()) {
                que.push(2 * res);
                has.insert(2 * res);
            }
            if (has.find(3 * res) == has.end()) {
                que.push(3 * res);
                has.insert(3 * res);
            }
            if (has.find(5 * res) == has.end()) {
                que.push(5 * res);
                has.insert(5 * res);
            }
        }

        return res;
    }
};

#endif //CPP_264_H
