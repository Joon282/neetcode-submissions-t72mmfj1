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
    bool isBalanced(TreeNode* root) {
        if (!root){
            return true;
        }
        bool check = true;
        getHeight(root, check);
        return check;
    }
    int getHeight(TreeNode* node, bool& check){
        if (!node){
            return 0;
        }
        int left = getHeight(node->left, check);
        int right = getHeight(node->right, check);
        if (std::abs(right - left) > 1){
            check = false;
        }
        return 1 + std::max(left,right);
    }
};
