//
//  main.cpp
//  evaluate
//
//  Created by gmy on 2023/5/26.
//

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Evaluate {
public:
    Evaluate() {
        
    }
//    Evaluate(string str) {
//        evaluateStr = str;
//    }
    ~Evaluate() {
        cout << "~Evaluate()" << endl;
    }
//    double compute() {
//        if (evaluateStr.size() == 0) {
//            return 0;
//        }
//
//        return 0;
//    }
    double compute(string str) {
        string evaluateStr = str;
        // 去除空格
        trim(evaluateStr);
        if (evaluateStr.size() == 0) {
            return 0;
        }
        
        size_t size = evaluateStr.size();
        int index = 0;
        vector<char> verifyArray = {'(', '+', '-', '*', '/', ')'};
        vector<char> verifyArray1 = {'s', 'q', 'r', 't'};
        string tmpString;
        string sqrtString;
        stack<double> vals;
        stack<string> ops;
        
        while (index < size) {
            char s1 = evaluateStr[index];
            string s;
            s.push_back(s1);
            
            // 将数字压栈
            if (find(verifyArray.begin(), verifyArray.end(), s1) != verifyArray.end()) {
                if (tmpString.size() > 0) {
//                    int num = stoi(tmpString);
                    double num = stod(tmpString);
                    vals.push(num);
                    tmpString = "";
                }
            }
            
            if (s == "(");
            else if (s == "+") ops.push(s);
            else if (s == "-") ops.push(s);
            else if (s == "*") ops.push(s);
            else if (s == "/") ops.push(s);
            else if (s == ")") {
                string s2 = ops.top();
                ops.pop();
                double v = vals.top();
                vals.pop();
                if (s2 == "+") v = vals.top() + v;
                else if (s2 == "-") {
                    v = vals.top() - v;
                    vals.pop();
                }
                else if (s2 == "*") {
                    v = vals.top() * v;
                    vals.pop();
                }
                else if (s2 == "/") {
                    v = vals.top() / v;
                    vals.pop();
                }
                else if (s2 == "sqrt") {
                    v = sqrt(v);
                }
                vals.push(v);
            }
            else if (find(verifyArray1.begin(), verifyArray1.end(), s1) != verifyArray1.end()) {
                // 将sqrt压栈
                sqrtString.push_back(s1);
                if (sqrtString.compare("sqrt") == 0) {
                    ops.push("sqrt");
                    sqrtString = "";
                }
            }
            else tmpString.push_back(s1);
//            else vals.push(int(s) - 48);
            index++;
        }
        cout << vals.top() << endl;
        return vals.top();
    }
private:
    string evaluateStr;
    void trim(string &s) {
        int index = 0;
        if(!s.empty()) {
            while((index = s.find(' ', index)) != string::npos) {
                s.erase(index, 1);
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Evaluate evaluate = Evaluate();
    
    string str = "(1.2 + ((2.3 * 3.4) * (4.5 * 5.6)))";
    cout << evaluate.compute(str) << endl;
    cout << 1.2 + ((2.3 * 3.4) * (4.5 * 5.6)) << endl;
    
    string str1 = "(1.2 + ((2.3 * 3.4) * sqrt(4.5)))";
    cout << evaluate.compute(str1) << endl;
    cout << 1.2 + ((2.3 * 3.4) * sqrt(4.5)) << endl;
    
    return 0;
}


//int main(int argc, const char * argv[]) {
//    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
//
//    for (const string& word : msg)
//    {
//        cout << word << " ";
//    }
//    cout << endl;
//    return 0;
//}
//
//
