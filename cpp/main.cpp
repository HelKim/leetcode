
#include <iostream>
#include "problem/backtrack/126_3.h"

using namespace std;

int main() {
    Solution s;
    vector<string> v{"hot", "dot", "dog", "lot", "log", "cog"};
    s.findLadders("hit", "cog", v);
}

