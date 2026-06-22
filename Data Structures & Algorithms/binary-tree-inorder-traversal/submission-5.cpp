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
        if (!root) {
            return {};
        }
        std::vector<int> results;
        std::stack<TreeNode*> sp;
        TreeNode* curr = root;
        while (curr || !sp.empty()){
            if (curr){
                sp.push(curr);
                curr = curr->left;
            } else {
                TreeNode* node = sp.top();
                results.push_back(node->val);
                sp.pop();
                curr = node->right;
            }
        }
        return results;
    }
};