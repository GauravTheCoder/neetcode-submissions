class MyHashMap {
private:
    int numBuckets;
    // Each bucket stores a list of pairs (key, value)
    std::vector<std::list<std::pair<int, int>>> buckets;

    // Hash function to map key to a bucket index
    int hash(int key) {
        return std::abs(key) % numBuckets;
    }
public:
    MyHashMap() {
        numBuckets = 15013; // A prime number reduces collision rates
        buckets.resize(numBuckets);
    }
    
    void put(int key, int value) {
        int index = hash(key);
        for (auto& pair : buckets[index]) {
            if (pair.first == key) {
                pair.second = value; // Update existing key
                return;
            }
        }
        // Key not found, insert a new pair
        buckets[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);
        for (const auto& pair : buckets[index]) {
            if (pair.first == key) {
                return pair.second; // Key found
            }
        }
        return -1; // Key does not exist
    }
    
    void remove(int key) {
        int index = hash(key);
        auto& bucket = buckets[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->first == key) {
                bucket.erase(it); // Remove key-value pair
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */