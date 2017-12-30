//
// Created by wesley shi on 2017/12/26.
//

#include "Solution.h"

void TrieNode::insert(string s){
    auto size = s.size();
    if (size==0) return;
    TrieNode* cur = this;
    for (decltype(size) i=0; i<size; i++){
        if (cur->sons[s[i]-'a'] == nullptr){
            cur->sons[s[i]-'a'] = new TrieNode();
        }
        cur = cur->sons[s[i]-'a'];
        if (i == size-1){
            cur->end = true;
        }
    }
}

vector<string> Solution::findAllConcatenatedWordsInADict(vector<string>& words){
    auto size = words.size();
    if (size <= 1) {
        vector<string> empty;
        return empty;
    }
    auto root = new TrieNode();
    for (decltype(size) i=0; i<size; i++){
        root->insert(words[i]);
    }
    vector<string> result;
    for (decltype(size) i=0; i<size; i++){
        const char* c = words[i].data();
        if (find(c, 0, words[i].size(), root, 0)){
            result.push_back(words[i]);
        };
    }
    delete(root);
    return result;
}

bool Solution::find(const char* s, int i, const int size, TrieNode* root, int count){
    TrieNode* cur = root;
    for (; i<size; i++){
        TrieNode* next = cur->sons[s[i]-'a'];
        if (next == nullptr){
            return false;
        }
        if (i == size-1) return next->end && count >=1;
        if (next->end){
            if (find(s, i+1, size, root, count+1)){
                return true;
            }
        }
        cur = next;
    }
    return false;
}
