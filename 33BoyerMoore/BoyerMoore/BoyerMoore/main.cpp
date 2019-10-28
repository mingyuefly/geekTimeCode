//
//  main.cpp
//  BoyerMoore
//
//  Created by Gguomingyue on 2019/10/28.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>
#include "BoyerMoore.hpp"

int main(int argc, const char * argv[]) {
    
    //string txt = "abcacabdc";
    //string pattern = "abd";
    //string txt = "aaabaaabaaabaaaab";
    //string pattern = "aaaa";
    // 单纯使用坏字符不可行示例
    string txt = "aaaaaaaaaaaaaaaa";
    string pattern = "baaa";
    int match = boyerMoore(txt, pattern);
    if (match == txt.length()) {
        cout << "未匹配" << endl;
    } else {
        cout << match << "位匹配" << endl;
    }
    
    return 0;
}
