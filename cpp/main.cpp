#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include "problem/trie/212_2.h"

using namespace std;

int main() {
    Solution s;

    vector<vector<char>> a{{'o', 'a', 'a', 'n'},
                           {'e', 't', 'a', 'e'},
                           {'i', 'h', 'k', 'r'},
                           {'i', 'f', 'l', 'v'}};
    vector<string> strs{"oath", "pea", "eat", "rain"};

    auto r = s.findWords(a, strs);

    for_each(r.begin(), r.end(), [](string &a) {
        cout << a << ", ";
    });
    cout << endl;
    return 0;
}

