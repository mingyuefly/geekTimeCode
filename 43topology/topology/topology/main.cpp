//
//  main.cpp
//  topology
//
//  Created by Gguomingyue on 2019/2/26.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>

#include "LinkedList.hpp"
#include "Graph.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    /***       **
           0->1
           0->2
           1->2
           1->3
           4->2
           5->6
           5->7
     ***       **/
    
    int num = 8;
    // 初始化有向图
    Graph *graph = new Graph(num);
    // 初始化各个节点
    GraphVector *vector0 = new GraphVector(0);
    GraphVector *vector1 = new GraphVector(1);
    GraphVector *vector2 = new GraphVector(2);
    GraphVector *vector3 = new GraphVector(3);
    GraphVector *vector4 = new GraphVector(4);
    GraphVector *vector5 = new GraphVector(5);
    GraphVector *vector6 = new GraphVector(6);
    GraphVector *vector7 = new GraphVector(7);
    // 添加各个节点
    graph->addEdge(vector0, vector1); // 0--1
    graph->addEdge(vector0, vector2); // 0--2
    graph->addEdge(vector1, vector2); // 1--2
    graph->addEdge(vector1, vector3); // 1--3
    graph->addEdge(vector4, vector2); // 4--2
    graph->addEdge(vector5, vector6); // 5--6
    graph->addEdge(vector5, vector7); // 5--7
    
    graph->show();
    cout << endl;
    
    graph->topoSortByKahn();
    //graph->printTopo();
    
    graph->topoSortByDFS();
    cout << endl;
    
    delete graph;
    
    return 0;
}
