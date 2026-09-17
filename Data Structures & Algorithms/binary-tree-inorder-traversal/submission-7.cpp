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
    vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> stack1;
        std::vector<int> results;
        TreeNode* curr = root;
        while (!stack1.empty() || curr){
            if (curr){
                stack1.push(curr);
                curr = curr->left;
            } else {
                curr = stack1.top();
                results.push_back(curr->val);
                stack1.pop();
                curr = curr->right;
            }
        }
        return results;
    }
};