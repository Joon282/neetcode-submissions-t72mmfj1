class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if (asteroids.empty()){
             return {};
        }
        std::stack<int> stack1;

        for (int i = 0; i < asteroids.size(); i++) {
            stack1.push(asteroids[i]);
            while (stack1.size() >= 2) {
                int num = stack1.top();      
                stack1.pop();
                int num2 = stack1.top();    
                stack1.pop();
                if (num2 > 0 && num < 0) {
                    if (std::abs(num) == std::abs(num2)) {
                        break;
                    } else if (std::abs(num) > std::abs(num2)) {
                        stack1.push(num);
                    } else {
                        stack1.push(num2);
                        break;
                    }
                } else {
                    stack1.push(num2);
                    stack1.push(num);
                    break;
                }
            }
        }
        std::vector<int> results(stack1.size());
        for (int i = results.size() - 1; i >= 0; i--) {
            results[i] = stack1.top();
            stack1.pop();
        }
        return results;
        }
};