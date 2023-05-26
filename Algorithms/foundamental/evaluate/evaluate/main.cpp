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
    Evaluate(string str) {
        evaluateStr = str;
    }
    ~Evaluate() {
        cout << "~Evaluate()" << endl;
    }
    double compute() {
        if (evaluateStr.size() == 0) {
            return 0;
        }
        
        return 0;
    }
    double compute(string str) {
        string evaluateStr = str;
        trim(evaluateStr);
        if (evaluateStr.size() == 0) {
            return 0;
        }
        size_t size = evaluateStr.size();
        int index = 0;
        vector<char> verifyArray = {'(', '+', '-', '*', '/', ')'};
        string tmpString;
        stack<double> vals;
        stack<char> ops;
        while (index < size) {
            char s = evaluateStr[index];
            if (find(verifyArray.begin(), verifyArray.end(), s) != verifyArray.end()) {
                if (tmpString.size() > 0) {
//                    int num = stoi(tmpString);
                    double num = stod(tmpString);
                    vals.push(num);
                    tmpString = "";
                }
            }
            if (s == '(');
            else if (s == '+') ops.push(s);
            else if (s == '-') ops.push(s);
            else if (s == '*') ops.push(s);
            else if (s == '/') ops.push(s);
            else if (s == ')') {
                char s = ops.top();
                ops.pop();
                double v = vals.top();
                vals.pop();
                if (s == '+') v = vals.top() + v;
                else if (s == '-') v = vals.top() - v;
                else if (s == '*') v = vals.top() * v;
                else if (s == '/') v = vals.top() / v;
                vals.pop();
                vals.push(v);
            }
            else tmpString.push_back(s);
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
    
    string str = "(1.2 + ((2.3 * 3.4) * (4.5 * 5.6)))";
    Evaluate evaluate = Evaluate();
//    cout << evaluate.compute(str) << endl;
    cout << evaluate.compute(str) << endl;
    cout << 1.2 + ((2.3 * 3.4) * (4.5 * 5.6)) << endl;
    
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
