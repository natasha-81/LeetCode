class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26);
        vector<bool> visited(26, false);

        // Step 1: last occurrence
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        stack<char> st;

        // Step 2: iterate
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (visited[c - 'a']) continue;

            while (!st.empty() && st.top() > c && last[st.top() - 'a'] > i) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(c);
            visited[c - 'a'] = true;
        }

        // build result
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        reverse(result.begin(), result.end());
        return result;
    }
};