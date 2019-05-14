//
//  main.cpp
//  shortestPath
//
//  Created by Gguomingyue on 2019/2/27.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>

#include "LinkedList.hpp"
#include "Graph.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    /*
     0--1:10  0--4:15
     1--0:10  1--2:15  1--3:2
     2--1:15  2--3:1   2--5:5
     3--5:12  3--1:2   3--2:1
     4--0:15  4--5:10
     5--2:5   5--4:10  5--3:12
     */
    int num = 6;
    // 初始化有向无权图
    Graph *graph = new Graph(num);
    // 初始化各个节点
    GraphVector *vector0 = new GraphVector(0);
    GraphVector *vector1 = new GraphVector(1);
    GraphVector *vector2 = new GraphVector(2);
    GraphVector *vector3 = new GraphVector(3);
    GraphVector *vector4 = new GraphVector(4);
    GraphVector *vector5 = new GraphVector(5);
    //添加边
    graph->addEdge(vector0, vector1, 10);
    graph->addEdge(vector0, vector4, 15);
    graph->addEdge(vector1, vector0, 10);
    graph->addEdge(vector1, vector2, 15);
    graph->addEdge(vector1, vector3, 2);
    graph->addEdge(vector2, vector1, 15);
    graph->addEdge(vector2, vector3, 1);
    graph->addEdge(vector2, vector5, 5);
    graph->addEdge(vector3, vector1, 2);
    graph->addEdge(vector3, vector2, 1);
    graph->addEdge(vector3, vector5, 12);
    graph->addEdge(vector4, vector0, 15);
    graph->addEdge(vector4, vector5, 10);
    graph->addEdge(vector5, vector2, 5);
    graph->addEdge(vector5, vector3, 12);
    graph->addEdge(vector5, vector4, 10);
//    //添加边
//    graph->addEdge(new GraphVector(0), new GraphVector(1), 10);
//    graph->addEdge(new GraphVector(0), new GraphVector(4), 15);
//    graph->addEdge(new GraphVector(1), new GraphVector(0), 10);
//    graph->addEdge(new GraphVector(1), new GraphVector(2), 15);
//    graph->addEdge(new GraphVector(1), new GraphVector(3), 2);
//    graph->addEdge(new GraphVector(2), new GraphVector(1), 15);
//    graph->addEdge(new GraphVector(2), new GraphVector(3), 1);
//    graph->addEdge(new GraphVector(2), new GraphVector(5), 5);
//    graph->addEdge(new GraphVector(3), new GraphVector(1), 2);
//    graph->addEdge(new GraphVector(3), new GraphVector(2), 1);
//    graph->addEdge(new GraphVector(3), new GraphVector(5), 12);
//    graph->addEdge(new GraphVector(4), new GraphVector(0), 15);
//    graph->addEdge(new GraphVector(4), new GraphVector(5), 10);
//    graph->addEdge(new GraphVector(5), new GraphVector(2), 5);
//    graph->addEdge(new GraphVector(5), new GraphVector(3), 12);
//    graph->addEdge(new GraphVector(5), new GraphVector(4), 10);
    
    graph->show();
    
    graph->dijkstra(vector0);
    graph->dijkstra(vector1);
    
    
    delete graph;
    
    return 0;
}
