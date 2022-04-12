/*
 * @lc app=leetcode id=508 lang=cpp
 *
 * [508] Most Frequent Subtree Sum
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
#include<bits/stdc++.h>
#include "Util\Include\BuildTreeFromPreOrderArray.h"

using namespace std;

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        
    }
};
// @lc code=end

int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();

    vector<int> preOrder1 = {1,2,5,3};
    //         1
    //     2       3
    //       5          
    vector<int> inOrder1 = {5,2,1,3};

    BuildTreeFromPreOrderArray bl;
    TreeNode* root = bl.buildTree(preOrder1, inOrder1);

    Solution sl;
    sl.findFrequentTreeSum(root);
}
