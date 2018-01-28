#include <iostream>
#include "solution.h"

int main() {
    Solution solution;
    vector<int> nums1 = {2,5,6,4,4,0};
    vector<int> nums2 = {7,3,8,0,6,5,7,6,2};
    int k = 15;
    vector<int> r = solution.maxNumber(nums1, nums2, k);
    for (int i=0; i<k; i++){
        cout << r[i] << endl;
    }
    return 0;
}