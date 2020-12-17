//
// Created by zhengxiaojian on 2020/12/15.
//

#ifndef CPP_126_H
#define CPP_126_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> tmp;
    vector<bool> visit;
    unordered_map<string, int> map;
    int mmin;

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList) {
        visit.assign(wordList.size(), false);
        tmp.push_back(beginWord);
        mmin = wordList.size() + 1;

        int idx = 0;
        while (idx < wordList.size()) {
            if (wordList[idx] == endWord) break;
            ++idx;
        }

        if (idx == wordList.size()) return result;

        swap(wordList[idx], wordList[0]);

        backtrack(0, beginWord, endWord, wordList);
        return result;
    }

    void backtrack(int s, string &beginWord, string &endWord, vector<string> &wordList) {
        if (beginWord == endWord) {
            if (tmp.size() == mmin) {
                result.push_back(tmp);
            } else if (tmp.size() < mmin) {
                mmin = tmp.size();
                result = {tmp};
            }
            return;
        }
        if (s == wordList.size() || tmp.size() >= mmin) return;

        if (map.find(beginWord) != map.end() && map[beginWord] < s) return;
        map[beginWord] = s;

        for (int i = 0; i < wordList.size(); ++i) {
            if (visit[i] || !isValid(beginWord, wordList[i])) continue;
            visit[i] = true;
            tmp.push_back(wordList[i]);
            backtrack(s + 1, wordList[i], endWord, wordList);
            tmp.pop_back();
            visit[i] = false;
        }
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

#endif //CPP_126_H
