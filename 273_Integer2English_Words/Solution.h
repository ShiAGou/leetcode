//
// Created by wesley shi on 2017/12/4.
//

#ifndef INC_273_INTEGER2ENGLISH_WORDS_SOLUTION_H
#define INC_273_INTEGER2ENGLISH_WORDS_SOLUTION_H

#include <string>
#include <vector>

using namespace std;

class Solution {

public:
    Solution();
    string numberToWords(int num);
    string numts(int num, int begin, int end, bool need_and);

private:
    int* tens;
    vector<string> num2s;
};


#endif //INC_273_INTEGER2ENGLISH_WORDS_SOLUTION_H
