//
// Created by zhengxiaojian on 2021/1/2.
//

#ifndef CPP_TEST_H
#define CPP_TEST_H

#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

bool is_sort(vector<int> &arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

vector<int> generate_random_arr(int n, int left = 0, int right = 10) {
    vector<int> arr(n);
    srand((int) time(nullptr));
    for (int i = 0; i < n; ++i) {
        arr[i] = (rand() % (right - left)) + left;
    }
    return arr;
}

#endif //CPP_TEST_H
