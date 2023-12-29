#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct treeNode{
    int idx;//nodeinfo의 idx
    int x;
    int y;
    treeNode* left=NULL;
    treeNode* right=NULL;
} treeNode;

vector<treeNode> tree;

void makeTree(treeNode* parent, treeNode* cur) {
    if (cur->x < parent->x) {
        if (parent->left != NULL) {
            makeTree(parent->left, cur);
        }else if (parent->left == NULL) {
            parent->left = cur;
        }
    }
    else if (parent->x < cur->x) {
        if (parent->right != NULL) {
            makeTree(parent->right, cur);
        }
        else if (parent->right == NULL) {
            parent->right = cur;
        }
        
    }
}

bool cmp(vector<int> a, vector<int> b) {
    if (a[1]>b[1]) {
        return true;
    }
    else if (a[1]==b[1]) {
        if (a[0]<b[0]) {
            return true;
        }
        else return false;
    }
    else return false;
}

void preorder(treeNode* root, vector<int> &ret) {
    ret.push_back(root->idx);
    if (root->left!=NULL) {
        preorder(root->left, ret);
    }
    if (root->right!=NULL) {
        preorder(root->right, ret);
    }
}

void postorder(treeNode* root, vector<int> &ret) {
    
    if (root->left!=NULL) {
        postorder(root->left, ret);
    }
    if (root->right!=NULL) {
        postorder(root->right, ret);
    }
    ret.push_back(root->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    for (int i=0; i<nodeinfo.size(); i++) {//nodeinfo[i][2]에 idx 저장
        nodeinfo[i].push_back(i+1);
    }
    
    sort(nodeinfo.begin(), nodeinfo.end(), cmp);
    
    for (int i=0; i<nodeinfo.size(); i++) {
        treeNode t;
        t.x = nodeinfo[i][0];
        t.y = nodeinfo[i][1];
        t.idx = nodeinfo[i][2];
        tree.push_back(t);
    }
    
    for (int i=1; i<tree.size(); i++) {
        makeTree(&tree[0], &tree[i]);
    }
    vector<int> temp;
    preorder(&tree[0], temp);
    answer.push_back(temp);
    
    vector<int> temp2;
    postorder(&tree[0], temp2);
    answer.push_back(temp2);
    return answer;
}