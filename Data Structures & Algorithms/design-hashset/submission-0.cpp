class MyHashSet {
private:
    int size = 0;
    std::list<int> keys;

public:
    MyHashSet() {
    }
    
    void add(int key) {
        for (int prob_key : keys) {
            if (key == prob_key) {
                return;
            }
        }
        keys.push_back(key);
    }
    
    void remove(int key) {
        for (auto it = keys.begin(); it != keys.end(); ++it) {
            if (*it == key) {
                keys.erase(it);
                return;
            }
        }
    }
    
    bool contains(int key) {
        for (int prob_key : keys) {
            if (prob_key == key) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */