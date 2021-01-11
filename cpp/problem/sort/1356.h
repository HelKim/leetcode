//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_1356_H
#define CPP_1356_H

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int> &arr) {
        unordered_map<int, int> map;

        sort(arr.begin(), arr.end(), [&](int x, int y) {
            if (!map.count(x)) map[x] = cal(x);
            if (!map.count(y)) map[y] = cal(y);

            return map[x] == map[y] ? x < y : map[x] < map[y];
        });

        return arr;
    }

    int cal(int x) {
        int s = 0;
        while (x != 0) {
            s += (x & 1);
            x >>= 1;
        }
        return s;
    }
};

#endif //CPP_1356_H
