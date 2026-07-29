class MyHashMap {

private:
    struct Node{
        int key;
        int value;
        Node* next;
        
        Node(int key, int value, Node* next): key(key), value(value), next(nullptr) {}
    };
    static const int SIZE = 1000;   
    std::vector<Node*> buckets;
public:
    MyHashMap() {
        buckets.resize(SIZE, nullptr);
    }
    int gethash(int key) {
        return key % SIZE;
    }

    void put(int key, int value) {
        int hash = gethash(key);
        Node* curr = buckets[hash];
        while (curr){
            if (curr->key == key){
                curr->value = value;
                return;
            } 
            curr = curr->next;
        }
        buckets[hash] = new Node(key, value, buckets[hash]);
    }
    
    int get(int key) {
        int hash = gethash(key);
        Node* curr = buckets[hash];
        while (curr){
            if (curr->key == key){
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int hash = gethash(key);
        Node* curr = buckets[hash];
        if (!curr){
            return;
        }
        if (curr->key == key) {                      
            buckets[hash] = curr->next;
            delete curr;
            return;
        }
        while (curr->next){
            if (curr->next->key == key){
                Node* toDelete = curr->next;
                curr->next = toDelete->next;
                delete toDelete;
                return;
            }
            curr = curr->next;
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