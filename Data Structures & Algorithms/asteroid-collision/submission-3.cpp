class Solution {
    
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if (asteroids.empty()){
            return {};
        }
        std::stack<int> stack1;
        std::vector<int> results;
        for (int asteroid : asteroids) {
            bool destroyed = false;
            while (!stack1.empty() && asteroid < 0 && stack1.top() > 0) {
                if (std::abs(asteroid) > stack1.top()){
                    stack1.pop();
                } else if (std::abs(asteroid) < stack1.top()){
                    destroyed = true;
                    break;
                } else {
                    stack1.pop();
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                stack1.push(asteroid);
            }
        }
        while(!stack1.empty()){
            results.push_back(stack1.top());
            stack1.pop();
        }

        std::reverse(results.begin(),results.end());
        return results;
    }
};