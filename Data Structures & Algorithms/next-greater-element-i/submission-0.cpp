class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> results;
        int i = 0;
        while (i < nums1.size()){
            int j = nums2.size() - 1;
            int number = -1;
            while (j >= 0){
                if (nums2[j] > nums1[i]){
                    number = nums2[j];
                } else if (nums2[j] == nums1[i]){
                    break;
                }
                j--;
            }
            results.push_back(number);
            i++;
        }
        return results;
    }
};