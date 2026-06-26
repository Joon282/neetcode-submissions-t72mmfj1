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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return val;
        }
        TreeNode* curr = root;
        if (val > curr->val){
            if (curr->right){
                insertIntoBST(curr->right, val);
            } else {
                TreeNode* right = new TreeNode(val);
                curr->right = right;
            }
        } else if (val < curr->val) {
            if (curr->left){
                insertIntoBST(curr->left, val);
            } else {
                TreeNode* left = new TreeNode(val);
                curr->left = left;
            }
        }
        return root;
    }
};