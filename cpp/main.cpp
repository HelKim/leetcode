
#include <iostream>
#include "problem/backtrack/10.h"

using namespace std;

int main() {

    Solution s;
    cout << s.isMatch("bccbbabcaccacbcacaa", ".*b.*c*.*.*.c*a*.c");
    return 0;
}
