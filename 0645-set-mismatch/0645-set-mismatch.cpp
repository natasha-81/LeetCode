class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int calcXor = 0;
        for (int i=0; i<n; i++) {
            calcXor ^= nums[i];
            calcXor ^= (i+1);
        }
        int findBit = calcXor & -calcXor;
        int zero = 0, one = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] & findBit) {
                one ^= nums[i];
            }
            else {
                zero ^= nums[i];
            }
            if ((i+1) & findBit) {
                one ^= (i+1);
            }
            else {
                zero ^= (i+1);
            }
        }
        for (int x: nums) {  // find repeating element
            if (x==zero) return {zero,one};
        }
        return {one,zero};
    }
};