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

class Solution {
public:
     vector<int> dfs(TreeNode* node){
        if(!node)return {1,0};
        vector<int>left = dfs(node->left);
        vector<int>right = dfs(node->right);
        int isBal = (left[0]==1 && right[0]==1 && abs(left[1]-right[1])<=1) ? 1 : 0;
        int height = 1 + max(left[1],right[1]);
        return {isBal, height};
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0];
    }
};
