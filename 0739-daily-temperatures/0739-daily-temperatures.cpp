class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>res(n,0);
        stack<pair<int,int>> st;  //pair :- {temp,index}
        for (int i=0; i<n; i++) {
            int curr_temp = temperatures[i];
            while (!st.empty() && curr_temp > st.top().first) {
                auto pair = st.top();
                st.pop();
                res[pair.second] = i - pair.second;
            }
            st.push({curr_temp,i});
        }
        return res;
    }
};