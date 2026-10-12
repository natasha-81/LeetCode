class LRUCache {
    private:
    vector<pair<int,int>> cache;
    int capacity;
public:
    LRUCache(int capacity) {
        this-> capacity = capacity;
    }
    
    int get(int key) {
        for (int i=0; i<cache.size(); i++) {
            //if found
            if (cache[i].first == key) {
                pair<int,int> temp = cache[i];
                cache.erase(cache.begin()+i);
                cache.push_back(temp); // most recently used 
                return temp.second;
            }
        }
        //if not found
        return -1;
    }
    
    void put(int key, int value) {
        for (int i=0; i<cache.size(); i++) {
            // if key already in the list, update value and add at end
            if (cache[i].first == key) {
                cache.erase(cache.begin()+i);
                cache.push_back({key,value});
                return;
            }
        }
        //if capacity is full, remove lru that is first element
        if (cache.size() == capacity) {
            cache.erase(cache.begin());
        }
        cache.push_back({key,value});
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */