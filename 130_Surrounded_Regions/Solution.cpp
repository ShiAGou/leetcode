//
// Created by wesley shi on 2017/11/30.
//

#include "Solution.h"
#include <queue>

void Solution::solve(vector<vector<char>> &board) {
    unsigned long Y = board.size();
    if (Y == 0){
        return;
    }
    unsigned long X = board[0].size();
    queue<ordinate> q;
    vector<ordinate> v;
    for (unsigned long i = 0; i < Y; i++){
        for (unsigned long j = 0; j < X ; j++) {
            if (board[i][j] != 'O') {
                continue;
            }
            ordinate p(i, j);
            q.push(p);
            v.push_back(p);
            bool surrounded = false;
            while (!q.empty()) {
                ordinate tmp = q.front();
                q.pop();
                if (!surrounded && (tmp.x == 0 || tmp.x == X - 1 || tmp.y == 0 || tmp.y == Y - 1)) {
                    surrounded = true;
                }
                // add surroundings
                if (tmp.y != Y - 1 && board[tmp.y + 1][tmp.x] == 'O') {
                    ordinate t(tmp.y + 1, tmp.x);
                    board[tmp.y+1][tmp.x] = '1';
                    q.push(t);
                    v.push_back(t);
                }
                if (tmp.y != 0 && board[tmp.y - 1][tmp.x] == 'O') {
                    ordinate t(tmp.y - 1, tmp.x);
                    board[tmp.y-1][tmp.x] = '1';
                    q.push(t);
                    v.push_back(t);
                }
                if (tmp.x != X - 1 && board[tmp.y][tmp.x + 1] == 'O') {
                    ordinate t(tmp.y, tmp.x + 1);
                    board[tmp.y][tmp.x+1] = '1';
                    q.push(t);
                    v.push_back(t);
                }
                if (tmp.x != 0 && board[tmp.y][tmp.x - 1] == 'O') {
                    ordinate t(tmp.y, tmp.x - 1);
                    board[tmp.y][tmp.x-1] = '1';
                    q.push(t);
                    v.push_back(t);
                }
            }
            char rplce = surrounded ? 'o' : 'X';
            for (unsigned long k = 0; k < v.size(); k++) {
                board[v[k].y][v[k].x] = rplce;
            }
            v.clear();
        }
    }
    for (unsigned long i=0; i<Y; i++){
        for (unsigned long j=0; j<X; j++){
            if (board[i][j] == 'o'){
                board[i][j] = 'O';
            }
        }
    }

}