//
// Created by wesley shi on 2018/1/19.
//

#ifndef INC_440_KTH_LEXICO_ORDER_NUM_SOLUTION_H
#define INC_440_KTH_LEXICO_ORDER_NUM_SOLUTION_H

#include <string>

using namespace std;

class Solution {
public:
    int L[10];

    Solution(){
        L[0] = 1;
        for(int i=1; i<10; i++){
            L[i] = 1+10*L[i-1];
        }
    }

    int leval(int i){
        if (i < 0) return 0;
        return L[i];
    }

    int get(string &num, string &n){
        int flag = 0;
        for (int i=0; i<num.size(); i++){
            if (num[i] != n[i]) {
                flag = num[i] > n[i]? 1:-1;
                break;
            }
        }
        if (flag < 0)
            return leval(n.size()-num.size());
        else if (flag > 0)
            return leval(n.size()-num.size()-1);
        else {
            int sum = 1+n.size()-num.size();
            for (int i=num.size(); i<n.size(); i++){
                sum += (n[i]-'0') * leval(n.size()-i-1);
                sum += ('9' - n[i])*leval(n.size()-i-2);
            }
            return sum;
        }
    }

    string search(int k, string &num, string &n){
        char tmp = '0';
        if (num.size() != 0) {
            if (k==1) return num;
            k--;
        } else {
            tmp ++;
        }
        string stmp = num.append(1, tmp);
        int itmp = get(stmp, n);
        while (k > itmp){
            k -= itmp;
            tmp++;
            stmp[stmp.size()-1] = tmp;
            itmp = get(stmp, n);
        }
        return search(k, stmp, n);
    }

    int findKthNumber(int n, int k) {
        string empty="";
        string sn = to_string(n);
        return atoi(search(k, empty, sn).c_str());
    }
};


#endif //INC_440_KTH_LEXICO_ORDER_NUM_SOLUTION_H
