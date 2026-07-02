class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int posIdx = 0;
        int negIdx = 1;
        vector<int> resultArr(n);
        for (int i=0; i<n; i++) {
            if (nums[i] > 0) {
                resultArr[posIdx] = nums[i];
                posIdx+=2;
            }
            else {
                resultArr[negIdx] = nums[i];
                negIdx+=2;
            }
        }
        return resultArr;
    }
};