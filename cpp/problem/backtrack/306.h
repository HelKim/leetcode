//
// Created by zhengxiaojian on 2020/12/15.
//

#ifndef CPP_306_H
#define CPP_306_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector <string> nums;

    bool isAdditiveNumber(string num) {
        return backtrack(0, num);
    }

    bool backtrack(int s, string &num) {
        if (s == num.size()) return nums.size() > 2;

        string n;
        for (int i = s; i < num.size(); ++i) {
            if (i > s && num[s] == '0') return false;
            n += num[i];
            int v = isValid(n);
            if (v == 0) {
                nums.push_back(n);
                if (backtrack(i + 1, num)) return true;
                nums.pop_back();
            } else if (v == 1) return false;
        }
        return false;
    }

    int isValid(string &num) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        string p = big_add(nums[n - 1], nums[n - 2]);
        return num == p ? 0 : greater(num, p) ? 1 : -1;
    }

    bool greater(string &a, string &b) {
        if (a.size() != b.size()) return a.size() > b.size();
        int n = a.size();
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) return a[i] > b[i];
        }
        return true;
    }

    string big_add(string &a, string &b) {
        int bit = 0;
        int n = a.size() - 1;
        int m = b.size() - 1;
        vector<char> res;

        while (n >= 0 || m >= 0 || bit > 0) {
            int t = (n >= 0 ? a[n] - '0' : 0) + (m >= 0 ? b[m] - '0' : 0) + bit;
            bit = t / 10;
            res.push_back((char) (t % 10 + '0'));
            --n;
            --m;
        }

        return string(res.rbegin(), res.rend());
    }
};

#endif //CPP_306_H
