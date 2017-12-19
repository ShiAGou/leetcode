//
// Created by wesley shi on 2017/12/10.
//

#include "Solution.h"

#include <bitset>
#include <vector>
using namespace std;

bool Solution::canIWin(int maxChoosableInteger, int desiredTotal){
    int size = 1 << (maxChoosableInteger-1);
    vector<bitset> dp(desiredTotal, bitset<size>());

}

