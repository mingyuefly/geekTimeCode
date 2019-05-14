//
//  Graph.hpp
//  graph
//
//  Created by Gguomingyue on 2019/2/25.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>
#include <map>

class GraphVector {
public:
    int vector;
    int referCount; // 引用次数
    GraphVector();
    GraphVector(int vectorP);
    ~GraphVector();
};

GraphVector::GraphVector() {
    
}

GraphVector::GraphVector(int vectorP){
    vector = vectorP;
    referCount = 0;
}

GraphVector::~GraphVector(){
    cout << "~GraphVector()" << endl;
}

class Graph {
private:
    // 定义内部类边
    class Edge {
    public:
        GraphVector * sid; // 起点ID；
        GraphVector * tid; // 终点ID;
        int weight;   // 权重
        Edge(){
            cout << "Edge()" << endl;
        };
        Edge(GraphVector * sidp, GraphVector * tidp, int wp) {
            sid = sidp;
            sid->referCount++;
            tid = tidp;
            tid->referCount++;
            weight = wp;
            //cout << "Edge(GraphVector * sidp, GraphVector * tidp, int wp)" << endl;
        }
        ~Edge(){
            sid->referCount--;
            if (sid != NULL && sid->referCount == 0) {
                cout << sid->vector << endl;
                delete sid;
            }
            tid->referCount--;
            if (tid != NULL && tid->referCount == 0) {
                cout << tid->vector << endl;
                delete tid;
            }
            cout << "~Edge()" << endl;
        };
    };
    int v; // 顶点个数
    LinkedList<Edge> *adj[100];
    void printDistanceMap(map <int, int> distanceMap);
    void printprevMap(map <int, int> prevMap, GraphVector * startVector, GraphVector * endVector);
    void recurPrint(map <int, int> prevMap, int start, int end);
public:
    Graph();
    Graph(int vp);
    ~Graph();
    void show();
    void addEdge(GraphVector * s, GraphVector * t, int wp);
    void dijkstra(GraphVector * start);
};

Graph::Graph(){
    cout << "Graph()" << endl;
}
Graph::Graph(int vp){
    v = vp;
    for (int i = 0; i < vp; i++){
        LinkedList<Edge> * list = new LinkedList<Edge>();
        //list->add(new Edge(i));
        adj[i] = list;
    }
}
Graph::~Graph(){
    for (int i = 0; i < v; i++) {
        LinkedList<Edge> * list = adj[i];
        if (list != NULL) {
            delete list;
        }
    }
    cout << "~Graph()" << endl;
}

void Graph::addEdge(GraphVector * s, GraphVector * t, int wp){
    Edge * edge = new Edge(s, t, wp);
    adj[s->vector]->add(edge);
}

void Graph::show(){
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < adj[i]->size(); j++) {
            Edge *edge = adj[i]->get(j);
            cout << edge->sid->vector << "--" << edge->tid->vector << ":" << edge->weight << "  ";
        }
        cout << endl;
    }
}

void Graph::dijkstra(GraphVector * start)
{
    int max = 999999;
    // 创建距离start顶点的距离hash表
    map <int, int> distanceMap;
    for (int i = 0; i < v; i++) {
        distanceMap[i] = max;
    }
    for (int i = 0; i < adj[start->vector]->size(); i++) {
        Edge * edge = adj[start->vector]->get(i);
        distanceMap[edge->tid->vector] = edge->weight;
    }
    distanceMap[start->vector] = 0;
    //printDistanceMap(distanceMap);
    
    // 创建前置hash表
    map <int, int> prevMap;
    for (int i = 0; i < v; i++) {
        prevMap[i] = start->vector;
    }
    
    bool book[100] = {false};
    book[start->vector] = true;
    for (int i = 0; i < v; i++) {
        // 找到距离start顶点最近距离的点
        int min = max;
        int nearest = 0;
        for (int i = 0; i < v; i++) {
            if (i != start->vector && book[i] == false && distanceMap[i] < min) {
                min = distanceMap[i];
                nearest = i;
            }
        }
        book[nearest] = true;
        
        // 松弛
        for (int i = 0; i < adj[nearest]->size(); i++) {
            Edge * edge = adj[nearest]->get(i);
            if (edge->tid->vector != start->vector) {
                if (distanceMap[edge->tid->vector] > (distanceMap[nearest] + edge->weight)) {
                    distanceMap[edge->tid->vector] = distanceMap[nearest] + edge->weight;
                    prevMap[edge->tid->vector] = edge->sid->vector;
                }
            }
        }
        //printDistanceMap(distanceMap);
    }
    
    printDistanceMap(distanceMap);
    printprevMap(prevMap, start, new GraphVector(5));
}

void Graph::printDistanceMap(map <int, int> distanceMap)
{
    // 打印distanceMap
    for (int i = 0; i < v; i++) {
        cout << " " << distanceMap[i];
    }
    cout << endl;
}

void Graph::printprevMap(map <int, int> prevMap, GraphVector * startVector, GraphVector * endVector)
{
    // 打印prevMap
    for (int i = 0; i < v; i++) {
        cout << " " << prevMap[i];
    }
    cout << endl;
    recurPrint(prevMap, startVector->vector, endVector->vector);
    cout << " " << endVector->vector;
    cout << endl;
    
    delete endVector;
}

void Graph:: recurPrint(map <int, int> prevMap, int start, int end)
{
    if (end == start) {
        return;
    }
    recurPrint(prevMap, start, prevMap[end]);
    cout << " " << prevMap[end];
}


#endif /* Graph_hpp */
