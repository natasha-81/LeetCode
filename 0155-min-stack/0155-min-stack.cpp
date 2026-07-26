class MinStack {
public:
vector<int> arr;
vector<int> mini;
    MinStack() {
        
    }
    
    void push(int value) {
        arr.push_back(value);
        if (mini.empty()) {
            mini.push_back(value);
        }
        else {
            mini.push_back(min(mini.back(),value));
        }
    }
    
    void pop() {
        arr.pop_back();
        mini.pop_back();
    }
    
    int top() {
        return arr.back();
    }
    
    int getMin() {
        return mini.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */