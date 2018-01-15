#include <iostream>
#include <vector>


using namespace std;

void p1(){
    int N;
    cin >> N;
    vector<string> vs;
    string a;
    for (int i=0; i<N; i++){
        cin >> a;
        vs.push_back(a);
    }

    int x[] = {1, 1, 1, 0, 0, -1,-1, -1};
    int y[] = {-1, 0,1, -1,1, -1, 0, 1};

    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (vs[i][j] == '*') {
                cout << '*';
                continue;
            }
            int num = 0;
            for (int k=0; k<8; k++){
                int tmpx = i+x[k];
                int tmpy = j+y[k];
                if (tmpx < N && tmpx>=0
                        && tmpy <N && tmpy >=0){
                    if (vs[tmpx][tmpy] == '*') num++;
                }
            }
            cout << num;
        }
        cout << endl;
    }

}

int guessN(vector<string> &vs, int pesuN, int K, bool print){
    int b = to_string(pesuN).size()+3;
    int ln = 1;
    int restrain = K - (to_string(ln).size()+b);
    int curl = 0;
    int i = 0;
    string space = " ";
    bool isspace = false;
    while (i != vs.size()){
        string *cur = nullptr;
        if (!isspace){
            cur = &vs[i];
            i++;
            isspace = true;
        } else {
            cur = &space;
            isspace = false;
        }
        if (curl +cur->size() > restrain){
            if (print) {
                cout << '(' << ln << '/' << pesuN << ')' << endl;
            }
            ln ++;
            restrain = K - (to_string(ln).size()+b);
            curl = cur->size();
            if (print) cout << *cur;
        } else {
            curl += cur->size();
            if (print) {
                cout << *cur;
            }
        }
    }

    if (print) cout << '(' << ln << '/' << pesuN << ')' << endl;
    return ln;
}

void split(std::string& s, std::string& delim,std::vector< std::string >* ret)
{
    size_t last = 0;
    size_t index=s.find_first_of(delim,last);
    while (index!=std::string::npos)
    {
        ret->push_back(s.substr(last,index-last));
        last=index+1;
        index=s.find_first_of(delim,last);
    }
    if (index-last>0)
    {
        ret->push_back(s.substr(last,index-last));
    }
}

void p2(){
    int K;
    cin >> K;
    string s;
    getline(cin, s);
    getline(cin, s);
    vector<string> vs;
    string space = " ";
    split(s, space, &vs);
    int pesuN = 1;
    int next = guessN(vs, pesuN, K, false);
    while (next != pesuN){
        pesuN = next;
        next = guessN(vs, pesuN, K, false);
    }
    guessN(vs, next, K, true);
}


#include <cmath>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <map>
#include <vector>
//#include <unordered_map>
//#include <unordered_set>
#include <stack>
#include <set>
#include <queue>
#include <list>
using namespace std;
typedef long long LL;
const int MAXN=100010;
int a[MAXN],b[MAXN];
int Search(int num,int low,int high) {
    int mid;
    while(low<=high) {
        mid=(low+high)/2;
        if(num>=b[mid]) low=mid+1;
        else high=mid-1;
    }
    return low;
}
int DP(int n) {
    int i,len,pos;
    b[1]=a[1];
    len=1;
    for(i=2; i<=n; i++) {
        if(a[i]>=b[len]) {
            len=len+1;
            b[len]=a[i];
        } else {
            pos=Search(a[i],1,len);
            b[pos]=a[i];
        }
    }
    return len;
}
int p3() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",a+i),a[i]=-a[i];
    printf("%d\n",n-DP(n));
    return 0;
}


int p4(){
    int M,N,K;
    cin >> M >> N >> K;
    vector<vector<long>> matrix(M+1, vector<long>(N+1, 0));
    for (int i=1; i<=M; i++){
        for (int j=1; j<=N; j++){
            cin >> matrix[i][j];
        }
    }
    vector<vector<long>> dpsum(matrix);
    for (int i=1; i<=M; i++){
        for (int j=1; j<=N; j++){
            dpsum[i][j] += dpsum[i-1][j] + dpsum[i][j-1]-dpsum[i-1][j-1];
        }
    }

    int maxsize=0;
    for (int i=1; i<=M; i++){
        for (int j=1; j<=N; j++){
            for (int k=i; k<=M; k++){
                for (int l=j; l<=N; l++){
                    long tmp = dpsum[k][l]+dpsum[i-1][j-1]-dpsum[k][j-1]-dpsum[i-1][l];
                    if (tmp <= K){
                        int tmpsize= (k-i+1)*(l-j+1);
                        maxsize = max(maxsize, tmpsize);
                    }
                }
            }
        }
    }
    cout << maxsize <<endl;
    return maxsize;
}


int main(void) {
    p4();
    return 0;
}
