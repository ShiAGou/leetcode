#include <iostream>

#include "Solution.h"

int main() {
    Solution *s = new Solution;
    vector<int> v = {0,0};
    cout << s->checkSubarraySum(v, 0) << endl;
    return 0;
}