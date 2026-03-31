class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = m + n - 1;
        int j = n - 1;
        for (int i = size; i >= m; i--){
            nums1[i] = nums2[j];
            j--;
        }
        std::sort(nums1.begin(), nums1.end());
    }
};