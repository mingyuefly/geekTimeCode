//
//  Trie.hpp
//  trie
//
//  Created by Gguomingyue on 2019/10/30.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef Trie_hpp
#define Trie_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Trie {
        
public:
    class TrieNode {
        
    public:
        char data;
        TrieNode *children[26];
        bool isEndingChar;
        TrieNode(char dataP) {
            data = dataP;
            isEndingChar = false;
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
        }
        ~TrieNode() {
            cout << "~TrieNode()  " << data << endl;
        }
    };
    TrieNode *root;
    ~Trie();
    void deleteNode(TrieNode *node);//删除所有节点
    Trie();
    void insert(string txt);
    bool find(string txt);
};

Trie::Trie()
{
    root = new TrieNode('\\');
}

Trie::~Trie()
{
    cout << "~Trie() begin" << endl;
    Trie::deleteNode(root);
    cout << "~Trie()" << endl;
}

void Trie::deleteNode(TrieNode *node) {
    for (int i = 0; i < 26; i++) {
        TrieNode *pi = node->children[i];
        if (pi != NULL) {
            deleteNode(pi);
            delete pi;
            node->children[i] = NULL;
        }
    }
}

void Trie::insert(string txt)
{
    int length = (int)txt.length();
    TrieNode *p = root;
    for (int i = 0; i < length; i++) {
        char ch = txt.at(i);
        int index = ch - 'a';
        if (p->children[index] == NULL) {
            p->children[index] = new TrieNode(ch);
        }
        p = p->children[index];
    }
    p->isEndingChar = true;
}

bool Trie::find(string txt)
{
    int length = (int)txt.length();
    TrieNode *p = root;
    for (int i = 0; i < length; i++) {
        char ch = txt.at(i);
        int index = ch - 'a';
        if (p->children[index] == NULL) {
            return false;
        } else {
            p = p->children[index];
        }
    }
    if (p->isEndingChar) {
        return true;
    }
    return false;
}




#endif /* Trie_hpp */
