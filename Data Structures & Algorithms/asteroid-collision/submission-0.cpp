class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> stack1;

        for (int a : asteroids){
            bool destroyed = false;
            while (!stack1.empty() && stack1.top() > 0 && a < 0){
                if (std::abs(stack1.top()) == std::abs(a)){
                    destroyed = true;
                    stack1.pop();
                    break;
                } else if (std::abs(stack1.top()) > std::abs(a)){
                    destroyed = true;
                    break;
                } else {
                    stack1.pop();
                }
            }
            if (!destroyed){
                stack1.push(a);
            }
        }
        std::vector<int> res(stack1.size());
        for (int i = res.size() - 1; i >= 0; i--){
            res[i] = stack1.top();
            stack1.pop();
        }
        return res;
    }
};