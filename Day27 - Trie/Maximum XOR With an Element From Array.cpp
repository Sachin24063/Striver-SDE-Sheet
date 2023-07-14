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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie T;
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int,int>>>offlinequesries;
        int idx=0;
        for(auto it: queries){
            offlinequesries.push_back({it[1],{it[0], idx}});
            idx++;
        }
        sort(offlinequesries.begin(), offlinequesries.end());
        vector<int>ans(queries.size(),0);
        int ind = 0;
        int n = nums.size();
        for(auto it: offlinequesries){
             int mi = it.first;
             int xi = it.second.first;
             int qindex = it.second.second;
             while(ind < n && nums[ind] <= mi){
                 T.insert(nums[ind]);
                 ind++;
             }
             if(ind == 0) ans[qindex] = -1;
             else ans[qindex] = T.getmax(xi);
        }
        return ans;
    }
};
