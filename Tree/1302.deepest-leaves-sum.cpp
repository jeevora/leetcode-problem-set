/*
 * @lc app=leetcode id=1302 lang=cpp
 *
 * [1302] Deepest Leaves Sum
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<iostream>
#include<algorithm>
#include<vector>
#include<Util\Include\BuildTreeFromPreOrderArray.h>

using namespace std;

class Solution {

    void dfs(TreeNode* root, int ans){

        if(!root)
            return;

        if(!root->left && !root->right)
            ans += root->val;

        dfs(root->left,ans);
        dfs(root->right,ans);
    }

public:
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        dfs(root,ans);
        return ans;
    }
};
// @lc code=end
int main(){
    vector<int> inOrder = {7,4,2,5,1,3,6,8},
                preOrder = {1,2,4,7,5,3,6,8};

    Solution sl;

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder,inOrder);
    
    sl.deepestLeavesSum(root);
}
