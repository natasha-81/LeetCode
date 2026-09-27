class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (int a: asteroids) {
            while (!st.empty() && a<0 && st.top()>0) {
                int difference = a+st.top();
                if (difference < 0) {
                    st.pop();
                }
                else if (difference==0) {
                    a = 0;
                    st.pop();
                }
                else {
                    a = 0;
                }
            }
            // if stack empty 
            if (a != 0) {
                st.push(a);
            }
        }
        vector<int> ans;
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
    }
};