#include <iostream>
#include "Solution.h"

int main() {
    Solution solution;
    vector<vector<char>> matrix={
            {'1','0'},
            {'1', '0'},
    };
    cout << solution.maximalRectangle(matrix) << endl;
    return 0;
}