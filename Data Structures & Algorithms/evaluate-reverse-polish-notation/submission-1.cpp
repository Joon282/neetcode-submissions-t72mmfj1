class Solution {
    //Push operands onto a stack until a operator is encountered
    //Pop the top 2 elements from the stack, the first element to the right, second to the left
    // Push the result after the operation has be done onto the stack 
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> stack;
        for (std::string c : tokens){
            if (c != "+" && c !=  "-" && c !=  "*" && c != "/"){
                stack.push(std::stoi(c));
            } else {
                int right = stack.top();
                stack.pop();
                int left = stack.top();
                stack.pop();
            if (c == "+"){
                stack.push(left + right);
            } else if (c == "-"){
                stack.push(left - right);
            } else if (c == "*"){
                stack.push(left * right);
            } else if (c == "/"){
                stack.push(left / right);
            }
            }
        }
        return stack.top();
    }
};
