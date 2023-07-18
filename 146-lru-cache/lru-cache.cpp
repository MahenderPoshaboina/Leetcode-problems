class LRUCache {
private:
    int capacity;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    std::list<int> lru;
    
    void updateLRU(int key) {
        lru.erase(cache[key].second);
        lru.push_front(key);
        cache[key].second = lru.begin();
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        
        updateLRU(key);
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            cache[key].first = value;
            updateLRU(key);
            return;
        }
        
        if (cache.size() == capacity) {
            int lastKey = lru.back();
            cache.erase(lastKey);
            lru.pop_back();
        }
        
        lru.push_front(key);
        cache[key] = {value, lru.begin()};
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */