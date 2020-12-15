//
// Created by zhengxiaojian on 2020/12/13.
//

#ifndef CPP_66_H
#define CPP_66_H

#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        list<int> res;
        if (plusOne(0, digits, res) == 1) res.push_front(1);
        return vector(res.begin(), res.end());
    }

    int plusOne(int pos, vector<int> &digits, list<int> &l) {
        if (pos == digits.size()) return 1;

        int s = plusOne(pos + 1, digits, l) + digits[pos];
        if (s >= 10) {
            s -= 10;
            l.push_front(s);
            return 1;
        }
        l.push_front(s);
        return 0;
    }
};

#endif //CPP_66_H
