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
        std::unordered_map<TreeNode*, int> height;
        std::stack<TreeNode*> stack1;
        TreeNode* node = root;
        TreeNode* visited = nullptr;
        while(!stack1.empty() || node != nullptr){
            if (node != nullptr){
                stack1.push(node);
                node = node->left;
            } else {
                node = stack1.top();
                if (node->right == nullptr || visited == node->right){
                    stack1.pop();
                    int left = height[node->left];
                    int right = height[node->right];
                    if (std::abs(left - right) > 1){
                        return false;
                    }
                    height[node] = 1 + std::max(left,right);
                    visited = node;
                    node = nullptr;
                } else {
                    node = node->right;
                }
            }
        }
        return true;
    }
};
