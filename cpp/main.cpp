
#include <iostream>
#include "problem/dfs/332.h"

using namespace std;

int main() {
    Solution s;
//    vector<string> v{"hot", "dot", "dog", "lot", "log", "cog"};
//    s.findLadders("hit", "cog", v);
    vector<int> v{1, 0, -1, 0, -2, 2};
//    s.fourSum(v, 0);
    vector<vector<string>> vec;
    s.findItinerary(vec);
}

