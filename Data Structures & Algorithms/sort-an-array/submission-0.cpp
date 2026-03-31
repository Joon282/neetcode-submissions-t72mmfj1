class Solution {
public:
    void merge(std::vector<int>& array, int left, int mid, int right){
        int n1 = mid - left + 1;
        int n2 = right - mid;
        std::vector<int> vec1;
        std::vector<int> vec2;
        for (int i = 0; i < n1; i++){
            vec1.push_back(array[left + i]);
        }
        for (int i = 0; i < n2; i++){
            vec2.push_back(array[mid + 1 + i]);
        }
        int i = 0;
        int j = 0;
        int k = left;
        while (i < n1 && j < n2) {
            if (vec1[i] < vec2[j]){
                array[k++] = vec1[i++];
            } else {
                array[k++] = vec2[j++];
            }
        }
        while (j < n2){
            array[k++] = vec2[j++];
        }
        while (i < n1){
            array[k++] = vec1[i++];
        }
    }
    void mergeSort(std::vector<int>& array, int left, int right){
        if (left >= right){
            return;
        }
        int mid = (left + right) / 2;
        mergeSort(array,left, mid);
        mergeSort(array,mid+1,right);
        merge(array,left,mid,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0 , nums.size()-1);
        return nums;
    }
};