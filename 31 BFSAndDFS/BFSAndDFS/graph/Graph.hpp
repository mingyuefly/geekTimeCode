//
//  Graph.hpp
//  graph
//
//  Created by Gguomingyue on 2019/2/25.
//  Copyright © 2019 Gmingyue. All rights reserved.
//  广度优先和深度优先的区别在于：用白话来说就是，广度是从起点开始往外查找紧邻的点，同时记录下来每个点的上一个点，直到找到目标点为止，深度优先就好像从起点开始下一步走向紧邻点，然后继续走，如果走不下去就返回上一步重新选择一个紧邻点，直到走到目标点为止，运用了回溯思想。

#ifndef Graph_hpp
#define Graph_hpp

#include <stdio.h>

class GraphVector {
public:
    int vector;
    int referCount;
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
    int v; // 顶点个数
    LinkedList<GraphVector> *adj[100];
    bool dfsFound;
public:
    Graph();
    Graph(int vp);
    ~Graph();
    void show();
    void addEdge(GraphVector * s, GraphVector * t);
    bool breadthFirstSearch(GraphVector * s, GraphVector * t);
    void print(GraphVector * prev[], GraphVector * s, GraphVector * t);
    void depthFirstSearch(GraphVector * s, GraphVector * t);
    void recurDFS(GraphVector * w, GraphVector * t, bool visited[], GraphVector * prev[]);
};

Graph::Graph(){
    dfsFound = false;
    cout << "Graph()" << endl;
}
Graph::Graph(int vp){
    dfsFound = false;
    v = vp;
    for (int i = 0; i < vp; i++) {
        LinkedList<GraphVector> * list = new LinkedList<GraphVector>();
        adj[i] = list;
    }
}
Graph::~Graph(){
    cout << endl;
    for (int i = 0; i < v; i++) {
        LinkedList<GraphVector> * list = adj[i];
        if (list != NULL && list->size() == 0) {
            delete list;
        } else {
            for (int j = 0; j < list->size(); j++) {
                GraphVector * vector = list->get(j);
                vector->referCount--;
                if (vector->referCount == 0) {
                    cout << vector->vector << endl;
                    delete vector;
                }
            }
        }
    }
    cout << "~Graph()" << endl;
}

void Graph::addEdge(GraphVector * s, GraphVector * t){
    LinkedList<GraphVector> * list = adj[s->vector];
    if (list->size() == 0) {
        adj[s->vector]->add(s);
        s->referCount++;
    }
    adj[s->vector]->add(t);
    //adj[t->vector]->add(s);
    t->referCount++;
    //s->referCount++;
}

void Graph::show(){
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < adj[i]->size(); j++) {
            if (j == adj[i]->size() - 1) {
                cout << adj[i]->get(j)->vector;
            } else {
                cout << adj[i]->get(j)->vector << "--";
            }
        }
        cout << endl;
    }
}

/*
 广度搜索其实就是一种“地毯式”层层推进的搜索策略，即先查找离起始顶点最近的，然后是次近的，依次往外搜索。
 */
bool Graph::breadthFirstSearch(GraphVector * s, GraphVector * t){
    if (s->vector == t->vector) {
        cout << s->vector << "和" << t->vector << "是同一个点。" << endl;
        return false;
    }
    
    // visited记录每个点是否被访问过，初始化为false
    bool visited[100] = {false};
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    
    // 初始化起始点被访问状态
    visited[s->vector] = true;
    LinkedList<GraphVector> * queue = new LinkedList<GraphVector>();
    queue->add(s);
    
    // prev记录依次被访问过的点，不过是反序的，初始为-1
    GraphVector * prev[100] = {};
    for (int i = 0; i < 100; i++) {
        GraphVector *vector = new GraphVector(-1);
        prev[i] = vector;
    }
    
    while (queue->size() != 0) {
        // 出队列的同时查找出队列的点所连接的点，这些点如果没有被访问过入队列
        GraphVector * w = queue->out();
        for (int i = 0; i < adj[w->vector]->size(); i++) {
            GraphVector * q = adj[w->vector]->get(i);
            if (!visited[q->vector]) {
                // 如果没被访问加入队列的同时记下来这个点的上一个点
                prev[q->vector]->vector = w->vector;
                if (q->vector == t->vector) {
                    // 若找到目标点则停止搜索
                    print(prev, s, t);
                    cout << endl;
                    return true;
                }
                visited[q->vector] = true;
                queue->add(q);
            }
        }
    }
    cout << "找不到" << s->vector << "到" << t->vector << "的路径。";
    return false;
}

void Graph::print(GraphVector * prev[], GraphVector * s, GraphVector * t){
    if (prev[t->vector]->vector != -1 && t->vector != s->vector) {
        print(prev, s, prev[t->vector]);
    }
    cout << t->vector << " ";
}

void Graph::depthFirstSearch(GraphVector *s, GraphVector *t){
    dfsFound = false;
    bool visited[100] = {false};
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    GraphVector * prev[100] = {};
    for (int i = 0; i < 100; i++) {
        GraphVector * vector = new GraphVector(-1);
        prev[i] = vector;
    }
    recurDFS(s, t, visited, prev);
    print(prev, s, t);
    cout << endl;
}

void Graph::recurDFS(GraphVector *w, GraphVector *t, bool visited[], GraphVector *prev[]){
    if (dfsFound == true) {
        return;
    }
    visited[w->vector] = true;
    if (w->vector == t->vector) {
        dfsFound = true;
        return;
    }
    for (int i = 0; i < adj[w->vector]->size(); i++) {
        GraphVector * q = adj[w->vector]->get(i);
        // 如果没被踩过就继续往下走
        if (!visited[q->vector]) {
            prev[q->vector] = w;
            recurDFS(q, t, visited, prev);
        }
    }
}



#endif /* Graph_hpp */
