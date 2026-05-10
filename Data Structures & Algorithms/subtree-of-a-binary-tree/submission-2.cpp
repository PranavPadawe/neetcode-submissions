class Solution {
public:

    void serialize(TreeNode* root, string& s) {

        if (!root) {
            s += "#,";
            return;
        }

        s += to_string(root->val) + ",";

        serialize(root->left, s);
        serialize(root->right, s);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        string s1, s2;

        serialize(root, s1);
        serialize(subRoot, s2);

        return s1.find(s2) != string::npos;
    }
};