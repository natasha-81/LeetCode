class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        int maxSum=0;
        int minSum=0;
        int result=0;
        for (int i : nums) {
            maxSum = max(i, maxSum+i);
            minSum = min(i,minSum+i);
            result = max(result, max(abs(maxSum), abs(minSum)));
        }
        return result;
    }
};