//
//  main.cpp
//  graph
//
//  Created by Gguomingyue on 2019/2/21.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>

#include "LinkedList.hpp"
#include "Graph.hpp"

using namespace std;

int main(int argc, const char * argv[]) {

    /***       **
    0——1——2       0--1--3
    |  |  |       1--0--2--4
    3——4——5       2--1--5
       |  |       3--0--4
       6——7       4--1--3--5--6
                  5--2--4--7
                  6--4--7
                  7--5--6
    ***       **/
    
    int num = 8;
    // 初始化无向图
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
    graph->addEdge(vector0, vector3); // 0--3
    graph->addEdge(vector1, vector2); // 1--2
    graph->addEdge(vector1, vector4); // 1--4
    graph->addEdge(vector2, vector5); // 2--5
    graph->addEdge(vector3, vector4); // 3--4
    graph->addEdge(vector4, vector5); // 4--5
    graph->addEdge(vector4, vector6); // 4--6
    graph->addEdge(vector5, vector7); // 5--7
    graph->addEdge(vector6, vector7); // 6--7
    
    graph->show();
    
    graph->breadthFirstSearch(vector0, vector7);
    
    graph->depthFirstSearch(vector0, vector7);
    
    delete graph;
    
    return 0;
}
