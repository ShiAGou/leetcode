#include <iostream>

#include <map>

using namespace std;

long long p1(){
    int t;
    cin >> t;
    int x, y;
    map<int, long long> mp;
    for (int i=0; i<t; i++){
        cin >> x >> y;
        int tmp = x-y;
        if (!mp.count(tmp)) {
            mp[tmp] = 0;
        }
        mp[tmp]++;
    }
    long long sum=0;
    for (auto itr=mp.begin(); itr != mp.end(); itr++){
        int key = itr->first;
        if (key == 0){
            continue;
        }
        else if (mp.count(-key)){
            sum += mp[-key]*itr->second;
        }
    }
    sum = sum>>1;
    if (mp.count(0)){
        sum += mp[0]*(mp[0]-1) >> 1;
    }
    return sum;
}


void p2(){
    int t;
    cin >> t;
    int x[t], y[t];
    int minx = 0;
    for (int i=0; i<t; i++){
        cin >> x[i] >> y[i];
        if (x[i] < x[minx]){
            minx = i;
        }
    }
    double g = -1;
    int next_index = -1;
    for (int i=0; i<t; i++){
        if (i == minx) continue;
        if (x[minx] == x[i]) {
            next_index = i;
            break;
        };
        double tmp_g = (y[minx] - y[i])/(double)(x[minx] - x[i]);
        if (tmp_g >= 0 && tmp_g > g){
            next_index = i;
            g = tmp_g;
        }
    }

    cout << minx+1 << ' '<< next_index+1 << endl;
}

#include <string>

int p3(){
    string s, t;
    cin >> s >> t;
    if (s.size() != t.size()) return -1;
    if (s.size() <= 1) return s==t?0:-1;

    int times=0;
    for (int i=0; i<s.size(); i++){
        if (s[i] == t[i]) continue;
        if (s[i] == '_' && t[i] == 'L'){
            int tmp = i+1;
            while(tmp < s.size() && s[tmp] != 'L'){
                tmp++;
            }
            if (tmp == s.size()) return -1;
            s[i] = 'L';
            s[tmp] = '_';
            times+= tmp-i;
        }
        else if (s[i] == 'R' && t[i] == '_'){
            int tmp = i+1;
            while(tmp < s.size() && s[tmp] != '_'){
                tmp++;
            }
            if (tmp == s.size()) return -1;
            s[i] = '_';
            s[tmp] = 'R';
            times+= tmp-i;

        } else {
            return -1;
        }
    }
    return times;
}

const int maxm = 1000000;
const int maxn = 100000;
int node[maxn] = {0};
int from[maxm] = {0};
int to[maxm] ={0};
int nedge[maxm]={0};
int cur=0;

bool dfs(int nd, bool visit[], int target){
    visit[nd] = true;
    if (nd == target)
        return true;
    int head = node[nd];
    while (head!=0){
        int child = to[head];
        if (from[head] != nd) cout << "construction err!!!"  << from[head]<< endl;
        if (!visit[child]) {
            if (dfs(child, visit, target)){
                return true;
            }
        }
        head = nedge[head];
    }
    return false;
}

void add_edge(int f, int t){
    from[++cur] = f;
    to[cur] = t;
    int head = node[f];
    node[f] = cur;
    nedge[cur] = head;
}

int p4(){
    int N, M;
    scanf("%d %d\n", &N, &M);
    bool reach1[N+1],reachN[N+1];
    memset(reach1, 0, sizeof(reach1));
    memset(reachN, 0, sizeof(reachN));
    reach1[1] = true; reachN[N]=true;
    int small, big;
    char alg;
    for (int i=0; i<M; i++){
        scanf("A%d %c A%d\n", &small, &alg, &big);
        add_edge(big, small);
        if (alg == '='){
            add_edge(small, big);
            if (reach1[small]){
                if (dfs(small, reach1, N)) return i+1;
            }
            if (reachN[small]){
                if (dfs(small, reachN, 1)) return i+1;
            }
        }
        if (reach1[big]){
            if (dfs(big, reach1, N)) return i+1;
        }
        if (reachN[big]){
            if (dfs(big, reachN, 1)) return i+1;
        }
    }
    return -1;
}

int main() {
    cout << p4() << endl;
    return 0;
}