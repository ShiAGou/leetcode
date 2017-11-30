//
// Created by wesley shi on 2017/11/30.
//

#include "Solution.h"

void Solution::insertSpace(vector<string> &tmp, int wordlen, int maxWidth, vector<string> &lines){
    if (tmp.size() == 1){
        string s(tmp[0]);
        s.append(maxWidth - tmp[0].size(), ' ');
        lines.push_back(s);
        return;
    }
    string s;
    int space = (maxWidth-wordlen) / (int)(tmp.size()-1);
    int remain = (maxWidth-wordlen) % (int)(tmp.size()-1);
    for (auto tmp_iter=tmp.begin(); tmp_iter!=tmp.end(); tmp_iter++){
        s.append(*tmp_iter);
        if (tmp_iter == tmp.end()-1){
            continue;
        }
        int tmp_space = space;
        if (remain != 0){
            tmp_space ++;
            remain --;
        }
        s.append((unsigned long)tmp_space, ' ');
    }
    lines.push_back(s);
}


vector<string> Solution::fullJustify(vector<string> &words, int maxWidth) {
    vector<string> lines;
    if (words.empty()){
        return lines;
    }
    vector<string> tmp;
    int len = 0;
    int wordlen = 0;
    // for better performance, we can only record begin and end index of string in vector 'tmp'!!
    for (auto iter = words.begin(); iter != words.end(); iter ++){
        if (len == 0){
            len = (int)iter->size();
            wordlen = len;
            tmp.push_back(*iter);
        } else if (len + (int)iter->size() + 1 <= maxWidth){
            len += (int)iter->size() + 1;
            wordlen += (int)iter->size();
            tmp.push_back(*iter);
        } else {
            insertSpace(tmp, wordlen, maxWidth, lines);
            len = wordlen = (int)iter->size();
            tmp.clear();
            tmp.push_back(*iter);
        }
    }

    if (!tmp.empty()){
        insertSpace(tmp, wordlen, len, lines);
    }
    lines.back().append(maxWidth - lines.back().size(), ' ');
    return lines;
}
