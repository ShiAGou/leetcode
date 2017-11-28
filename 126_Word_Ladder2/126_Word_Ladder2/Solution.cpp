//
//  Solution.cpp
//  126_Word_Ladder2
//
//  Created by wesley shi on 2017/11/28.
//  Copyright © 2017年 self. All rights reserved.
//

#include "Solution.hpp"
#include <queue>

bool checkADJ(string a, string b){
    if (a.size() != b.size()){
        return false;
    }
    unsigned long diff = 0;
    for (unsigned long i = 0; i < a.size(); i++){
        if (a[i] != b[i]){
            diff++;
            if (diff > 1){
                return false;
            }
        }
    }
    return diff == 1;
}

unsigned long findStr(vector<string> &wordList, string endWord){
    for (unsigned long i=0; i < wordList.size(); i++){
        if (endWord == wordList[i]){
            return i;
        }
    }
    return ULONG_LONG_MAX;
}

void printMatrix(vector<vector<bool>> matrix, unsigned long size){
    for (unsigned long i = 0; i < size; i++){
        for (unsigned long j= 0; j< size; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


void printArr(unsigned long *arr, unsigned long size){
    for (int i=0; i<size; i++){
        cout<< arr[i]<<" ";
    }
    cout << endl;
}

void generateResult(vector<vector<unsigned long>> &pre_node, unsigned long end, unsigned long root, string& rootstr, vector<string> &wordList, vector<vector<string>> &result, vector<string>& cur){
    if (pre_node[end].size() == 0){
        return;
    }
    if (pre_node[end][0] == root){
        cur.insert(cur.begin(), rootstr);
        result.push_back(cur);
        return;
    }
    for (unsigned long i = 0; i<pre_node[end].size(); i++){
        vector<string> tmp(cur);
        unsigned long pre = pre_node[end][i];
        tmp.insert(tmp.begin(), wordList[pre]);
        generateResult(pre_node, pre, root, rootstr, wordList, result, tmp);
    }
}

vector<vector<string>> Solution::findLadders(string beginWord, string endWord, vector<string> &wordList){
    unsigned long end_index = findStr(wordList, endWord);
    vector<vector<string>> result;
    if (end_index == ULONG_LONG_MAX){
        return result;
    }
    unsigned long size = wordList.size();
    vector<vector<bool>> matrix(size+1, vector<bool>(size+1));
    vector<vector<unsigned long>> pre_node(size, vector<unsigned long>());
    unsigned long *path_len = new unsigned long[size+1];
    path_len[size] = 0;
    bool *fresh = new bool[size];
    for (unsigned long i = 0; i < size; i++){
        matrix[size][i] = checkADJ(wordList[i], beginWord);
        matrix[i][size] = matrix[size][i];
        matrix[i][i] = false;
        path_len[i] = ULONG_LONG_MAX;
        fresh[i] = true;
    }
    matrix[size][size] = false;
    if (matrix[size][end_index]){
        vector<string> v;
        v.push_back(beginWord);
        v.push_back(endWord);
        result.push_back(v);
        return result;
    }
    for (unsigned long i = 0; i < size; i++){
        for (unsigned long j = i+1; j < size; j++){
            matrix[i][j] = checkADJ(wordList[i], wordList[j]);
            matrix[j][i] = matrix[i][j];
        }
    }
    queue<unsigned long> nodes;
    nodes.push(size);
    while (!nodes.empty()){
        unsigned long n = nodes.front();
        nodes.pop();
        for (int i = 0; i< size; i++){
            if (fresh[i] && matrix[n][i]){
                if (path_len[i] >= path_len[n] + 1){
                    pre_node[i].push_back(n);
                    if (path_len[i] == ULONG_LONG_MAX){
                        nodes.push(i);
                    }
                    path_len[i] = path_len[n] + 1;
                } else {
                    fresh[i] = false;
                }
            }
        }
    }
    for (int i = 0; i< pre_node.size(); i++){
        for (int j=0; j<pre_node[i].size(); j++){
            cout << pre_node[i][j] << " ";
        }
        cout << endl;
    }
    vector<string> start;
    start.push_back(endWord);
    generateResult(pre_node, end_index, size, beginWord, wordList, result, start);
    return result;
}
