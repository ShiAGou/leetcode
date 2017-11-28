//
//  main.cpp
//  65_Valid_Number
//
//  Created by wesley shi on 2017/11/28.
//  Copyright © 2017年 self. All rights reserved.
//

#include <iostream>
#include "Solution.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *s = new Solution();
    string str = string("  2e+10 ");
    cout << s->isNumber(str) << endl;
    return 0;
}
