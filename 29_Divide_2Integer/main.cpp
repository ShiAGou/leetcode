#include <iostream>
#include "Solution.h"
using namespace std;

int main() {
    Solution *s = new Solution();
    cout << s->divide(2147483646, 4) << endl;
    return 0;
}