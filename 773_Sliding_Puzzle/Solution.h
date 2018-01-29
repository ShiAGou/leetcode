//
// Created by wesley shi on 2018/1/29.
//

#ifndef INC_773_SLIDING_PUZZLE_SOLUTION_H
#define INC_773_SLIDING_PUZZLE_SOLUTION_H

#include <vector>
#include <unordered_map>
#include <string>
#include <queue>

using namespace std;

class Solution {
private:
    unordered_map<string, int> mp;
    vector<vector<int>> moves = {{1,3},{0,2,4},{1,5},{0,4},{3,5,1},{4,2}};
    queue<string> *que;
    int cur_steps;
    int search(string s);
public:
    Solution(){
        que = new queue<string>;
        que->emplace("123450");
        mp.insert(pair<string, int>(string("123450"), 0));
        cur_steps = 0;
    }
    int slidingPuzzle(vector<vector<int>>& board);
};


#endif //INC_773_SLIDING_PUZZLE_SOLUTION_H
