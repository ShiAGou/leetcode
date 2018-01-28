#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct P{
    char c;
    int t;

    P(char c1, int t1){
        c = c1;
        t = t1;
    }
};

bool cmp(P& p1, P&p2){
    return p1.t < p2.t;
};

string reorganizeString(string S) {
    int mp[26];
    memset(mp, 0, sizeof(mp));
    for (int i=0; i<S.size(); i++){
        mp[S[i]-'a']++;
    }
    int sum = S.size();
    vector<P> vp;
    for (int i=0; i<26; i++){
        if (mp[i] == 0) continue;
        vp.push_back(P(i+'a', mp[i]));
        if (S.size()-mp[i] < mp[i]-1){
            return string("");
        }
    }
    sort(vp.begin(), vp.end(), cmp);
    string r;
    while(!vp.size()){
        auto frst = vp.begin();
        auto scd = frst+1;
        if (vp.size() == 2 && *frst.t == *scd.t){
            break;
        }
        int f, s;
        if (*frst->t == *scd->t){
            *scd->t = 1;
            s =
            sum++;
        } else {
            vp.erase(scd);
            f = s+1;
        }
        auto tmp = vp.begin();
        int interval = sum - *tmp.t;
        if (interval < *tmp.t -1){
            // cannot use

        }
    }
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}