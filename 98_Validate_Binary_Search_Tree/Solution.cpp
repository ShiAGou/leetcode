//
// Created by wesley shi on 2017/12/5.
//

#include "Solution.h"

#include <iostream>
using namespace std;

bool isvalid(TreeNode* root, long lowerbound, long upperbound){
    if (root == nullptr) return true;
    if (root->val <= lowerbound || root->val >= upperbound) return false;
    return isvalid(root->left, lowerbound, root->val)
           && isvalid(root->right, root->val, upperbound);
}


bool Solution::isValidBST(TreeNode* root) {
    return isvalid(root, LONG_MIN, LONG_MAX);
}
