//
//  main.cpp
//  arithmetic
//
//  Created by gmy on 2023/5/29.
//

#include <iostream>

using namespace std;

class Arithmetic {
public:
    Arithmetic() {
        
    }
    ~Arithmetic() {
        cout << "~Arithmetic()" << endl;
    }
    int add(int a, int b) {
        int sum = a ^ b;
        int carry = (a & b) << 1;
        while (carry != 0) { // 当进位为 0 时跳出
            int tmpSum = sum;
            int tmpCarry = carry;
            sum = tmpSum ^ tmpCarry; // sum = 非进位和(对应位的和)
            carry = (tmpSum & tmpCarry) << 1;
        }
        return sum;
    }
    int subtractionubtraction(int a, int b) {
        return add(a, add(~b, 1));
    }
    int mutiply1(int a, int b) {
        // 取绝对值
        int mutiplicand = abs(a);
        int mutiplier = abs(b);
        int product = 0;
        int count = 0;
        while (count < mutiplier) {
            product = add(product, mutiplicand);
            count = add(count, 1);
        }
        if ((a ^ b) < 0) {
            product = add(~product, 1);
        }
        return product;
    }
    int mutiply2(int a, int b) {
        // 取绝对值
        int mutiplicand = abs(a);
        int mutiplier = abs(b);
        int product = 0;
        
        while (mutiplier > 0) {
            if ((mutiplier & 0x1) > 0) {
                product = add(product, mutiplicand);
            }
            mutiplicand <<= 1;
            mutiplier >>= 1;
        }
        if ((a ^ b) < 0) {
            product = add(~product, 1);
        }
        return product;
    }
    int division1(int a, int b) {
        if (b == 0) {
            return 0;
        }
        bool flag = true;
        if ((a ^ b) < 0) {
            flag = false;
        }
        // 取绝对值
        a = abs(a);
        b = abs(b);
        int count = 0;
        while (a >= b) {
            a = subtractionubtraction(a, b);
            count = add(count, 1);
        }
        if (!flag) {
            count = add(~count, 1);
        }
        return count;
    }
    int division2(int a, int b) {
        if (b == 0) {
            return 0;
        }
        bool flag = true;
        if ((a ^ b) < 0) {
            flag = false;
        }
        // 取绝对值
        int dividend = abs(a);
        int divisor = abs(b);
        int i = 31;
        int ans = 0;
        while (i >= 0) {
            if ((dividend >> i) >= divisor) {
                ans = add(ans, 1 << i);
                dividend = subtractionubtraction(dividend, divisor << i);
            }
            i = subtractionubtraction(i, 1);
        }
        
        if (!flag) {
            ans = add(~ans, 1);
        }
        return ans;
    }
    int abs(int a) {
        return a < 0 ? add(~a, 1) : a;
    }
};

int main(int argc, const char * argv[]) {
    Arithmetic arithmetic;
    cout << arithmetic.add(9, 3) << endl;
    
    cout << arithmetic.subtractionubtraction(9, 3) << endl;
    
    cout << arithmetic.mutiply1(3, 5) << endl;
    cout << arithmetic.mutiply1(3, -4) << endl;
    cout << arithmetic.mutiply2(3, 5) << endl;
    cout << arithmetic.mutiply2(3, -4) << endl;
    
    cout << arithmetic.division1(18, 6) << endl;
    cout << arithmetic.division1(18, -6) << endl;
    cout << arithmetic.division2(18, 6) << endl;
    cout << arithmetic.division2(18, -6) << endl;
    
    return 0;
}
