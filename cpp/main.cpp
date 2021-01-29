#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "problem/binary-search/1631_2.h"

using namespace std;

int main() {
    Solution s;
//    vector<vector<int>> a{{1, 3}, {6, 9}};
//    vector<int> b{2, 5};
//    s.insert(a, b);
//    string str = "dcab";
//    vector<vector<int>> v{{0, 3},
//                          {1, 2}};
//    s.smallestStringWithSwaps(str, v);
//    s.intToRoman(356);
    vector<vector<int>> a{{1, 2, 2},
                          {3, 8, 2},
                          {5, 3, 5}};
    s.minimumEffortPath(a);

//    vector<vector<char>> a{{'o', 'a', 'a', 'n'},
//                           {'e', 't', 'a', 'e'},
//                           {'i', 'h', 'k', 'r'},
//                           {'i', 'f', 'l', 'v'}};
//    vector<string> strs{"oath", "pea", "eat", "rain"};
//
//    auto r = s.findWords(a, strs);
//
//    for_each(r.begin(), r.end(), [](string &a) {
//        cout << a << ", ";
//    });
//    cout << endl;

    return 0;
}

