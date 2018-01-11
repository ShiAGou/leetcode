#include <iostream>

#include "LCS.h"

using namespace std;

bool cmp(string s1, string s2){
    int c1=0, c2=0;
    while(true){
        int t1=-1, t2=-1;
        while(c1 < s1.size() && s1[c1]!='.'){
            t1 = t1<0?0:t1;
            t1 = t1*10 + (s1[c1]-'0');
            c1++;
        }
        while(c2 < s2.size() && s2[c2]!='.'){
            t2 = t2<0?0:t2;
            t2 = t2*10 + (s2[c2]-'0');
            c2++;
        }
        if (t1 <0 && t2 <0) return false;

        if (t1 < 0) {
            // cout << 1 << endl;
            return true;
        }
        else if (t2 < 0) {
            // cout << 0 << endl;
            return false;
        }
        else if (t1 != t2) {
            // cout << (t1 < t2) << endl;
            return t1 < t2;
        }
        c1++;
        c2++;
    }
}

int main(void) {
    /*
    int maxn = 0;
    int n;
    cin >> n;
    int N, K;
    string s = "hiho";
    vector<int> Ns, Ks;
    for (int i=0; i<n; i++){
        cin >> N >> K;
        Ns.push_back(N);
        Ks.push_back(K);
        maxn = max(maxn, N);
    }
    init(maxn);

    for (int i=0; i<n; i++){
        if (Ns[i] == 1) {
            cout << s[Ks[i]-1] << endl;
            continue;
        }
        int cnt[4] = {0};
        cnt[0] = dp[Ns[i]-1][0][3];
        cnt[1] = dp[Ns[i]-1][1][3];
        cnt[2] = dp[Ns[i]-1][0][3];
        cnt[3] = dp[Ns[i]-1][2][3];
        int j = 0;
        for (; j < 4; j++){
            if (Ks[i] <= cnt[j]){
                break;
            }
            Ks[i] -= cnt[j];
        }
        cout << search(Ns[i]-1, s[j], Ks[i]) << endl;
    }
    return 0;
     */
    int n, m;
    cin >> n >> m;
    vector<string> vs;
    string s;
    for (int i=0; i<n; i++){
        cin >> s;
        vs.push_back(s);
    }
    cout << lcs(vs, m);
}
