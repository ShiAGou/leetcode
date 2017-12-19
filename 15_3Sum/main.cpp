#include <iostream>
#include "Solution.h"

void print(vector<vector<int>> &vv){
    for (auto i=vv.begin(); i<vv.end(); i++){
        vector<int> v = *i;
        for (auto j=v.begin(); j<v.end(); j++){
            cout << *j << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution *s = new Solution();
    vector<int> v;
    // -1, 0, 1, 2, -1, -4
    v.push_back(-1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(-1);
    v.push_back(-4);
    vector<vector<int>> vv = s->threeSum(v);
    print(vv);
    return 0;
}