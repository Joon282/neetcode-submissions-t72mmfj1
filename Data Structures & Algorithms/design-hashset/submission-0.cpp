class MyHashSet {
    private:
        struct ListNode {
        int key;
        ListNode* next;

        ListNode(int k, ListNode* n = nullptr)
            : key(k), next(n) {}
    };

    static const int SIZE = 1000;   
    std::vector<ListNode*> buckets;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        buckets.resize(SIZE, nullptr);
    }
    
    void add(int key) {
        int index = hash(key);
        ListNode* head = buckets[index];
        while (head){
            if (head->key == key){
                return;
            }
            head = head->next;
        }
        buckets[index] = new ListNode(key, buckets[index]);
    }
    
    void remove(int key) {
        int index = hash(key);
        if (!buckets[index]) return;
        if (buckets[index]->key == key) {
            ListNode* temp = buckets[index];
            buckets[index] = temp->next;
            delete temp;
            return;
        }
        ListNode* current = buckets[index];
        while (current->next) {
            if (current->next->key == key) {
                ListNode* temp = current->next;
                current->next = temp->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }
    
    bool contains(int key) {
        int index = hash(key);
        ListNode* head = buckets[index];
        while (head){
            if (head->key == key){
                return true;
            }
            head = head->next;
        }
        return false;
    }
};
