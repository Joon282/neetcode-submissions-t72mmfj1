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
        std::stack<std::pair<TreeNode*,TreeNode*>> stk1;
        stk1.push({p,q});
        while (!stk1.empty()){
            auto [p,q] = stk1.top();
            stk1.pop();
            if (!p && !q){
                continue;
            }
            if (!p && q || p && !q){
                return false;
            }
            if (p->val != q->val){
                return false;
            }
            stk1.push({p->left,q->left});
            stk1.push({p->right,q->right});
        }
        return true;
    }
};
