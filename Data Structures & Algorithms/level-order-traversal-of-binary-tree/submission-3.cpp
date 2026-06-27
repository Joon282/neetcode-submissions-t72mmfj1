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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root){
            return {};
        }
        std::vector<std::vector<int>> results;
        std::queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()){
            int count = q.size();
            std::vector<int> values;
            while (count > 0){
                TreeNode* curr = q.front();
                values.push_back(curr->val);
                q.pop();
                count--;
                if (curr->left){
                    q.push(curr->left);
                }
                if (curr->right){
                    q.push(curr->right);
                }
            }
            results.push_back(values);
        }
        return results;
    }
};
