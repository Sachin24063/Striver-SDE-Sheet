#include <bits/stdc++.h> 

class Trie {
    struct Node {
        Node* list[26];
        bool flag = false;
        int ew = 0;
        int cp = 0;

        bool containskey(char ch) {
            return list[ch - 'a'] != NULL;
        }

        void put(char ch, Node* node) {
            list[ch - 'a'] = node;
        }

        Node* get(char ch) {
            return list[ch - 'a'];
        }
    };

private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

void insert(string& word) {
    Node* node = root;
    for (int i = 0; i < word.size(); i++) {
        if (!node->containskey(word[i])) {
            node->put(word[i], new Node());
        } 
        node = node->get(word[i]);
        node->cp++;
    }
    node->ew += 1;
} 

int countWordsEqualTo(string& word) {
    Node* node = root;
    for (int i = 0; i < word.size(); i++) {
        if (node->containskey(word[i])) {
            node = node->get(word[i]);
        }
        else{
            return 0;
        }  
    }
    return node->ew;
}



    int countWordsStartingWith(string& word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (node->containskey(word[i])) {
                node = node->get(word[i]);
            }
            else{
                return 0; 
            }
        }
        return node->cp;
    }

void erase(string& word) {
    Node* node = root;
    for (int i = 0; i < word.size(); i++) {
        if (node->containskey(word[i])) {
            node = node->get(word[i]);
            node->cp--;
        }
        else{
            return;
        }
            node->ew--;
    }
}
};
