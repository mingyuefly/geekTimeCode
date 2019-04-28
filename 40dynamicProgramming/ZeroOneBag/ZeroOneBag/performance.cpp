//
//  performance.cpp
//  ZeroOneBag
//
//  Created by Gguomingyue on 2019/2/13.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

static int weight[5] = {2, 2, 4, 6, 3};
static int n = 5;
static int w = 9;
static int times = 0;
static bool states[10] = {false};

void statesChangeObserve() {
    for (int i = 0; i <= w; i++) {
        cout << states[i] << " ";
    }
    cout << endl;
}

int knapsack(int weight[], int n, int w) {
    states[0] = true;
    states[weight[0]] = true;
    for (int i = 0; i < n; ++i) {
        for (int j = w - weight[i]; j >= 0; --j) {//把第i个物体放入背包
            if (states[j] == true) {
                states[j + weight[i]] = true;
                
                // 打印过程 **********/
                times++;
                cout << i << "+" << j << endl;
                statesChangeObserve();
                cout << endl;
                cout << times << endl;;
                // 打印过程 **********/
            }
        }
    }
    for (int i = w; i >= 0; --i) {
        if (states[i] == true) {
            return i;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int k = knapsack(weight, n, w);
    cout << "-------" << endl;
    cout << k << endl;
    statesChangeObserve();
    cout << endl << times << endl;
    
    return 0;
}

