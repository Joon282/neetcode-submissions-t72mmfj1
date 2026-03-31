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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::stack<TreeNode*> stack1;
        std::stack<TreeNode*> stack2;
        stack1.push(p);
        stack2.push(q);
        while (!stack1.empty() && !stack2.empty()){
            TreeNode* curr1 = stack1.top();
            TreeNode* curr2 = stack2.top();
            stack1.pop();
            stack2.pop();
            if (curr1 == nullptr && curr2 == nullptr){
                continue;
            }

            if (curr1 == nullptr || curr2 == nullptr) {
                return false;
            }

            if (curr1->val != curr2->val) {
                return false;
            }
            stack1.push(curr1->left);
            stack2.push(curr2->left);
            stack1.push(curr1->right);
            stack2.push(curr2->right);
        }
        return true;
    }
};
