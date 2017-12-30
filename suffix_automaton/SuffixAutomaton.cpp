//
// Created by wesley shi on 2017/12/30.
//

#include "SuffixAutomaton.h"

#include <iostream>

void SuffixAutomaton::init(){
    sz = last = index = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;
}


void SuffixAutomaton::extend(char c){
    int cur = sz++;
    st[cur].len = st[last].len+1;
    st[cur].first_pos = st[last].len;
    int p;
    for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link){
        st[p].next[c] = cur;
    }
    if (p == -1){
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[q].len == st[p].len+1){
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].len = st[p].len+1;
            st[clone].next= st[q].next;
            st[clone].link = st[q].link;
            st[clone].is_clon = true;
            st[clone].first_pos = st[q].first_pos;
            for (; p!=-1&&st[p].next[c]==q; p=st[p].link){
                st[p].next[c] = clone;
            }
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}


/**
 * 对所有状态，找到指向其的后缀链接的所有状态
 */
void SuffixAutomaton::inv_link(){
    for (int v=1; v<sz; ++v){
        st[st[v].link].inv_link.push_back(v);
    }
}


/**
 * 找到子串的所有匹配位置
 *
 * @param v 子串s的终止状态下标
 * @param p_length 子串的长度
 */
void SuffixAutomaton::output_all_occurences(int v, int p_length) {
    if (!st[v].is_clon){
        cout << st[v].first_pos-p_length+1 << " ";
    }
    for (size_t i=0; i<st[v].inv_link.size(); ++i){
        output_all_occurences(st[v].inv_link[i], p_length);
    }
    cout << endl;
}
