class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int candidate1 = 0;
        int candidate2 = 0;
        for (int i=0; i<n; i++) {
            if (count1==0 && candidate2!=nums[i]) {
                count1++;
                candidate1=nums[i];
            }
            else if (count2==0 && candidate1!=nums[i]) {
                count2++;
                candidate2=nums[i];
            }
            else if (candidate1 == nums[i]) {
                count1++;
            }
            else if (candidate2 == nums[i]) {
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
    vector<int> result;
    count1=0;
    count2=0;
    for (int i=0; i<n; i++) {
        if (candidate1 == nums[i]) {
            count1++;
        }
        else if (candidate2 == nums[i]) {
            count2++;
        }
    }
    if (count1 > n/3) {
        result.push_back(candidate1);
    }
    if(count2 > n/3) {
        result.push_back(candidate2);
    }
    return result;
    }
};