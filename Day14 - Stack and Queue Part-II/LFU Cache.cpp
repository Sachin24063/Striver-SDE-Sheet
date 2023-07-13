struct Node {
    int key, value, freq;
    Node* next;
    Node* prev;

    Node(int key_, int val_) {
        key = key_;
        value = val_;
        freq = 1;
    }
};

class LFUCache {
    std::unordered_map<int, Node*> keynode;
    std::unordered_map<int, std::list<Node*>> freq_list_map;
    int max_sizecache;
    int min_freq;
    int curr_size;

public:
    LFUCache(int capacity) {
        max_sizecache = capacity;
        min_freq = 0;
        curr_size = 0;
    }

    void update_freq(Node* node) {
        auto& freq_list = freq_list_map[node->freq];
        freq_list.erase(std::find(freq_list.begin(), freq_list.end(), node));

        if (node->freq == min_freq && freq_list.empty()) {
            min_freq++;
        }

        node->freq += 1;
        freq_list_map[node->freq].push_front(node);
        keynode[node->key] = node;
    }

    int get(int key) {
        if (keynode.find(key) != keynode.end()) {
            Node* node = keynode[key];
            int val = node->value;
            update_freq(node);
            return val;
        }
        return -1; // Key not found
    }

    void put(int key, int value) {
        if (max_sizecache == 0) return;

        if (keynode.find(key) != keynode.end()) {
            Node* node = keynode[key];
            node->value = value;
            update_freq(node);
        } else {
            if (curr_size == max_sizecache) {
                auto& freq_list = freq_list_map[min_freq];
                Node* lastNode = freq_list.back();
                keynode.erase(lastNode->key);
                freq_list.pop_back();
                curr_size--;
            }
            curr_size++;

            min_freq = 1;
            freq_list_map[min_freq].push_front(new Node(key, value));
            keynode[key] = freq_list_map[min_freq].front();
        }
    }
};
