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
    int DepthSearch(TreeNode* node, int& count){
        if (node == nullptr){
            return 0;
        }
        int left = DepthSearch(node->left, count);
        int right = DepthSearch(node->right, count);
        count = std::max(count, left+right);
        return 1 + std::max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int count = 0;
        DepthSearch(root, count);
        return count;
    }
};
