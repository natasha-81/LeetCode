class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;
        for (string operation: operations) {
            if (operation == "C") {
                st.pop_back();
            }
            else if (operation == "D") {
                st.push_back(2 * st.back());
            }
            else if (operation == "+") {
                int n = st.size();
                st.push_back(st[n-1] + st[n-2]);
            }
            else {
                st.push_back(stoi(operation));
            }
        }
        int sum = 0;
        for (int i: st) {
            sum = sum+i;
        }
        return sum;
    }
};