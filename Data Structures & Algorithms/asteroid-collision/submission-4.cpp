class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> stack1;
        for (int ast : asteroids){
            bool destroyed = false;
            while (!stack1.empty() && ast < 0 && stack1.top() > 0){
                int top = stack1.top();
                int num = std::abs(ast);
                if (top < num){
                    stack1.pop();
                } else if (top > num){
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    stack1.pop();
                    break;
                }
            }
            if (!destroyed){
                stack1.push(ast);
            }
        }
        std::vector<int> results(stack1.size());
        for (int i = results.size() - 1; i >= 0; i--){
            results[i] = stack1.top();
            stack1.pop();
        }
        return results;
    }
};