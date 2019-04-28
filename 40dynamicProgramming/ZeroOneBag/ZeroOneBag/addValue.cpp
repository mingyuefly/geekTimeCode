//
//  addValue.cpp
//  ZeroOneBag
//
//  Created by Gguomingyue on 2019/2/14.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

static int weight[5] = {2, 2, 4, 6, 3};
//static int weight[5] = {2, 2, 4, 3, 6};
static int value[5] = {3, 4, 8, 9, 6};
static int n = 5;
static int w = 9;
static int times = 0;
static int states[5][10] = {-1};

void statesChangeObserve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            cout << states[i][j];
            if (states[i][j] >= 10) {
                cout << "  ";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }
}

int knapsack(int weight[], int value[], int n, int w) {
    states[0][0] = 0;
    states[0][weight[0]] = value[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= w; ++j) {
            if (states[i-1][j] >= 0) {
                states[i][j] = states[i-1][j];
                
                // 打印过程 **********/
                times++;
                cout << i << "+" << j << endl;
                statesChangeObserve();
                cout << endl;
                cout << times << endl;;
                // 打印过程 **********/
            }
        }
        for (int j = 0; j <= w-weight[i]; ++j) {
            if (states[i-1][j] >= 0) {
                int v = states[i-1][j] + value[i];
                if (v > states[i][j + weight[i]]) {
                    states[i][j + weight[i]] = v;
                }
                
                // 打印过程 **********/
                times++;
                cout << i << "+" << j << "+" << weight[i] << endl;
                statesChangeObserve();
                cout << endl;
                cout << times << endl;
                // 打印过程 **********/
            }
        }
    }
    
    int maxValue = -1;
    for (int i = 0; i <= w; ++i) {
        if (states[n-1][i] > maxValue) {
            maxValue = states[n-1][i];
        }
    }
    
    return maxValue;
}


int main(int argc, const char * argv[]) {
    
    int k = knapsack(weight, value, n, w);
    cout << "-------" << endl;
    cout << k << endl;
    statesChangeObserve();
    cout << endl << times << endl;
    
    return 0;
}
