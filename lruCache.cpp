class LRUCache {
public:
    list<pair<int, int>> q;
    unordered_map<int, list<pair<int, int>>::iterator> cache;
    int capacity;
    LRUCache(int c) {
        capacity = c;
    }
    
    int get(int key) {
        if(cache.count(key)) {
            int value = cache[key]->second;
            q.erase(cache[key]);
            q.push_front(pair<int,int>(key, value));
            cache[key] = q.begin();
            return cache[key]->second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(cache.count(key)) {
            q.erase(cache[key]);
        }
        if(q.size() == capacity) {
            int last = q.back().first;
            cache.erase(last);
            q.pop_back();
        }
        q.push_front(pair<int,int>(key, value));
        cache[key] = q.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
