#include <iostream>
#include "Solution.h"

int main() {
    Solution *s = new Solution;
    string s1("a");
    string s2("dbbca");
    cout << s->isInterleave(s1, s2, "dbbada") << endl;
    cout << s->isInterleave(s1, s2, "dbbcaa") << endl;
    return 0;
}