//
// Created by zhengxiaojian on 2020/12/16.
//

#ifndef CPP_126_2_H
#define CPP_126_2_H

#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        vector<vector<string >> res;
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return res;
        bfs(beginWord, endWord, wordList, res);
        return res;
    }

    void bfs(string &beginWord, string &endWord, vector<string> &wordList, vector<vector<string>> &res) {
        queue<vector<string *> *> queue;
        queue.push(new vector({&beginWord}));
        bool isFound = false;
        unordered_set<string *> visit;
        visit.insert(&beginWord);

        while (!queue.empty() && !isFound) {
            int size = queue.size();
            unordered_set<string *> subVisit;

            for (int i = 0; i < size; ++i) {
                auto *p = queue.front();
                queue.pop();

                auto *ew = (*p)[p->size() - 1];

                for (auto &word : wordList) {
                    if (isValid(*ew, word) && visit.find(&word) == visit.end()) {
                        if (word == endWord) {
                            isFound = true;
                            p->insert(&word);
                            add_res(res, p);
                            p->pop_back();
                        }

                        p->insert(&word);
                        queue.push(new vector(p->begin(), p->end()));
                        p->pop_back();
                        subVisit.insert(&word);
                    }
                }
            }

            visit.insert(subVisit.begin(), subVisit.end());
        }
    }

    void add_res(vector<vector<string>> &res, vector<string *> *p) {
        vector<string> r;
        for (auto *s : *p) {
            r.push_back(*s);
        }
        res.push_back(r);
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

#endif //CPP_126_2_H
