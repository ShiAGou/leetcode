#include <iostream>

#include "Solution.h"
using namespace std;

int main() {
    Solution *s = new Solution;
    TreeNode *left = new TreeNode(4);
    TreeNode *right = new TreeNode(3);
    TreeNode *root = new TreeNode(2);
    root->left = left;
    root->right = right;
    cout << s->isValidBST(root);
    return 0;
}