//
// Created by wesley shi on 2017/11/28.
//

#ifndef INC_151_REVERSE_WORDS_SOLUTION_H
#define INC_151_REVERSE_WORDS_SOLUTION_H

#include <string>

using namespace std;

class Solution {
public:
    void reverseWords(string &s);
    void reversePart(string &s, unsigned long start, unsigned long end);
    void reversePart(string &s, unsigned long sl, unsigned long sh, unsigned long el, unsigned long eh);

};


#endif //INC_151_REVERSE_WORDS_SOLUTION_H
