//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_773_H
#define CPP_773_H

#include <vector>
#include <string>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>> &board) {
        int n = 2;
        int m = 3;

        vector<vector<int>> neighbor = {
                {1, 3},
                {0, 4, 2},
                {1, 5},
                {0, 4},
                {3, 1, 5},
                {4, 2}
        };

        string target = "123450";
        string start;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                start.push_back(board[i][j] + '0');
            }
        }

        unordered_set<string> visit;
        queue<string> q;
        q.push(start);
        visit.insert(start);

        bool find = false;

        int level = 0;
        while (!q.empty() && !find) {
            int sz = q.size();
            while (sz-- > 0) {
                auto p = q.front();
                q.pop();
                if (p == target) {
                    find = true;
                    break;
                }

                int idx = -1;
                while (p[++idx] != '0');

                for (auto &dir : neighbor[idx]) {
                    swap(p[idx], p[dir]);
                    if (!visit.count(p)) {
                        q.push(p);
                        visit.insert(p);
                    }
                    swap(p[idx], p[dir]);
                }
            }
            ++level;
        }

        return find ? level - 1 : -1;
    }
};

#endif //CPP_773_H
