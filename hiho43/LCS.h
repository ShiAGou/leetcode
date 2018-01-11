//
// Created by wesley shi on 2018/1/7.
//

#ifndef HIHO43_LCS_H
#define HIHO43_LCS_H

#include <string>
#include <vector>

using namespace std;

bool haveone(vector<int> &tp, int w, int k,int size, int n);
void lcp(vector<int> &r, vector<int> &sa, int n);
void bucketSort(vector<int> &r, vector<int> &sa, int n, int m);
int lcs(vector<string> &ss, int m);


#endif //HIHO43_LCS_H
