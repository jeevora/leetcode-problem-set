#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
// Definition for a Node.
*/
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
    // recursive
    void preorder(Node* root, vector<int>& ans){
        if(!root)
            return;
        
        ans.push_back(root->val);

        for (auto child :root->children)
            preorder(child, ans);        
    }

    void preorder_iteratively(Node* root, vector<int>& ans){
        
    }
public:
    vector<int> preorder(Node* root) {

        vector<int> ans;
        preorder(root, ans);
        return ans;
        
    }
};