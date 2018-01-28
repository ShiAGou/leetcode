#include <iostream>
#include "trie_solution.h"
#include <string>

int main() {
    vector<string> vs;
    string s = "pop";
    vs.push_back(s);
    WordFilter *wf = new WordFilter(vs);
    cout << wf->f("", "op") << endl;
    return 0;
}