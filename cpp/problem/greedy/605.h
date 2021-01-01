//
// Created by zhengxiaojian on 2021/1/1.
//

#ifndef CPP_605_H
#define CPP_605_H

#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        if (n == 0) return true;
        if (flowerbed.size() == 1) return flowerbed[0] == 0 && n == 1;

        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] != 0) continue;
            if (i > 0 && i + 1 < flowerbed.size()
                && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                --n;
            } else if (i == 0 && i + 1 < flowerbed.size() && flowerbed[i + 1] == 0) {
                flowerbed[i] = 1;
                --n;
            } else if (i == flowerbed.size() - 1 && flowerbed[i - 1] == 0) {
                flowerbed[i] = 1;
                --n;
            }

            if (n == 0) return true;
        }
        return false;
    }
};

#endif //CPP_605_H
