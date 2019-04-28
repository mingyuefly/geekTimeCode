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
public:
    Graph();
    Graph(int vp);
    ~Graph();
    void show();
    void addEdge(GraphVector * s, GraphVector * t, int wp);
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


#endif /* Graph_hpp */
