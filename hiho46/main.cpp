#include <iostream>
#include <vector>

using namespace std;

//修改的二分查找算法，返回数组元素需要插入的位置。
int BiSearch(char b[], int len, char w)
{
    int left = 1, right = len - 1;
    int mid;
    while (left < right)
    {
        mid = (left+right)>>1;
        if (b[mid] > w)
            right = mid;
        else if (b[mid] <= w)
            left = mid + 1;
    }
    return right;//数组b中不存在该元素，则返回该元素应该插入的位置
}

int LIS(string &s, int n, bool set, char B[])
{
    int len = 1;
    B[0] = 'a'-1;
    int i, pos = 0;

    for(i=0; i<n; ++i)
    {
        if (set && s[i] >= 'a' && s[i] <= 'i'){
            continue;
        } else if (!set && s[i] >='o' && s[i] <='u') {
            continue;
        }
        if(s[i] >= B[len-1]) //如果大于B中最大的元素，则直接插入到B数组末尾
        {
            B[len] = s[i];
            ++len;
        }
        else
        {
            pos = BiSearch(B, len, s[i]); //二分查找需要插入的位置
            B[pos] = s[i];
        }
    }

    return len-1;
}



int p1(){
    string s;
    cin >> s;
    int len = s.size();
    char aei[len+1];
    char ou[len+1];
    memset(aei, 0, sizeof(aei));
    memset(ou, 0, sizeof(ou));
    int aeilen = LIS(s, len, true, aei);
    int oulen = LIS(s, len, false, ou);
    return aeilen+oulen;
}

int transfer(char from, char to){
    int change = from-to;
    change = change<0? -change:change;
    change = change<5? change:10-change;
    return change;
}

long long p2(){
    int N;
    cin >> N;
    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<long long>> dp(N, vector<long long>(N, 0));
    for (int len=0; len<N; len++){
        for (int i=0; i<N-len; i++){
            long long change = transfer(s1[i+len], s2[i+len]);
            if (len == 0){
                dp[i][i] = change;
                continue;
            }
            change += dp[i][i+len-1];
            // try transfer
            for (int k=0; k<len; k++){
                long long tmp = transfer(s1[i+len], s2[i+k]) + transfer(s1[i+k], s2[i+len]) +1;
                if (k != 0){
                    tmp += dp[i][i+k-1];
                }
                if (k !=len-1){
                    tmp+= dp[i+k+1][i+len-1];
                }
                change = min(change, tmp);
            }
            dp[i][i+len] = change;

        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[0][N-1];
}

struct Pr{
    int i;
    int j;
    double value;
    Pr(int is, int js){
        i = is;
        j = js;
    }
};

int cmp(Pr &p1, Pr &p2){
    return p1.value<p2.value;
}

void p3(){
    int N,K;
    cin >> N >> K;
    int ps[N];
    int total = 0;
    for (int i=0; i<N; i++){
        cin >> ps[i];
        total += ps[i]-1;
    }
    vector<Pr> p(total, Pr(1,1));
    int k=0;
    for (int i=0; i<N; i++){
        for (int j=1; j<ps[i]; j++){
            p[k].i = ps[i];
            p[k].j = j;
            p[k].value = j/(double)ps[i];
            k++;
        }
    }
    sort(p.begin(), p.end(), cmp);
    Pr &pk = p[K-1];
    cout << pk.j << '/' << pk.i << endl;
}

#include<iostream>
#include<vector>
#include<string>
#include<strstream>
#include<algorithm>
#include<unordered_map>
using namespace std;
int MergeSort(vector<int>& nums, vector<int> &copy, int start, int end)
{
    if (start == end)
    {
        copy[start] = nums[start];
        return 0;
    }
    int len = (end - start) / 2;
    int left = MergeSort(nums, copy, start, start + len);
    int right = MergeSort(nums, copy, start + len + 1, end);
    int i = start, j = start + len + 1, index = start;
    int cnt = 0;
    while (i <= start + len && j <= end)
    {
        if (nums[i] < nums[j])
        {
            copy[index] = nums[i];
            i++;
        }
        else
        {
            copy[index] = copy[j];
            j++;
            cnt += start + len - i + 1;//次数统计逆序对
        }
        index++;
    }
    while (i <= start + len)//如果前半段有剩余则复制到copy数组中
    {
        copy[index] = nums[i];
        ++i;
        ++index;
    }
    while (j <= end)//如果后半段有剩余则复制到copy数组中
    {
        copy[index] = nums[j];
        ++j;
        ++index;
    }
    for (int i = start;i <= end;i++)//此时copy数组已经有序，将其复制到原数组中
        nums[i] = copy[i];
    return left + right + cnt;
}
int main()
{
    int a[8] = { 7,5,6,4 };
    vector<int> nums(a, a + 4);
    int len = nums.size();
    vector<int> copy(len);
    cout << "kkk "<<MergeSort(nums, copy, 0, len - 1) << endl;
    for (auto e : nums)
        cout << e << " ";
    cout << endl;
    for (auto e : copy)
        cout << e << " ";
    cout << endl;
    return 0;
}
