//
// Created by wesley shi on 2018/1/7.
//

#ifndef HIHO43_BINARYTREE_H
#define HIHO43_BINARYTREE_H

#include <iostream>
#include <vector>
using namespace std;

struct node{
    int n;
    node* left= nullptr;
    node* right = nullptr;
    node* parent = nullptr;
};

void dfs(node* p, int &n, vector<node*> &sorted){
    // p is the leaf
    if (p->left == nullptr && p->right == nullptr){
        sorted[n++] = p;
    }
    if (p->left != nullptr) dfs(p->left, n, sorted);
    if (p->right!= nullptr) dfs(p->right, n, sorted);
}

vector<int> search(node *root, int N){
    vector<node*> sorted(N, nullptr);
    int n = 0;
    dfs(root, n, sorted);
    bool is_visited[N];
    memset(is_visited, 0, sizeof(is_visited));

    vector<int> result;
    for (int i=0; i<n; i++){
        node* leaf=sorted[i];
        while (leaf != nullptr){
            if (!is_visited[leaf->n]){
                result.push_back(leaf->n);
                is_visited[leaf->n] = true;
            }
            leaf = leaf->parent;
        }
    }
    return result;
}

void main_fuc(){
    int N;
    cin >> N;
    int p, c;
    node ND[100000];
    for (int i=0; i<2*N; i++){
        ND[i].n = i;
    }
    int maxn = -1;
    for (int i=0; i<N-1; i++){
        cin >> p >> c;
        p--; c--;
        ND[p].n = p;
        ND[c].n = c;
        maxn = max(maxn, p);
        maxn = max(maxn, c);
        if (ND[p].left == nullptr) ND[p].left = &ND[c];
        else{
            if (ND[p].left->n > c){
                ND[p].right = ND[p].left;
                ND[p].left = &ND[c];
            }
            else {
                ND[p].right = &ND[c];
            }
        }
        ND[c].parent = &ND[p];
    }
    node* root;
    for (int i=0; i<=maxn; i++){
        if (ND[i].parent == nullptr){
            root = &ND[i];
        }
    }
    vector<int> result = search(root, maxn+1);
    for (int i=0; i<N; i++){
        cout << result[i]+1 << endl;
    }
}



#endif //HIHO43_BINARYTREE_H
