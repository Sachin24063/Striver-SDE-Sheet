#include <bits/stdc++.h> 
struct Node{
    Node* list[26];
    bool flag = false;
    
    bool containskey(char ch){
        return list[ch - 'a'] != NULL;
    }
    
    Node* getkey(char ch){
        return list[ch - 'a'];
    }
    
    void push(char ch, Node* node){
        list[ch - 'a'] = node;
    }
};
class Trie{

private:
Node* root;

public:
    Trie(){
        root = new Node();
    }
    
    void insert(string word){
        Node* node = root;
        for(int i=0;i<word.size();i++){
            if(!node->containskey(word[i])){
                node->push(word[i], new Node());
            }
            node = node->getkey(word[i]);
        }
        node->flag = true;
    }
    
public:
    bool prefixexists(string word){
        Node* node = root;
        for(int i=0;i<word.size(); i++){
            if(!node->containskey(word[i])) return false;
            node = node->getkey(word[i]);
            if(node->flag == false) return false; 
        }
        return true;
    }  
};


string completeString(int n, vector<string> &a){
    Trie T;
    for(auto it: a){
        T.insert(it);
    }
    string longeststr = "";
    
    for(auto it: a){
        if(T.prefixexists(it)){
            if(it.size() > longeststr.size()) longeststr = it;
            
            else if(it.size() == longeststr.size()){
                if(it < longeststr) longeststr = it;
            }
        }
    }
    
    if(longeststr == "") return "None";
    return longeststr;
}
