#include <iostream>
#include "Solution.h"

int main() {
    Solution s;
    vector<vector<int>> vv = {{3,2,4},{1,5,0}};
    cout << s.slidingPuzzle(vv) << endl;
    return 0;
}