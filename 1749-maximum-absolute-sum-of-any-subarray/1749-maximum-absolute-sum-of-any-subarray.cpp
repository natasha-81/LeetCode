class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int prefixSum = 0;
        int max_prefixSum = 0;
        int min_prefixSum = 0;
        for (int i=0; i<nums.size(); i++) {
            prefixSum = prefixSum + nums[i];
            max_prefixSum = max(prefixSum,max_prefixSum);
            min_prefixSum = min(prefixSum,min_prefixSum);
        }
        return max_prefixSum - min_prefixSum;
    }
};