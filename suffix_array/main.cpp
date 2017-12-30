#include <iostream>

#include "SuffixArray.h"
using namespace std;

int main() {
    SuffixArray sa;
    auto r = new int[10];
    r[0] = 1, r[1] = 2, r[2] = 3, r[3] = 4;
    r[4] = 1, r[5] = 2, r[6] = 3, r[7] = 5;
    r[8] = 1, r[9] = 0;
    auto sar = new int[10];
    sa.bucketSort(r, sar, 10, 6);
    for (int i=0; i<10; i++){
        cout << sar[i] << endl;
    }
    delete[](r);
    delete[](sar);
    return 0;
}