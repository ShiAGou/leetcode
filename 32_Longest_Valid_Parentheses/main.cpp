#include <iostream>

#include "Solution.h"

int main() {
    Solution *s = new Solution;
    cout << s->longestValidParentheses("(()") << endl;
    return 0;
}