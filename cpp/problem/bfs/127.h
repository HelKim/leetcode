//
// Created by zhengxiaojian on 2020/12/22.
//

#ifndef CPP_127_H
#define CPP_127_H

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        unordered_map<string, int> wordId;
        int id = 0;
        for (auto &w : wordList) {
            wordId[w] = id++;
        }
        if (!wordId.count(endWord)) return 0;

        if (!wordId.count(beginWord)) {
            wordId[beginWord] = id++;
            wordList.push_back(beginWord);
        }

        vector<vector<int>> edges(wordList.size());

        for (int i = 0; i < wordList.size(); ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                if (isValid(wordList[i], wordList[j])) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }

        queue<int> q;
        q.push(wordId[beginWord]);
        vector<bool> visit(wordList.size(), false);

        int count = 0;
        bool find = false;

        while (!q.empty() && !find) {
            ++count;
            int size = q.size();

            for (int i = 0; i < size; ++i) {
                auto p = q.front();
                visit[p] = true;
                if (p == wordId[endWord]) {
                    find = true;
                    break;
                }

                q.pop();

                for (auto e : edges[p]) {
                    if (visit[e]) continue;
                    q.push(e);
                }
            }
        }

        return find ? count : 0;
    }

    bool isValid(string &a, string &b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) {
                ++diff;
                if (diff > 1) return false;
            }
        }
        return true;
    }
};

#endif //CPP_127_H
