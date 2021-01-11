//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_344_H
#define CPP_344_H

class Solution {
public:
    void reverseString(vector<char> &s) {
        reverse(s.begin(), s.end());
    }
};

class Solution2 {
public:
    void reverseString(vector<char> &s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            swap(s[i++], s[j--]);
        }
    }
};

#endif //CPP_344_H
