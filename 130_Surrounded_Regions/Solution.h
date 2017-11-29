//
// Created by wesley shi on 2017/11/30.
//

#ifndef INC_130_SURROUNDED_REGIONS_SOLUTION_H
#define INC_130_SURROUNDED_REGIONS_SOLUTION_H

#include <vector>

using namespace std;

struct ordinate{
    unsigned long x;
    unsigned long y;
    ordinate(unsigned long a, unsigned long b){
        y = a;
        x = b;
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board);
};


#endif //INC_130_SURROUNDED_REGIONS_SOLUTION_H
