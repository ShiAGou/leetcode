//
// Created by wesley shi on 2017/11/30.
//

#ifndef INC_68_TEXT_JUSTIFICATION_SOLUTION_H
#define INC_68_TEXT_JUSTIFICATION_SOLUTION_H

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth);

private:
    void insertSpace(vector<string> &tmp, int wordlen, int maxWidth, vector<string> &lines);
};


#endif //INC_68_TEXT_JUSTIFICATION_SOLUTION_H
