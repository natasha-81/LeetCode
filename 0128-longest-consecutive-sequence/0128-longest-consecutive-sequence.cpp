class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 1;
        int count = 0;
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        if (n==0) return 0; //base case

        for (auto it: st) {
            if(st.find(it-1) == st.end()) {
                count = 1;
                int currentEl = it;
                while (st.find(currentEl+1) != st.end()) {
                    currentEl++;
                    count++;
                }
                longest = max(count, longest);
            }
        }
        return longest;
    }
};