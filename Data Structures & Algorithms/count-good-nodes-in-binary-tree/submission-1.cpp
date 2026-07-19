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
    
    int goodNodes(TreeNode* root) {
        int ans = 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,INT_MIN});
        while(q.size()){
            TreeNode* node = q.front().first;
            int maxi = q.front().second;
            q.pop();
            if(node->val >= maxi){
                ans++;
            }
            if(node->left)q.push({node->left,max(maxi,node->val)});
            if(node->right)q.push({node->right,max(maxi,node->val)});
        }
        return ans;
    }
};
