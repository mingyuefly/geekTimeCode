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
        if (evaluateStr.size() == 0) {
            return 0;
        }
        size_t size = evaluateStr.size();
        int index = 0;
        stack<int> vals;
        stack<char> ops;
        while (index < size) {
            char s = evaluateStr[index];
            if (s == '(');
            else if (s == ' ');
            else if (s == '+') ops.push(s);
            else if (s == '-') ops.push(s);
            else if (s == '*') ops.push(s);
            else if (s == '/') ops.push(s);
            else if (s == ')') {
                char s = ops.top();
                ops.pop();
                int v = vals.top();
                vals.pop();
                if (s == '+') v = vals.top() + v;
                else if (s == '-') v = vals.top() - v;
                else if (s == '*') v = vals.top() * v;
                else if (s == '/') v = vals.top() / v;
                vals.pop();
                vals.push(v);
            }
            else vals.push(int(s) - 48);
            index++;
        }
        return vals.top();
    }
private:
    string evaluateStr;
};

int main(int argc, const char * argv[]) {
    
    string str = "(1 + ((2 * 3) * (4 * 5)))";
    Evaluate evaluate = Evaluate();
    cout << evaluate.compute(str) << endl;
    
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
