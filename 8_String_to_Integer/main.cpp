#include <iostream>
#include "Solution.h"

int main() {
    Solution *s = new Solution();
    int result = s->myAtoi(string(" b11228552307"));
    cout << result;
    return 0;
}