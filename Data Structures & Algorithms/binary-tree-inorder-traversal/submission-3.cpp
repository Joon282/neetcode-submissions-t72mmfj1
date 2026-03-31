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
        TreeNode* current = root;
        while (current != nullptr || !stack1.empty()){
            while(current != nullptr){
                stack1.push(current);
                current = current->left;
            }
            current = stack1.top();
            results.push_back(current->val);
            stack1.pop();
            current = current->right;
        }
        return results;
    }
};