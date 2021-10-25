#include<iostream>
#include<queue>
#include<stack>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
    void _dfs(TreeNode* root, int p=INT_MIN, cur,mx=INT_MIN){

        if(!root)
            return;
        if(root->left)
            inorder(root->left);
        if(p==root->val) cur++;
        else cur=1;
        if(cur==mx) {
            modes.push_back(root->val);
        }
        if(cur>mx) {
            modes.clear();
            modes.push_back(root->val);
            mx=cur;
        }
        p=root->val;
        if(root->right)
            inorder(root->right);

    }
public:
    vector<int> findMode(TreeNode* root) {

        int prev=INT_MIN, cur, mx=INT_MIN;

        
    }
};

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {1,2,2};
    vector<int> inOrder1 = {1,2,2};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    // vector<int> preOrder1 = {0};
    // vector<int> inOrder1 = {0};

    // TreeNode* root1 = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    for(auto it: sl.findMode(root))
        cout << it << endl;
}