//
// Created by zhengxiaojian on 2021/1/11.
//

#ifndef CPP_8_H
#define CPP_8_H

#include <string>

using namespace std;

bool operator<=(string &a, string &b) {
    if (a.size() != b.size()) return a.size() < b.size();

    int i = 0;
    while (i < a.size()) {
        if (a[i] != b[i]) {
            return a[i] < b[i];
        }
        ++i;
    }
    return true;
}

class Solution {
public:
    int myAtoi(string s) {
        int first_idx = get_first_idx(s);
        if (first_idx == s.size()) return 0;
        bool negative = s[first_idx] == '-';
        if (s[first_idx] == '-' || s[first_idx] == '+') ++first_idx;

        string num;
        bool zero_leader = true;
        for (int i = first_idx; i < s.size(); ++i) {
            if (!isdigit(s[i])) break;
            if (zero_leader && s[i] == '0') {
                continue;
            }
            zero_leader = false;
            num.push_back(s[i]);
        }

        if (num.empty()) return 0;

        string int_max = "2147483647", int_min = "2147483648";
        if (negative && int_min <= num) return INT_MIN;
        if (!negative && int_max <= num) return INT_MAX;

        int sum = 0;
        for (auto c : num) {
            sum = sum * 10 + (c - '0');
        }

        return negative ? -sum : sum;
    }

    int get_first_idx(string &s) {
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != ' ') return i;
        }
        return s.size();
    }
};

#endif //CPP_8_H
