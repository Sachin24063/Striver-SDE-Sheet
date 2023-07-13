class LRUCache {
public:

class node{
    public:
    int key;
    int val;
    node* next;
    node* prev;
   node(int key_, int val_){
       key = key_;
       val = val_;
   }
};

node *head = new node(-1,-1);
node *tail = new node(-1, -1);
 int cap;
 unordered_map<int,node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void insert_node(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void delete_node(node* delnode){
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_) {
        if(mp.find(key_) != mp.end()){
            node* resnode = mp[key_];
            int result = resnode->val;
            mp.erase(key_);
            delete_node(resnode);
            insert_node(resnode);
            mp[key_] = head->next;
            return result;
        }
        return -1;
    }
    
    void put(int key_, int value_) {
        if(mp.find(key_) != mp.end()){
            node *existingnode = mp[key_];
            mp.erase(key_);
            delete_node(existingnode);
        }
        if(mp.size() == cap){
            mp.erase(tail->prev->key);
            delete_node(tail->prev);
        }
        insert_node(new node(key_,value_));
        mp[key_] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
