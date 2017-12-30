#include <iostream>

#include "SuffixAutomaton.h"

int main() {
    SuffixAutomaton sa;
    sa.init();
    char c[] = "aabbabd";
    for (int i=0; c[i]!='\0'; i++){
        sa.extend(c[i]);
    }
    sa.inv_link();
    return 0;
}
    
