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
    vector<int> preorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> stack1;
        std::vector<int> results;
        TreeNode* curr = root;
        while (curr != nullptr || !stack1.empty()){
            if (curr != nullptr){
                stack1.push(curr);
                results.push_back(curr->val);
                curr = curr->left;
            } else {
                curr = stack1.top();
                stack1.pop();
                curr = curr->right;
            }
        }
        return results;
    }
};