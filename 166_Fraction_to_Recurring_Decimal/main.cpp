#include <iostream>
#include "Solution.h"

int main() {
    Solution* s = new Solution();
    string str = s->fractionToDecimal(-1,-2147483648);
    cout << str << endl;
    return 0;
}