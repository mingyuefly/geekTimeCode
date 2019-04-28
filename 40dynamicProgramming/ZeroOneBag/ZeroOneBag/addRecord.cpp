//
//  addRecord.cpp
//  ZeroOneBag
//
//  Created by Gguomingyue on 2019/2/14.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;

//static int maxW = 0;
//static int weight[5] = {2, 2, 4, 6, 3};
static int weight[5] = {2, 2, 4, 5, 3};
static int n = 5;
static int w = 9;
static int times = 0;
static bool states[5][10] = {false};

void statesChangeObserve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            cout << states[i][j] << " ";
        }
        cout << endl;
    }
}

int knapsack(int weight[], int n, int w) {
    states[0][0] = true;
    states[0][weight[0]] = true;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= w; j++) {// 不把第 i 个物品放入背包
            if (states[i-1][j] == true) {// 这个判断在于基于上一行的状态如果选择不放入那就说明状态一致
                
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
        for (int j = 0; j <= w - weight[i]; j++) {// 把第 i 个物品放入背包
            if (states[i-1][j] == true) {// 这个判断在于基于上一行的状态如果选择放入后状态一致
                
                states[i][j+weight[i]] = states[i-1][j];
                
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
    
    int j;
    for (j = w; j >= 0; --j) {// 输出结果
        if (states[n-1][j] == true) {
            break;
            //return j;
        }
    }
    
    for (int i = n-1; i >= 0; --i) {
        if (j - weight[i] >= 0 && states[i-1][j-weight[i]] == true) {
            cout << "i=" << i << " " << "w=" << weight[i] << " ";
            j = j - weight[i];
        }
    }
    cout << endl;
    
    return j;
}

int main(int argc, const char * argv[]) {
    
    int k = knapsack(weight, n, w);
    cout << "-------" << endl;
    cout << k << endl;
    statesChangeObserve();
    cout << endl << times << endl;
    
    return 0;
}
