class Node {
public:
    string url;
    Node* prev;
    Node* next;

    Node (string u) {
        url = u;
        this->prev = NULL;
        this->next = NULL;
    }
};
class BrowserHistory {
public:
    Node* current = NULL;
    BrowserHistory(string homepage) {
        current = new Node(homepage);
    }
    
    void visit(string url) {
        Node* newnode = new Node(url);
        //remove any forward history
        current->next = NULL;
        newnode->prev = current;
        current->next = newnode;
        current = newnode;
    }
    
    string back(int steps) {
        while (steps-- && current->prev) {
            current = current->prev;
        }
        return current->url;
    }
    
    string forward(int steps) {
        while (steps-- && current->next) {
            current = current->next;
        }
        return current->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */