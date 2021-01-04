//
// Created by zhengxiaojian on 2021/1/4.
//

#ifndef CPP_692_H
#define CPP_692_H

#include <vector>
#include <string>
#include <queue>
#include <list>

using namespace std;

struct TrieNode {
    int flag = 0;
    int idx = -1;
    vector<TrieNode *> children = vector<TrieNode *>(26, nullptr);
};

struct Node {
    int count;
    int weigh;
    int idx;
};

struct cmp {
    bool operator()(Node &p1, Node &p2) {
        return p1.count == p2.count ? p1.weigh < p2.weigh : p1.count > p2.count;
    }
};

class Solution {
public:
    TrieNode *root = new TrieNode();
    priority_queue <Node, vector<Node>, cmp> q;
    int k;


    vector <string> topKFrequent(vector <string> &words, int k) {
        this->k = k;
        build(words);
        dfs(root);

        list <string_view> list1;
        while (!q.empty()) {
            list1.push_front(words[q.top().idx]);
            q.pop();
        }

        return vector<string>(list1.begin(), list1.end());
    }

    int l = 0;
    void dfs(TrieNode *r) {
        if (r->flag > 0) {
            if (k > q.size()) {
                q.push({r->flag, l++, r->idx});
            } else if (r->flag > q.top().count) {
                q.pop();
                q.push({r->flag, l++, r->idx});
            }
        }
        for (auto *child : r->children) {
            if (child == nullptr) continue;
            dfs(child);
        }
    }

    void build(vector <string> &words) {
        for (int i = 0; i < words.size(); ++i) {
            auto &word = words[i];

            auto *cur = root;
            for (auto c : word) {
                if (cur->children[c - 'a'] == nullptr)
                    cur->children[c - 'a'] = new TrieNode();
                cur = cur->children[c - 'a'];
            }
            cur->flag++;
            cur->idx = i;
        }
    }
};

#endif //CPP_692_H
