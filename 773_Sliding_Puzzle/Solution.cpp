//
// Created by wesley shi on 2018/1/29.
//

#include "Solution.h"
#include <iostream>

int Solution::search(string s){
    cout << s << endl;
    auto itr = mp.find(s);
    if (itr != mp.end()){
        return itr->second;
    }
    // run BFS
    queue<string> *tmp = new queue<string>;
    queue<string> *cur = que;
    bool has_found = false;
    while (!cur->empty()){
        cur_steps++;
        while (!cur->empty()){
            string st = cur->front();
            cur->pop();
            int index = st.find('0');
            for (int i=0; i<moves[index].size(); i++){
                string stmp = st;
                stmp[index] = st[moves[index][i]];
                stmp[moves[index][i]] = '0';
                if (mp.find(stmp) != mp.end()) continue;
                cout << stmp << " ";
                tmp->push(stmp);
                mp.insert(pair<string, int>(stmp, cur_steps));
                if (s == stmp){
                    mp.insert(pair<string, int>{stmp, cur_steps});
                    has_found = true;
                }
            }
        }
        cout << endl;
        queue<string> *qqq = tmp;
        tmp = cur;
        cur = qqq;
        if (has_found){
            que = cur;
            return cur_steps;
        }
    }
    return -1;
}

int Solution::slidingPuzzle(vector<vector<int>>& board){
    string scur = "000000";
    for (int i=0; i<2; i++){
        for (int j=0; j<3; j++){
            scur[i*3+j] += board[i][j];
        }
    }
    return search(scur);
}
