/*
Linked List Algorithm
1. Data Structures
- A hash map cache that maps key -> node.
- A doubly linked list with:
- left dummy: before the least recently used node.
- right dummy: after the most recently used node.
2. Helper: remove(node)
- Unlink node from the list by connecting its prev and next nodes.
3. Helper: insert(node)
- Insert node just before right (mark as most recently used).
4. get(key)
- If key not in cache, return -1.
- Otherwise:
- Remove its node from the list.
- Insert it again near right (mark as recently used).
- Return the node's value.
5. put(key, value)
- If key already exists:
- Remove its old node from the list.
- Create or update the node and store it in cache[key].
- Insert the node near right.
- If len(cache) > capacity:
- Take the node right after left (this is LRU).
- Remove it from the list.
- Delete its key from the hash map.
This way, both get and put run in O(1) time, and the LRU policy is always maintained.
*/

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
