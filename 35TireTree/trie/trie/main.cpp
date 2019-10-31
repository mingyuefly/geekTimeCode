//
//  main.cpp
//  trie
//
//  Created by Gguomingyue on 2019/10/30.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>
#include "Trie.hpp"

int main(int argc, const char * argv[]) {
    
    Trie *trie = new Trie();
    trie->insert("apple");
    trie->insert("pear");
    trie->insert("desk");
    trie->insert("watch");
    trie->insert("doctor");
    trie->insert("booknote");
    //string txt = "pear";
    //string txt = "booknote";
    //string txt = "watch";
    string txt = "box";
    if (trie->find(txt)) {
        cout << txt << "查找到" << endl;
    } else {
        cout << txt << "未查到" << endl;
    }
    trie->insert(txt);
    if (trie->find(txt)) {
        cout << txt << "查找到" << endl;
    } else {
        cout << txt << "未查到" << endl;
    }
    
    delete trie;
    
    return 0;
}
