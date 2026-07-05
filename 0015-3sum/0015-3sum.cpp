class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> resultTriplets;
        for (int i=0; i<n; i++) {
            if (i>0 && nums[i] == nums[i-1]) {  //skip duplicates for first element to be chosen
                continue;
            }
            int left = i+1;
            int right = n-1;
            while (left<right) {
                int sum = nums[i]+nums[left]+nums[right];
                if (sum == 0) {
                    resultTriplets.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    //skip duplicate for left elements 
                    while (left<right && nums[left] == nums[left-1]) {
                        left++;
                    }
                    //skip dupliate for right elements
                    while (left<right && nums[right] == nums[right+1]) {
                        right--;
                    }
                }
                else if (sum<0) {
                    left++;
                }
                else right--;
            }
        }
        return resultTriplets;
    }
};