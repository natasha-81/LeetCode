class LFUCache {
    struct Listnode {
        int key;
        int val;
        int freq;
        Listnode* prev;
        Listnode* next;
        Listnode(int key, int val) : key(key), val(val), freq(1), prev(nullptr), next(nullptr) {}
    };
    struct Linkedlist {
        Listnode* left;
        Listnode* right;
        int size;
        Linkedlist() {
            left = new Listnode(0,0);
            right = new Listnode(0,0);
            left -> next = right;
            right -> prev = left;
            size = 0;
        }
        ~Linkedlist () {
            delete left;
            delete right;
        }
        int length() {
            return size;
        }
        void pushRight(Listnode* node) {
            Listnode* previous = right->prev;
            previous->next = node;
            node->prev = previous;
            node->next = right;
            right->prev = node;
            size++;
        }
        void pop(Listnode* node) {
            Listnode* previous = node->prev;
            Listnode* nextnode = node->next;
            previous->next = nextnode;
            nextnode->prev = previous;
            node->next = nullptr;
            node->prev = nullptr;
            size--;
        }
        Listnode* popLeft() { //LRU
            Listnode* node = left->next;
            pop(node);
            return node;
        }

    };
    int capacity;
    int lfuCount;
    unordered_map<int,Listnode*> nodemap;  // maps key->node
    unordered_map<int,Linkedlist*> listmap;  // maps frequency->linkedlist

    void counter(Listnode* node) {
        int count = node->freq;
        listmap[count]->pop(node);
        if (count == lfuCount && listmap[count]->length() == 0) { //if node removed from min freq group and that group is empty
            lfuCount++;
        }
        node->freq++;
        if (!listmap.count(node->freq)) { //if new frequency doesnt exist create new list for that frequency
            listmap[node->freq] = new Linkedlist();
        }
        listmap[node->freq]->pushRight(node);
    }
public:
    LFUCache(int capacity) : capacity(capacity), lfuCount(0) {
        
    }
    
    int get(int key) {
        if (nodemap.find(key) == nodemap.end()) {
            return -1;
        }
        Listnode* node = nodemap[key];
        counter(node);
        return node->val;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;
        if (nodemap.find(key) != nodemap.end()) {
            Listnode* node = nodemap[key];
            node->val = value;
            counter(node);
            return;
        }
        if (nodemap.size() == capacity) {
            Listnode* toRemove = listmap[lfuCount]->popLeft();
            nodemap.erase(toRemove->key);
            delete toRemove;
        }
        Listnode* node = new Listnode(key,value);
        nodemap[key] = node;
        if (!listmap.count(1)) {
            listmap[1] = new Linkedlist();
        }
        listmap[1]->pushRight(node);
        lfuCount = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */