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
    int kthSmallest(TreeNode* root, int k) {
        if (!root){
            return 0;
        }
        int count = 0;
        std::stack<TreeNode*> stack_p;
        while (root || !stack_p.empty()){
            while (root){
                stack_p.push(root);
                root = root->left;
            }
            TreeNode* curr = stack_p.top();
            stack_p.pop();
            k--;
            if (k == 0){
                return curr->val;
            }
            curr = curr->right;
            root = curr;
        }
        return -1;
    }
};
