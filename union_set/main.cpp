#include <iostream>
#include "CountingIsland2.h"

int main() {
    CountingIsland2 ci2;
    ci2.mark(0,0);
    cout << ci2.count << endl;
    ci2.mark(1,1);
    cout << ci2.count << endl;
    ci2.mark(1,0);
    cout << ci2.count << endl;
    ci2.mark(100,0);
    cout << ci2.count << endl;
    return 0;
}