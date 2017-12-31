//
// Created by wesley shi on 2017/12/31.
//

#include "CountingIsland2.h"

CountingIsland2::CountingIsland2() {
    memset(A, -1, sizeof(A));
};

void CountingIsland2::mark(int x, int y){
    int index = M*x + y;
    if (A[index] != -1) return;
    A[index] = index;
    count++;
    for (int i=0; i<4; i++){
        int tmpx = x+x_offset[i], tmpy=y+y_offset[i];
        int tmp_index = tmpx*M + tmpy;
        if (tmpx < M && tmpx >=0
            && tmpy < M && tmpy >= 0
            && A[tmp_index] != -1){
            join(index, tmp_index);
        }
    }
}

void CountingIsland2::join(int x1, int x2){
    int f1 = find(x1);
    int f2 = find(x2);
    if (f1 == f2) {
        return;
    }
    A[f1] = f2;
    count--;
}

int CountingIsland2::find(int x){
    if (A[x] != x){
        A[x] = find(A[x]);
    }
    return A[x];
}
