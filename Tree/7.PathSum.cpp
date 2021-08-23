#include<iostream>
#include<queue>
#include<stack>
#include<unordered_set>

using namespace std;

/**
 * Definition for a binary tree node.
 **/ 
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
    void DFS_Recursive_PreOrderTraversal(TreeNode* root, int &ans, int targetSum){

        if (!root || ans == targetSum)
            return;

        ans +=root->val;

        if (root->left && (ans+=root->left->val <= targetSum))
            DFS_Recursive_PreOrderTraversal(root->left, ans, targetSum);

        if (root->right && (ans+=root->right->val <= targetSum))
            DFS_Recursive_PreOrderTraversal(root->right, ans, targetSum);

    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        int ans;
        
        if(!root)
            return ans;

        DFS_Recursive_PreOrderTraversal(root, ans, targetSum);

        return ans;
    }
};
