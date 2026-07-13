class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> needed(128,0);
        for (char c: t) {
            needed[c]++;
        }
        int count = t.size();
        int minlen = INT_MAX;
        int start = 0;
        int l=0, r=0;
        while(r<s.size()) {
            if (needed[s[r]] > 0) count--;
            needed[s[r]]--;
            //shrink window
            while (count==0) {
                if (r-l+1<minlen) {
                    minlen = r-l+1;
                    start = l;
                }
                needed[s[l]]++;
                if (needed[s[l]] > 0) count++; //after remmoving that char we require it thats why count ++
                l++;
            }
            r++;
        }
        return minlen == INT_MAX ? "" : s.substr(start,minlen);
    }
};