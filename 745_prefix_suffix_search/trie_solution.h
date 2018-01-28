//
// Created by wesley shi on 2018/1/18.
//

#ifndef INC_745_PREFIX_SUFFIX_SEARCH_SOLUTION_H
#define INC_745_PREFIX_SUFFIX_SEARCH_SOLUTION_H

#include <vector>
#include <string>

using namespace std;

struct node{
    vector<int> words;
    int next[26] = {0};
};

const int maxn = 150001;

class WordFilter {
public:
    node N[maxn];
    node M[maxn];
    int cur = 1;

    WordFilter(vector<string> words) {
        construct(N, words, true);
        cur = 1;
        construct(M, words, false);
    }

    void construct(node a[], vector<string> &words, bool pre){
        cur++; // root
        for (int i=0; i<words.size(); i++){
            a[1].words.push_back(i);
            int anchor = 1; // root
            for (int j=0; j<words[i].size(); j++){
                int actual_j = pre? j:words[i].size()-j-1;
                int index = words[i][actual_j] - 'a';
                int next = a[anchor].next[index];
                if (next == 0){
                    next = cur++;
                    a[anchor].next[index] = next;
                }
                a[next].words.push_back(i);
                anchor = next;
            }
        }
    }

    int f(string prefix, string suffix) {
        int pre_anchor = 1, suf_anchor=1;
        for (int i = 0; i<prefix.size() && pre_anchor > 0; i++){
            pre_anchor = N[pre_anchor].next[prefix[i]-'a'];
        }
        for (int i = suffix.size()-1; i>=0 && suf_anchor > 0; i--){
            suf_anchor = M[suf_anchor].next[suffix[i]-'a'];
        }
        if (pre_anchor == 0 || suf_anchor == 0){
            return -1;
        }
        vector<int> &a = N[pre_anchor].words;
        vector<int> &b = M[suf_anchor].words;
        int i = a.size()-1;
        int j = b.size()-1;
        while (i>=0 && j>= 0 && a[i] != b[j]){
            if (a[i] > b[j]) i--;
            else j--;
        }
        if (i >=0 && j>=0){
            return a[i];
        }
        return -1;
    }
};



#endif //INC_745_PREFIX_SUFFIX_SEARCH_SOLUTION_H
