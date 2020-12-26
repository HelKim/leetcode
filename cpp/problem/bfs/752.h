//
// Created by zhengxiaojian on 2020/12/24.
//

#ifndef CPP_752_H
#define CPP_752_H

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int openLock(vector<string> &deadends, string target) {
        int step = 0;

        unordered_set<string> deads(deadends.begin(), deadends.end());

        if (deads.count("0000")) return -1;

        queue<string> q;
        q.push("0000");
        deads.insert(q.front());

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; ++i) {
                auto &p = q.front();
                if (p == target) return step;

                for (int j = 0; j < 4; ++j) {
                    char t = p[j];
                    p[j] = (t - '0' + 1) % 10 + '0';
                    if (!deads.count(p)) {
                        deads.insert(p);
                        q.push(p);
                    }

                    p[j] = t == '0' ? '9' : t - 1;
                    if (!deads.count(p)) {
                        deads.insert(p);
                        q.push(p);
                    }

                    p[j] = t;
                }

                q.pop();
            }

            ++step;
        }

        return -1;
    }
};

#endif //CPP_752_H
