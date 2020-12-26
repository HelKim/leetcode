//
// Created by zhengxiaojian on 2020/12/24.
//

#ifndef CPP_863_H
#define CPP_863_H

#include <vector>
#include "../../lib/TreeNode.h"
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int K) {
        if (root == nullptr) return {};

        unordered_map<TreeNode *, vector<TreeNode *>> edges;
        dfs(root, edges);

        queue<TreeNode *> q;
        unordered_set<TreeNode *> visit;
        q.push(target);
        visit.insert(target);

        vector<int> res;
        int level = 0;

        while (!q.empty()) {
            int sz = q.size();

            if (level == K) {
                for (int i = 0; i < sz; ++i) {
                    auto *p = q.front();
                    q.pop();
                    res.push_back(p->val);
                }
                return res;
            }
            for (int i = 0; i < sz; ++i) {
                auto *p = q.front();
                q.pop();

                for (auto *next : edges[p]) {
                    if (!visit.count(next)) {
                        visit.insert(next);
                        q.push(next);
                    }
                }
            }
            ++level;
        }

        return res;
    }

    void dfs(TreeNode *root, unordered_map<TreeNode *, vector<TreeNode *>> &edges) {
        if (root == nullptr) return;

        if (root->left != nullptr) {
            edges[root].push_back(root->left);
            edges[root->left].push_back(root);
            dfs(root->left, edges);
        }

        if (root->right != nullptr) {
            edges[root].push_back(root->right);
            edges[root->right].push_back(root);
            dfs(root->right, edges);
        }
    }
};

#endif //CPP_863_H
