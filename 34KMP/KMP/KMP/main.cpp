//
//  main.cpp
//  KMP
//
//  Created by Gguomingyue on 2019/10/29.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>
#include "KMP.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    //string txt = "abcacabdc";
    //string pattern = "abd";
    
    //string txt = "aaabaaabaaabaaaab";
    //string pattern = "aaaa";
    
    //string txt = "abcacabcbcbacabc";
    //string txt = "abcacabcbcabccabc";
    //string txt = "abcadjffdkfjcabcabcabccabc";
    //string pattern = "cabcab";
    // 单纯使用坏字符不可行示例
    //string txt = "aaaaaaaaaabaaaaaa";
    //string pattern = "baaa";
    
    //string txt = "ababaeabacjiwoitoi";
    string txt = "ababaeabacjiwoiababacdtoi";
    string pattern = "ababacd";
    int match = kmp(txt, pattern);
    if (match == txt.length()) {
        cout << "未匹配" << endl;
    } else {
        cout << match << "位匹配" << endl;
    }
    return 0;
}
