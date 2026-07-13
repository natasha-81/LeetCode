class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int k = s2.size();
        if (k<n) return false;
        vector<int> s1count(26,0), s2count(26,0);
        for (char ch : s1) {
            s1count[ch-'a']++;
        }
        for (int i=0; i<n; i++) {
            s2count[s2[i]-'a']++;
        }
        if (s2count == s1count) return true;
        for (int i=n; i<k; i++) {
            s2count[s2[i]-'a']++;
            s2count[s2[i-n]-'a']--;
            if (s2count == s1count) return true;
        }
        return false;
    }
};