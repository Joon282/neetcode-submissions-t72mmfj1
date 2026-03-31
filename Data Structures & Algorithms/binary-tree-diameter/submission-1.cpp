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
    int DFS(TreeNode* node){
        if (node == nullptr){
            return 0;
        }
        return 1 + (std::max(DFS(node->left), DFS(node->right)));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int left = DFS(root->left);
        int right = DFS(root->right);
        int diameter = left + right;
        int currentNode = std::max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right));
        return std::max(diameter, currentNode)
    }
};
