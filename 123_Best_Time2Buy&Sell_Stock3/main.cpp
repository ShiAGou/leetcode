#include <iostream>
#include "Solution.h"

int main() {
    Solution solution;
    vector<int> v ={1,2,3,4,5,2,1,4};
    cout << solution.maxProfit(v) << endl;
    return 0;
}