//
// Created by wesley shi on 2017/12/5.
//

#ifndef INC_98_VALIDATE_BINARY_SEARCH_TREE_SOLUTION_H
#define INC_98_VALIDATE_BINARY_SEARCH_TREE_SOLUTION_H


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    bool isValidBST(TreeNode* root);

};


#endif //INC_98_VALIDATE_BINARY_SEARCH_TREE_SOLUTION_H
