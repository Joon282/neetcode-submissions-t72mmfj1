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
 // 
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        std::stack<TreeNode*> stk;
        std::vector<int> results;
        TreeNode* visited = nullptr;
        while (!stk.empty() || curr){
            if (curr){
                stk.push(curr);
                curr = curr->left;
            } else {
                TreeNode* node = stk.top();
                if (node->right && visited != node->right){
                    curr = node->right;
                } else {
                    results.push_back(node->val);
                    visited = node;
                    stk.pop();
                }
            }
        }
        return results;
    }
};