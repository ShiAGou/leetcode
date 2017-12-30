//
// Created by wesley shi on 2017/12/27.
//

#ifndef SUFFIX_ARRAY_SUFFIXARRAY_H
#define SUFFIX_ARRAY_SUFFIXARRAY_H


class SuffixArray {

public:
    void bucketSort(int* r, int* sa, int n, int m);
    void lcp(const int* r, const int* sa, int n);
};


#endif //SUFFIX_ARRAY_SUFFIXARRAY_H
