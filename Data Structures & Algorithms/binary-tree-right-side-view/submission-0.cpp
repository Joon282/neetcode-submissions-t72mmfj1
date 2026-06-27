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
    vector<int> rightSideView(TreeNode* root) {
        if (!root){
            return {};
        }
        std::vector<int> results;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            TreeNode* curr = nullptr;
            int count = q.size();
            while (count > 0){
                TreeNode* node = q.front();
                q.pop();
                count--;
                if (node){
                    curr = node;
                    if (curr->left)  q.push(curr->left);   
                    if (curr->right) q.push(curr->right);
                }
            }
            if (curr){
                results.push_back(curr->val);
            }
        }
        return results;
    }
};
