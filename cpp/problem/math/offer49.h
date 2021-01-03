//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_OFFER49_H
#define CPP_OFFER49_H

#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<>> q;
        unordered_set<int> set;
        set.insert(1);
        q.push(1);
        --n;
        while (n-- > 0) {
            auto p = q.top();
            q.pop();
            if (!set.count(p * 2)) {
                set.insert(p * 2);
                q.push(p * 2);
            }
            if (!set.count(p * 3)) {
                set.insert(p * 3);
                q.push(p * 3);
            }
            if (!set.count(p * 5)) {
                set.insert(p * 5);
                q.push(p * 5);
            }
        }
        return q.top();
    }
};

#endif //CPP_OFFER49_H
