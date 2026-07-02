class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivotIdx = -1;
        //find the first smallest element from right
        for (int i = n-2; i>=0; i--) {
            if (nums[i] < nums[i+1]) {
                pivotIdx = i;
                break;
            }
        }
        if (pivotIdx == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        //find the first element that is greater than pivot element
        for (int i=n-1; i>pivotIdx; i--) {
            if (nums[i] > nums[pivotIdx]) {
                swap(nums[pivotIdx], nums[i]);
                break;
            }
        }
        //reverse rest suffix elements
        reverse(nums.begin()+pivotIdx+1, nums.end());
    }
};