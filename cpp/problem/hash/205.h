//
// Created by zhengxiaojian on 2021/1/9.
//

#ifndef CPP_205_H
#define CPP_205_H

#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> map;
        unordered_set<char> set;

        for (int i = 0; i < s.size(); ++i) {
            if (map.count(s[i])) {
                if (map[s[i]] != t[i]) return false;
                else continue;
            }
            if (set.count(t[i])) return false;
            map[s[i]] = t[i];
            set.insert(t[i]);
        }

        return true;
    }
};

#endif //CPP_205_H
