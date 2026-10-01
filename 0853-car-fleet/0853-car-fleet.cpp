class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pair;
        for (int i=0; i<position.size(); i++) {
            pair.push_back({position[i],speed[i]});
        }
        sort(pair.rbegin(),pair.rend());
        vector<double> st;
        for (auto &p: pair) {
            st.push_back((double) (target - p.first) / p.second);
            if (st.size() >= 2 && st.back() <= st[st.size()-2]) {  // if current car time is less than or equal to fleet ahead, it will become fleet
                st.pop_back(); //remove current means merged into fleet
            }
        }
        return st.size();
    }
};