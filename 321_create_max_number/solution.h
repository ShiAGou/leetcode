//
// Created by wesley shi on 2018/1/19.
//

#ifndef INC_321_CREATE_MAX_NUMBER_SOLUTION_H
#define INC_321_CREATE_MAX_NUMBER_SOLUTION_H

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    void mask(vector<int> &nums, vector<int> &mask){
        vector<int> s(nums.size(), 0);
        int top= 0;
        s.push_back(0);
        int k = nums.size();
        for (int i=1; i< nums.size(); i++){
            while (top >= 0 && nums[i] > nums[s[top]]){
                k--;
                mask[s[top]] = k;
                top--;
            }
            s[++top] = i;
        }
        while (top >= 0){
            mask[s[top--]] = --k;
        }
    }

    void copy(vector<int> &s, vector<int> &mask, int si, int k, vector<int> &d, int di){
        for (int i=0; i<k; i++){
            while (mask[si] >= k) si++;
            d[di++] = s[si++];
        }
    }

    bool cmp(vector<int> &s1, vector<int> &s2){
        for (int i =0; i<s1.size(); i++){
            if (s1[i] != s2[i]) return s1[i] < s2[i];
        }
        return false;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> max(k, -1);
        if (nums1.size() == 0 || nums2.size() == 0){
            vector<int> &n = nums1.size()==0? nums2:nums1;
            vector<int> mm(k, 0);
            mask(n, mm);
            max = vector<int>(k, -1);
            copy(n, mm, 0, k, max, 0);
            return max;
        }
        vector<int> mask1(nums1.size(), 0), mask2(nums2.size(), 0);
        mask(nums1, mask1);
        mask(nums2, mask2);
        vector<int> tmp(k, -1);
        int max1 = k< nums1.size()? k:nums1.size();
        int min1 = k<nums2.size()? 0:k-nums2.size();
        int max2 = k< nums2.size()? k:nums2.size();
        for (int i=min1, j=max2; i<=max1; i++, j--){
            int len=0, a1=0, a2=0;
            for (;len<k;len++){
                while(a1<nums1.size() && mask1[a1] >= i) a1++;
                while(a2<nums2.size() && mask2[a2] >= j) a2++;
                if (a1==nums1.size() || a2==nums2.size()){
                    break;
                }
                if (nums1[a1] < nums2[a2]){
                    tmp[len] = nums2[a2];
                    a2++;
                } else {
                    tmp[len] = nums1[a1];
                    a1++;
                }
            }
            if (len != k) {
                if (a1 != nums1.size()) copy(nums1, mask1, a1, i, tmp, len);
                else if (a2 != nums2.size()) copy(nums2, mask2, a2, j, tmp, len);
            }
            if (cmp(max, tmp)){
                for (int i=0; i<k; i++){
                    max[i] = tmp[i];
                }
            }
        }
        return max;
    }
};

#endif //INC_321_CREATE_MAX_NUMBER_SOLUTION_H
