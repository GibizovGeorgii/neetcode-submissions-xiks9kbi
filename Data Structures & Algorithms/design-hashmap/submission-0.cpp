class MyHashMap {
private:
    std::list<std::pair<int, int>> hashList;

public:
    MyHashMap() {
    }
    
    void put(int key, int value) {
        for (auto it = hashList.begin(); it != hashList.end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        hashList.push_back({key, value});
    }
    
    int get(int key) {
        for (auto it = hashList.begin(); it != hashList.end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        for (auto it = hashList.begin(); it != hashList.end(); ++it) {
            if (it->first == key) {
                hashList.erase(it);
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