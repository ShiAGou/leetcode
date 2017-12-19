#include <iostream>

#include "Solution.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Solution *s = new Solution;
    cout << s->minCut("aab");
    return 0;
}