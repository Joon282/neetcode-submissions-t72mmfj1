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
    vector<int> postorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> stack1;
        std::vector<int> results;
        TreeNode* curr = root;
        TreeNode* visited = nullptr; 
        while (curr != nullptr || !stack1.empty()){
            if (curr != nullptr){
                stack1.push(curr);
                curr = curr->left;
            } else {
                TreeNode* node = stack1.top();
                if (node->right != nullptr && visited != node->right){
                    curr = node->right;
                } else {
                    results.push_back(node->val);
                    visited = node;
                    stack1.pop();
                }
            }
        }
        return results;
    }
};