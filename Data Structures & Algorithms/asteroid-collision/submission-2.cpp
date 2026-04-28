class Solution {
    
    
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if (asteroids.empty()){
            return {};
        }
        std::vector<int> results;
        std::stack<int> stack1;
        for (int ast : asteroids){
            bool destroyed = false;
            while (!stack1.empty() && ast < 0 && stack1.top() > 0){
                if (std::abs(ast) > stack1.top()){
                    stack1.pop();
                } else if (std::abs(ast) < stack1.top()){
                    destroyed = true;
                    break;
                } else {
                    stack1.pop();
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed){
                stack1.push(ast);
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