#include <iostream>
#include "Solution.h"

int main() {
    Solution *s = new Solution();
    string str = string(" ");
    s->reverseWords(str);
    cout << str;
    return 0;
}