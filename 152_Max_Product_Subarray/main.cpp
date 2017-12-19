#include <iostream>
#include "Solution.h"

int main() {
    Solution solution;
    vector<int> nums = {2, -2, -3, 4, -5};
    int max = solution.maxProduct(nums);
    cout << max << endl;
    return 0;
}