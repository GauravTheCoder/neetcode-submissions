class MyHashSet {
    int numBuckets;
    std::vector<std::list<int>> buckets;
    int hash(int key) {
        return std::abs(key) % numBuckets;
    }
    public:
    MyHashSet() {
        numBuckets = 15013; // A prime number reduces collision rates
        buckets.resize(numBuckets);
    }
    
    void add(int key) {
        int index = hash(key);
        auto it = std::find(buckets[index].begin(), buckets[index].end(), key);
        if (it == buckets[index].end()) {
            buckets[index].push_back(key);
        }
    }
    
    void remove(int key) {
        int index = hash(key);
        auto it = std::find(buckets[index].begin(), buckets[index].end(), key);
        if (it != buckets[index].end()) {
            buckets[index].erase(it);
        }
    }
    
    bool contains(int key) {
        int index = hash(key);
        auto it = std::find(buckets[index].begin(), buckets[index].end(), key);
        return it != buckets[index].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */