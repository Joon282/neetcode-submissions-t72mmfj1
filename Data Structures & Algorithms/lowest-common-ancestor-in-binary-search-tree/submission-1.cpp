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
/*
    if p < q then p must be in the left subtree of q or the left subtree of root
    if p > q then p must be in the right subtree or either q or root
    if p < q && p is a subtree of q then return q otherwise return the parent of 
*/
class Solution {
public:
    bool dfs(TreeNode* start, TreeNode* target, std::vector<TreeNode*>& path) {
        if (!start) {
            return false;
        }
        path.push_back(start);
        if (start == target) {
            return true;
        }
        if (target->val < start->val) {
            return dfs(start->left, target, path);
        } 
            
        return dfs(start->right, target, path);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> p_path;
        std::vector<TreeNode*> q_path;
        dfs(root, p, p_path);
        dfs(root, q, q_path);
        int i = 0;
        TreeNode* curr = nullptr;
        while (i < p_path.size() && i < q_path.size()){
            if (p_path[i] == q_path[i]){
                curr = p_path[i++];
            } else {
                break;
            }
        }
        return curr;
    }
};
