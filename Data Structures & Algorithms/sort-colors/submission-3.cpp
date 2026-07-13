class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        mergeSort(nums, left, right);
    }
    void mergeSort(std::vector<int>& nums, int left, int right){
        if (left >= right){
            return;
        }
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid ,right);
    }
    
    void merge(std::vector<int>& nums, int left, int mid, int right){
        int size1 = mid - left + 1;
        int size2 = right - mid;
        std::vector<int> temp1(size1);
        std::vector<int> temp2(size2);
        for (int i = 0; i < size1; i++){
            temp1[i] = nums[left + i];
        }
        for (int i = 0; i < size2; i++){
            temp2[i] = nums[mid + 1 + i];
        }
        int i = 0;
        int j = 0;
        int k = left;
        while (i < size1 && j < size2){
            if (temp1[i] < temp2[j]){
                nums[k] = temp1[i];
                i++;
                k++;
            } else {
                nums[k] = temp2[j];
                j++;
                k++;
            }
        }
        while (i < size1) {
            nums[k] = temp1[i];
            i++;
            k++;
        }
        while (j < size2) {
            nums[k] = temp2[j];
            j++;
            k++;
        }
    }
};