#include <iostream>
#include "Solution.h"

int main() {
    Solution solution;
    vector<string> words={"cat", "cats", "catsdogcats", "dog",
                          "dogcatsdog", "hippopotamuses", "rat", "ratcatsdogcat"};
    vector<string> result = solution.findAllConcatenatedWordsInADict(words);
    for (string s:result){
        cout<<s<<endl;
    }
    return 0;
}