#include <iostream>
#include "Solution.h"

void print(vector<vector<char>> &board){
    unsigned long Y = board.size();
    if (Y == 0){
        return;
    }
    unsigned long X = board[0].size();
    for (unsigned long i=0; i<Y; i++){
        for (unsigned long j=0; j<X; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<char> v1(4, 'X');
    vector<vector<char>> board(4, v1);
    board[1][1] = 'O';
    board[1][2] = 'O';
    board[2][2] = 'O';
    board[3][1] = 'O';
    print(board);
    auto* s = new Solution();
    s->solve(board);
    print(board);
    return 0;
}