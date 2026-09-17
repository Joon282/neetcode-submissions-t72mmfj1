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
    int diameterOfBinaryTree(TreeNode* root) {
         if (!root){
            return 0;
        }
        int leftDistance = 0;
        int rightDistance = 0;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left){
                    q.push(curr->left);
                    leftDistance++;
                }
                if (curr->right){
                    q.push(curr->right);
                    rightDistance++;
                }
            }
        }
        return 1 + std::max(leftDistance, rightDistance);
    }
};
