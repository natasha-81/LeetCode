class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;
        vector<int> lastSeen(256,-1);
        int left = 0;
        for (int right=0; right<n; right++) {
            if (lastSeen[s[right]] != -1) {
                left = max(left,lastSeen[s[right]]+1);
            }
            lastSeen[s[right]] = right; //storing the index of unique char of substring
            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};