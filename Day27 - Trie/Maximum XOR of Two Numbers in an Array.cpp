struct Node{
    Node* links[2];

    bool containskey(int bit){
        return links[bit] != NULL;
    }

    void insert(int bit, Node *node){
        links[bit] = node; 
    }

    Node* getkey(int bit){
        return links[bit];
    }
};
class Trie {
private:
    Node* root;
    public:
        Trie(){
             root = new Node();
        }

public:
void insert(int num){
    Node *node = root;
    for(int i=31; i>=0; i--){
        int bit = (num >> i) & 1;
        if(!node->containskey(bit)){
            node->insert(bit, new Node());
        }
        node = node->getkey(bit);
    }
}
public: 
int getmax(int num){
    Node *node = root;
    int maxnum = 0;
    for(int i=31; i>=0; i--){
        int bit = (num >> i) & 1;
        //now we have to search a opposite bit
        if(node->containskey(1-bit)){
            maxnum = maxnum | (1 << i);
            node = node->getkey(1-bit);
        }
        else{
             node = node->getkey(bit);
        }
    }
    return maxnum;
}
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie T;
        for(auto it: nums) T.insert(it);
        int maxi = 0;
        for(auto it: nums){
            maxi = max(maxi, T.getmax(it));
        }
        return maxi;
    }
};
