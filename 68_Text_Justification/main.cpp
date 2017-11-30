#include <iostream>
#include "Solution.h"

void print(vector<string> &lines){
    for (auto itr = lines.begin(); itr != lines.end(); itr++){
        cout << *itr << endl;
    }
}

int main() {
    vector<string> words;
    words.emplace_back("This");
    words.emplace_back("is");
    words.emplace_back("an");
    words.emplace_back("example");
    words.emplace_back("of");
    words.emplace_back("text");
    words.emplace_back("justification.");
    auto s = new Solution;
    vector<string> lines = s->fullJustify(words, 16);
    print(lines);
    return 0;
}