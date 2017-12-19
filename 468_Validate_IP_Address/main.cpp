#include <iostream>

#include "Solution.h"

int main() {
    Solution* s = new Solution();
    cout << s->validIPAddress("1.0.1.") << endl;
    cout << s->validIPAddress("2001:0db8:85a3:00000:8A2E:0370:7334") << endl;
    return 0;
}