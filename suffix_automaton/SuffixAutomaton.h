//
// Created by wesley shi on 2017/12/30.
//

#ifndef SUFFIX_AUTOMATON_SUFFIXAUTOMATON_H
#define SUFFIX_AUTOMATON_SUFFIXAUTOMATON_H

#include <map>
#include <vector>

using namespace std;

struct state{
    int len, link;
    map<char, int> next;

    bool is_clon=false;
    // 状态s
    int first_pos;
    vector<int> inv_link;
};


const int MAXLEN = 10000;


class SuffixAutomaton {
    state st[MAXLEN*2];
    int sz, last;
    int index;

public:
    void init();
    void extend(char c);

    void inv_link();
    void output_all_occurences(int v, int p_length);
};


#endif //SUFFIX_AUTOMATON_SUFFIXAUTOMATON_H
