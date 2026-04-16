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
        std::stack<std::pair<TreeNode*, TreeNode*>> stack1;
        stack1.push({p,q});
        while (!stack1.empty()){
            auto [p,q] = stack1.top();
            stack1.pop();
            if (!p && !q){
                continue;
            }
            if (!p && q || !q && p){
                return false;
            }
            if (p->val != q->val) {
                return false;
            }
            stack1.push({p->right, q->right});
            stack1.push({p->left, q->left});
        }
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::stack<TreeNode*> stack1;
        stack1.push(root);
        while (!stack1.empty()){
            TreeNode* node = stack1.top();
            stack1.pop();
            if (node->val == subRoot->val){
                if (isSameTree(node, subRoot)){
                    return true;
                }
            } 
            if (node->left != nullptr){
                stack1.push(node->left);
            }
            if (node->right != nullptr){
                stack1.push(node->right);
            }
        }
        return false;
    }
};
