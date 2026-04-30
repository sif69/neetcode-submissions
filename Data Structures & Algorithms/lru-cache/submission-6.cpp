class LRUCache {
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int capacity;

    // helper: move key to most-recent (back of list)
    void touch(int key) {
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) return -1;
        touch(key);
        return cache[key].first;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            touch(key);              // existing key → refresh position
        } else {
            if ((int)cache.size() == capacity) {
                cache.erase(order.front());  // evict LRU
                order.pop_front();
            }
            order.push_back(key);
            cache[key].second = --order.end();
        }
        cache[key].first = value;    // update value in both cases
    }
};