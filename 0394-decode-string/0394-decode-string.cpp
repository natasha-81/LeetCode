class Solution {
public:
    string decodeString(string s) {
        vector<string> st;
        for (char& c: s) {
            if (c != ']') {
                st.push_back(string(1,c));
            }
            else {
                string substr = "";
                while (st.back() != "[") {
                    substr = st.back() + substr;
                    st.pop_back();
                }
                st.pop_back(); //pop '[' opening bracket

                string k ="";
                while (!st.empty() && isdigit(st.back()[0])) {
                    k = st.back() + k;
                    st.pop_back();
                }
                int repeatCount = stoi(k);
                string repeated = "";
                for (int i=0; i<repeatCount; i++) {
                    repeated += substr;
                }
                st.push_back(repeated);

            }
        }
        string res = "";
        for (const string& part : st) {
            res +=part;
        }
        return res;
    }
};