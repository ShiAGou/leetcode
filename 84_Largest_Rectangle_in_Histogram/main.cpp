#include <iostream>
#include "Solution.h"

int main() {
    Solution solution;
    vector<int> histogram = {2,1,5,6,2,3};
    cout << solution.largestRectangleArea(histogram) << endl;
    return 0;
}