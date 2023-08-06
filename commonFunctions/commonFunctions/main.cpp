//
//  main.cpp
//  commonFunctions
//
//  Created by gmy on 2023/7/28.
//

#include <iostream>
#include <vector>

using namespace std;

// to_string保留两位有效数字
auto formatDobleValue(double val, int fixed) {
    auto str = std::to_string(val);
    return str.substr(0, str.find(".") + fixed + 1);
}

// 分割字符串
vector<string> split(string s, char delim) {
    vector<string> ans;
    string cur;
    for(char ch: s) {
        if (ch == delim) {
            ans.push_back(std::move(cur));
            cur.clear();
        } else {
            cur += ch;
        }
    }
    ans.push_back(std::move(cur));
    return ans;
}

// 翻转字符串
string reverseString(string &str) {
    string str1 = string(str);
    size_t length = str1.length();
    size_t l = 0, r = length - 1;
    while (l <= r) {
        swap(str1[l], str1[r]);
        l++;
        r--;
    }
    return str1;
}

int main(int argc, const char * argv[]) {
    
    vector<string> strings = split("hello world", ' '); 
    for(auto str : strings) {
        cout << str << endl;
    }
    
    return 0;
}
