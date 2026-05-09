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
    int maxDepth(TreeNode* root) {
        if(root==nullptr)return 0;
        stack<pair<TreeNode*,int>>st;
        st.push({root, 1});
        int ans = 0;
        while(st.size()){
            TreeNode* node = st.top().first;
            int curDepth = st.top().second;
            st.pop();
            ans = max(ans,curDepth);
            if(node->left)st.push({node->left,curDepth+1});
            if(node->right)st.push({node->right,curDepth+1});
        }
        return ans;
    }
};
