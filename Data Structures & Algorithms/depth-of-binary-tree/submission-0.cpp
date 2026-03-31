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
    void traverse(TreeNode* node, int count, int& maxCount){
        if (node == nullptr){
            return;
        }
        count++;
        maxCount = std::max(maxCount, count);
        traverse(node->left, count, maxCount);
        traverse(node->right, count, maxCount);
    }
    int maxDepth(TreeNode* root) {
        int maxCount = 0;
        
        traverse(root, 0, maxCount);
        return maxCount;
    }
};
