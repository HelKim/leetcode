//
// Created by zhengxiaojian on 2020/12/28.
//

#ifndef CPP_743_H
#define CPP_743_H

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>> &times, int N, int K) {
        vector<vector<pair<int, int>>> edges(N + 1);

        for (auto &node : times) {
            edges[node[0]].emplace_back(node[1], node[2]);
        }

        const int INF = 0x3f3f3f3f;

        vector<bool> visit(N + 1, false);
        vector<int> dis(N + 1, INF);
        dis[K] = 0;

        int time;
        while ((K = getNext(visit, dis)) != -1) {
            --N;
            visit[K] = true;
            time = dis[K];

            for (auto next : edges[K]) {
                if (dis[K] + next.second < dis[next.first]) {
                    dis[next.first] = dis[K] + next.second;
                }
            }
        }

        return N == 0 ? time : -1;
    }

    int getNext(vector<bool> &visit, vector<int> &dis) {
        int m_val = 0x3f3f3f3f;
        int m_idx = -1;

        for (int i = 1; i < visit.size(); ++i) {
            if (visit[i]) continue;
            if (dis[i] < m_val) {
                m_idx = i;
                m_val = dis[i];
            }
        }

        return m_idx;
    }
};

#endif //CPP_743_H
