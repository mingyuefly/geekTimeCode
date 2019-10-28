//
//  main.cpp
//  bruteForce
//
//  Created by Gguomingyue on 2019/10/23.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>
#include "BruteForce.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    string txt = "abcdfEDfbabaedfjgkjgke";
    //string pattern = "baba";
    string pattern = "babaZ";
    int x = bruteForce(txt, pattern);
    cout << x << endl;
    
    return 0;
}
