struct Node {
    int value;
    int minVal;
    Node* next;

    Node(int v, int m) {
        value = v;
        minVal = m;
        next = NULL;
    }
};
class MinStack {
public:
    Node* head;
    MinStack() {
        head = NULL;
    }
    
    void push(int value) {
        if (head == NULL ) {
            head = new Node(value,value);
        }
        else {
            int newMin = min(value,head->minVal);
            Node* temp = new Node(value, newMin);
            temp->next = head;
            head = temp;
        }
    }
    
    void pop() {
        if (head == NULL) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    int top() {
        if (head == NULL) return -1;
        return head->value;
    }
    
    int getMin() {
        if (head == NULL) return -1;
        return head->minVal;
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