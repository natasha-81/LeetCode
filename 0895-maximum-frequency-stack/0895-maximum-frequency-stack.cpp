class FreqStack {
private:
    unordered_map<int,int> count;
    vector<int> st;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        st.push_back(val);
        count[val]++;
    }
    
    int pop() {
        int maxCount = 0;
        for (auto& [_,frequency] : count) {
            maxCount = max(maxCount,frequency);
        }
        int i = st.size()-1;
        while (count[st[i]] != maxCount) {
            i--;
        }
        int val = st[i];
        st.erase(st.begin()+i);
        count[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */