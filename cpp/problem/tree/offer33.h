//
// Created by zhengxiaojian on 2021/1/3.
//

#ifndef CPP_OFFER33_H
#define CPP_OFFER33_H

#include <vector>

using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int> &postorder) {
        return verifyPostorder(0, postorder.size() - 1, postorder);
    }

    bool verifyPostorder(int s, int e, vector<int> &postorder) {
        if (s >= e) return true;

        int pos = e - 1;
        while (pos >= s && postorder[pos] > postorder[e]) --pos;

        int i = pos;
        while (i >= s) {
            if (postorder[i] > postorder[e]) return false;
            --i;
        }

        return verifyPostorder(s, pos, postorder)
               && verifyPostorder(pos + 1, e - 1, postorder);
    }
};

#endif //CPP_OFFER33_H
