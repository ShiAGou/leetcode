#include <iostream>
#include "Solution.h"

int main() {
    Solution *s = new Solution;
    vector<vector<int>> vv;
    vector<int> v3 = {3, -3, 1};
    vector<int> v2 = {0, -2, 0};
    vector<int> v1 = {-3, -3, -3};
    vv.emplace_back(v1);
    vv.emplace_back(v2);
    vv.emplace_back(v3);
    cout << s->calculateMinimumHP(vv) << endl;
    return 0;
}