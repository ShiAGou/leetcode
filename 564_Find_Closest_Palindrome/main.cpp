#include <iostream>
#include "Solution.h"

int main() {
    Solution* s = new Solution();
    string tmp = s->nearestPalindromic(string("88887"));
    cout << tmp << endl;
    return 0;
}