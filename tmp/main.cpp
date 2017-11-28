#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    void reversePart(string &s, unsigned long start, unsigned long end){
        for (unsigned long i = start, j = end; i < j; i++, j--){
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }

    void reversePart(string &s, unsigned long sl, unsigned long sh, unsigned long el, unsigned long eh){
        if (sl > sh || sh - sl != eh - el){
            return;
        }
        if (sl > eh){
            // no intersection
            for (unsigned long i = el, j = sh; j >= sl; i++,j--){
                s[i] = s[j];
            }
            return;
        }
        reversePart(s, eh+1, sh, el, sl-1);
        reversePart(s, sl, eh);
    }


    void reverseWords(string &s) {
        reversePart(s, 0, s.size()-1);
        unsigned long start = 0;
        unsigned long end = 0;
        int state = 0;
        for (unsigned long cursor = 0; cursor <= s.size(); cursor++){
            char cur = s[cursor];
            switch(state){
                case 0:
                    if (cur == ' '){
                        continue;
                    } else{
                        state = 1;
                    }
                    break;
                case 1:
                    if (cur == ' ' || cur == '\0'){
                        state = 0;
                        unsigned long len = end - start;
                        reversePart(s, cursor-1-len, cursor-1, start, end);
                        s[end+1] = cur;
                        start = end+2;
                        end = start;

                    } else{
                        end++;
                    }
            }
        }
        for (;end < s.size();end++){
            s[end] = ' ';
        }
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ")+1);
    }
};

int main() {
    Solution* s=new Solution();
    string str = string("  the sky is  blue   ");
    s->reverseWords(str);
    cout << str;
    return 0;
}