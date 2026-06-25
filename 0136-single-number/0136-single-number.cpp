class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int result_xor = 0;
        for (int i=0; i<n; i++) {
            result_xor= result_xor ^ nums[i];
        }
        return result_xor;
        
    }
};