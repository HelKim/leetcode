//
// Created by zhengxiaojian on 2020/12/17.
//

#ifndef CPP_126_3_H
#define CPP_126_3_H

#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    const int INF = 1 << 20;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        unordered_map<string, int> wordId;
        vector<string> idWord;
        vector<vector<int>> edges;

        int id = 0;
        for (const auto &word : wordList) {
            if (!wordId.count(word)) {
                wordId[word] = id++;
                idWord.push_back(word);
            }
        }

        if (!wordId.count(endWord)) {
            return {};
        }

        if (!wordId.count(beginWord)) {
            wordId[beginWord] = id++;
            idWord.push_back(beginWord);
        }

        edges.resize(idWord.size());
        for (int i = 0; i < idWord.size(); ++i) {
            for (int j = i + 1; j < idWord.size(); ++j) {
                if (transformCheck(idWord[i], idWord[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        const int dest = wordId[endWord];
        vector<vector<string >> res;

        queue<vector<int>> q;
        vector<int> cost(id, INF);
        q.push(vector<int>{wordId[beginWord]});
        cost[wordId[beginWord]] = 0;

        while (!q.empty()) {
            vector<int> now = q.front();
            q.pop();

            int last = now.back();
            if (last == dest) {
                vector<string> tmp;
                for (int idx : now) {
                    tmp.push_back(idWord[idx]);
                }
                res.push_back(tmp);
            } else {
                for (int i = 0; i < edges[last].size(); ++i) {
                    int to = edges[last][i];
                    if (cost[last] + 1 <= cost[to]) {
                        cost[to] = cost[last] + 1;
                        vector<int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }

        return res;
    }

    bool transformCheck(const string &str1, const string &str2) {
        int diff = 0;
        for (int i = 0; i < str1.size(); ++i) {
            if (str1[i] != str2[i]) {
                ++diff;
                if (diff > 1) return false;
            }
        }
        return true;
    }
};

#endif //CPP_126_3_H
