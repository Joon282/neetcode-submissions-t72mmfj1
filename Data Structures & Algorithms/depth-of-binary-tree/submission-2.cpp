class Solution {
public:
    int maxDepth(TreeNode* root) {
        std::stack<TreeNode*> stack1;
        int maxDepth = 0;
        TreeNode* node = root;

        while (node != nullptr || !stack1.empty()) {
            if (node != nullptr) {
                stack1.push(node);
                maxDepth = std::max(maxDepth, (int)stack1.size());
                node = node->left;
            } else {
                node = stack1.top();
                stack1.pop();
                node = node->right;
            }
        }

        return maxDepth;
    }
};