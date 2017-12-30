//
// Created by wesley shi on 2017/12/26.
//

#ifndef INC_472_CONCATENATED_WORDS_SOLUTION_H
#define INC_472_CONCATENATED_WORDS_SOLUTION_H


#include <vector>
#include <string>

using namespace std;

class TrieNode{
public:
    bool  end;
    TrieNode* sons[26];
    TrieNode() {
        end = false;
        for (int i=0; i<26; i++){
            sons[i] = nullptr;
        }
    }
    void insert(string s);

    ~TrieNode(){
        for (int i=0; i<26; i++){
            if (sons[i] != nullptr){
                delete(sons[i]);
            }
        }
    }
};

class Solution {

public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words);

private:
    bool find(const char* s, int i, const int size, TrieNode* root, int count);
};


#endif //INC_472_CONCATENATED_WORDS_SOLUTION_H
