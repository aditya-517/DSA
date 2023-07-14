/*
T.C : 

Insert = O(n)
Searching = O(n) 

Where, n = length of word

*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public: 
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word){
        // base case
        if(word.size() == 0){
            root->isTerminal = true;
            return;
        }
        
        int index = word[0] - 'A';      // assume word is ALL CAPS
        TrieNode* child;

        // if present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            // absent
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertUtil(child, word.substr(1));
    }

    bool searchUtil(TrieNode* root, string word){
        // base case
        if(word.size() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        // char present
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child, word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root, word);
    }

    bool search(string word){
        return searchUtil(root, word);
    }

};

int main()  
{ 
    Trie *t = new Trie();
    t->insertWord("ABCD");
    t->insertWord("ADITYA");
    t->insertWord("ADI");

    cout<<t->search("ABC")<<endl;
    cout<<t->search("ADITYA")<<endl;
    cout<<t->search("ADI")<<endl;
    return 0;
}
