#include<bits/stdc++.h>
struct Node{
    Node* list[26];

    bool containskey(char ch){
    return list[ch - 'a'] != NULL;
}

void push(char ch, Node* node){
    list[ch - 'a'] = node;
}

Node* getkey(char ch){
    return list[ch - 'a'];
}

};

class Trie{
private:
Node* root;

public:
    Trie(){
        root = new Node();
    }

public:
int insert(string word){
        int cnt = 0;
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->push(word[i], new Node());
                cnt ++;
            }
            node= node->getkey(word[i]);
        }
        return cnt;
    }  
};
int countDistinctSubstrings(string &s)
{
   Trie T;
   int n = s.size();
   int count = 0;
   for(int i=0;i<n;i++){
       count += T.insert(s.substr(i, n-i));
   }
   return count+1;
}
