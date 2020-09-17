//
//  main.cpp
//  eightQueens
//
//  Created by Gguomingyue on 2019/1/25.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>

using namespace std;
//static int gEightQueen[8] = { 0 }, gCount = 0;
//void print()//输出每一种情况下棋盘中皇后的摆放情况
//{
//    for (int i = 0; i < 8; i++)
//    {
//        int inner;
//        for (inner = 0; inner < gEightQueen[i]; inner++)
//            cout << "0";
//        cout <<"#";
//        for (inner = gEightQueen[i] + 1; inner < 8; inner++)
//            cout << "0";
//        cout << endl;
//    }
//    cout << "==========================\n";
//}
//int check_pos_valid(int loop, int value)//检查是否存在有多个皇后在同一行/列/对角线的情况
//{
//    int index;
//    int data;
//    for (index = 0; index < loop; index++)
//    {
//        data = gEightQueen[index];
//        if (value == data)
//            return 0;
//        if ((index + data) == (loop + value))
//            return 0;
//        if ((index - data) == (loop - value))
//            return 0;
//    }
//    return 1;
//}
//void eight_queen(int index)
//{
//    int loop;
//    for (loop = 0; loop < 8; loop++)
//    {
//        if (check_pos_valid(index, loop))
//        {
//            gEightQueen[index] = loop;
//            if (7 == index)
//            {
//                gCount++; print();
//                gEightQueen[index] = 0;
//                return;
//            }
//            eight_queen(index + 1);
//            gEightQueen[index] = 0;
//        }
//    }
//}




static int result[8] = { 0 }, gCount = 0, times = 0;
void print()//输出每一种情况下棋盘中皇后的摆放情况
{
    cout << endl;
    for (int row = 0; row < 8; row++) {
        for (int column = 0; column < 8; column++) {
            if (result[row] == column) {
                cout << "Q";
            } else {
                cout << "#";
            }
        }
        cout << endl;
    }
    cout << "==========================\n";
}
int check_pos_valid(int row, int column)//检查是否存在有多个皇后在同一行/列/对角线的情况
{
    int leftup = column - 1, rightup = column + 1;
    for (int i = row - 1; i >= 0; --i) {
        times++;
        // 判断竖线上方
        if (result[i] == column) return false;
        // 判断左上角
        if (leftup >= 0) {
            if (result[i] == leftup) return false;
        }
        // 判断右上角
        if (rightup >= 0) {
            if (result[i] == rightup) return false;
        }
        --leftup; ++rightup;
    }
    return true;
}
void eight_queen(int row)
{
    if (row == 8) {
        gCount++;
        print();
        return;
    }
    for (int column = 0; column < 8; ++column) {
        if (check_pos_valid(row, column)) {
            result[row] = column;
            cout << column;
            eight_queen(row+1);
        }
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    eight_queen(0);
    cout << "total=" << gCount << endl;
    cout << "times=" << times << endl;
    return 0;
}
