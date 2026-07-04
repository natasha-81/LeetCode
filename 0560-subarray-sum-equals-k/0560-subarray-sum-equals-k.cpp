class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int prefixSum = 0;
        unordered_map<int,int> mpp; //prefixsum,occurence of prefixsum
        mpp[0] = 1; //prefixsum 0 has occurred once
        for (int i=0; i<nums.size(); i++) {
            prefixSum = prefixSum + nums[i];
            int remaining = prefixSum - k;
            if (mpp.find(remaining) != mpp.end()) {  // if remaining prefixsum found in map
                    count = count + mpp[remaining];
            }
            mpp[prefixSum]++;
        }
        return count;
    }
};