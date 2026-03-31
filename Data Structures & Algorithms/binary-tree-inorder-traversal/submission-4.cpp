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
        std::stack<TreeNode*> recursiveStack;
        TreeNode* node = root;
        std::vector<int> results;
        while (node != nullptr || !recursiveStack.empty()){
            if (node != nullptr){
                recursiveStack.push(node);
                node = node->left;
            } else {
                node = recursiveStack.top();
                results.push_back(node->val);
                recursiveStack.pop();
                node = node->right;
            }
        }
        return results;
    }
};