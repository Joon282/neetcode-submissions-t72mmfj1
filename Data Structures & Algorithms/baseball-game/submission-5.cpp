class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> board;
        int maxSum = 0;
        for (const std::string& op : operations){
            if (std::isdigit(op[0]) || (op[0] == '-' && op.size() > 1)) {
                int value = std::stoi(op);
                board.push(value);
                maxSum += board.top();
            } else if (op == "+"){
                int nums1 = board.top();
                board.pop();
                int nums2 = board.top();
                int sum = nums1 + nums2;
                board.push(nums1);
                board.push(sum);
                maxSum += board.top();
            } else if (op == "D"){
                int nums1 = board.top() * 2;
                board.push(nums1);
                maxSum += board.top();
            } else if (op == "C") {
                maxSum -= board.top();
                board.pop();
            }
        }
        return maxSum;
    }
};