//
//  main.cpp
//  126_Word_Ladder2
//
//  Created by wesley shi on 2017/11/28.
//  Copyright © 2017年 self. All rights reserved.
//

#include <iostream>
#include "Solution.hpp"

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution *s = new Solution();
    /**
    string beginWord = string("hit");
    string endWord = string("cog");
    vector<string> wordList;
    wordList.push_back(string("hot"));
    wordList.push_back(string("dot"));
    wordList.push_back(string("dog"));
    wordList.push_back(string("lot"));
    wordList.push_back(string("log"));
    **/
    string beginWord = string("hot");
    string endWord = string("dog");
    vector<string> wordList;
    wordList.push_back(string("hot"));
    wordList.push_back(string("dog"));
    
    vector<vector<string>> result = s->findLadders(beginWord, endWord, wordList);
    for (int i=0; i<result.size(); i++){
        for (int j = 0; j<result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
