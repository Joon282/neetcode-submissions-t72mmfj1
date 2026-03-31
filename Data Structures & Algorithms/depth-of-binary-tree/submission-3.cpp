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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        std::stack<std::pair<TreeNode*, int>> stack1;
        TreeNode* node = root;
        int depth = 1;
        int maxDepth = 0;

        while (node != nullptr || !stack1.empty()) {
            if (node != nullptr) {
                stack1.push({node, depth});
                maxDepth = std::max(maxDepth, depth);

                node = node->left;
                depth++;  // going down the tree
            } else {
                auto [curr, d] = stack1.top();
                stack1.pop();

                node = curr->right;
                depth = d + 1;  // set depth correctly for right child
            }
        }

        return maxDepth;
    }
};
