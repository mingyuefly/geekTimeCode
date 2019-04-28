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
    GraphVector();
    GraphVector(int vectorP);
    ~GraphVector();
};

GraphVector::GraphVector() {
    
}

GraphVector::GraphVector(int vectorP){
    vector = vectorP;
}

GraphVector::~GraphVector(){
    cout << "~GraphVector()" << endl;
}

class Graph {
private:
    int v; // 顶点个数
    LinkedList<GraphVector> *adj[100];
    bool dfsFound;
    LinkedList<GraphVector> * topoQueue;
public:
    Graph();
    Graph(int vp);
    ~Graph();
    void show();
    void addEdge(GraphVector * s, GraphVector * t);
    void breadthFirstSearch(GraphVector * s, GraphVector * t);
    void print(GraphVector * prev[], GraphVector * s, GraphVector * t);
    void depthFirstSearch(GraphVector * s, GraphVector * t);
    void recurDFS(GraphVector * w, GraphVector * t, bool visited[], GraphVector * prev[]);
    void topoSortByKahn();
    void printTopo();
    void topoSortByDFS();
    void recurDFStopSort(int vertex, LinkedList<GraphVector> * inverseAdj[], bool visited[]);
};

Graph::Graph(){
    dfsFound = false;
    cout << "Graph()" << endl;
}
Graph::Graph(int vp){
    dfsFound = false;
    v = vp;
    for (int i = 0; i < vp; i++){
        LinkedList<GraphVector> * list = new LinkedList<GraphVector>();
        list->add(new GraphVector(i));
        adj[i] = list;
    }
}
Graph::~Graph(){
    for (int i = 0; i < v; i++) {
        LinkedList<GraphVector> * list = adj[i];
        if (list != NULL) {
            //delete list;
        }
    }
    cout << "~Graph()" << endl;
}

void Graph::addEdge(GraphVector * s, GraphVector * t){
    adj[s->vector]->add(t);
    //adj[t->vector]->add(s);
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

void Graph::breadthFirstSearch(GraphVector * s, GraphVector * t){
    if (s->vector == t->vector) {
        return;
    }
    bool visited[100] = {false};
    for (int i = 0; i < v; i++) {
        visited[i] = false;
    }
    visited[s->vector] = true;
    LinkedList<GraphVector> * queue = new LinkedList<GraphVector>();
    queue->add(s);
    GraphVector * prev[100] = {};
    for (int i = 0; i < 100; i++) {
        GraphVector *vector = new GraphVector(-1);
        prev[i] = vector;
    }
    while (queue->size() != 0) {
        GraphVector * w = queue->out();
        for (int i = 0; i < adj[w->vector]->size(); i++) {
            GraphVector * q = adj[w->vector]->get(i);
            if (!visited[q->vector]) {
                prev[q->vector]->vector = w->vector;
                if (q->vector == t->vector) {
                    print(prev, s, t);
                    cout << endl;
                    return;
                }
                visited[q->vector] = true;
                queue->add(q);
            }
        }
    }
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
        if (!visited[q->vector]) {
            prev[q->vector] = w;
            recurDFS(q, t, visited, prev);
        }
    }
}

void Graph::topoSortByKahn(){
    // 统计每个顶点入度
    int inDegree[100] = {0};
    for (int i = 0; i < v; i++) {
        for (int j = 1; j < adj[i]->size(); j++) {
            GraphVector * w = adj[i]->get(j);
            inDegree[w->vector]++;
        }
    }
    
    // 打印每个顶点入度
    for (int i = 0; i < v; i++) {
        cout << inDegree[i] << " ";
    }
    cout << endl;
    
    LinkedList<GraphVector> * queue = new LinkedList<GraphVector>();
    for (int i = 0; i < v; i++) {
        if (inDegree[i] == 0) {
            queue->add(adj[i]->get(0));
        }
    }
    
    topoQueue = new LinkedList<GraphVector>();
    while (queue->size() != 0) {
        GraphVector * i = queue->removeFirst();
        cout << "->" << i->vector;
        topoQueue->add(i);
        for (int j = 1; j < adj[i->vector]->size(); j++) {
            GraphVector * k = adj[i->vector]->get(j);
            inDegree[k->vector]--;
            if (inDegree[k->vector] == 0) {
                queue->add(k);
            }
        }
    }
    cout << endl;
}

void Graph::printTopo(){
    for (int i = 0; i < topoQueue->size(); i++) {
        cout << topoQueue->get(i)->vector << " ";
    }
    cout << endl;
}

void Graph::topoSortByDFS(){
    // 先构建逆邻接表，边s->t表示，s依赖于t，t优先于s
    LinkedList<GraphVector> *inverseAdj[v];
    for (int i = 0; i < v; i++) {
        LinkedList<GraphVector> * list = new LinkedList<GraphVector>();
        list->add(new GraphVector(i));
        inverseAdj[i] = list;
    }
    //通过邻接表生成逆邻接表
    for (int i = 0; i < v; i++) {
        for (int j = 1; j < adj[i]->size(); j++) {
            GraphVector * w = adj[i]->get(j);
            inverseAdj[w->vector]->add(adj[i]->get(0));
        }
    }
    
    // 打印逆邻接表
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < inverseAdj[i]->size(); j++) {
            if (j == inverseAdj[i]->size() - 1) {
                cout << inverseAdj[i]->get(j)->vector;
            } else {
                cout << inverseAdj[i]->get(j)->vector << "--";
            }
        }
        cout << endl;
    }
    
    bool visited[100] = {false};
    for (int i = 0; i < v; i++) {
        if (visited[i] == false) {
            visited[i] = true;
            recurDFStopSort(i, inverseAdj, visited);
        }
    }
}

void Graph::recurDFStopSort(int vertex, LinkedList<GraphVector> *inverseAdj[], bool visited[]){
    for (int i = 0; i < inverseAdj[vertex]->size(); i++) {
        GraphVector * w = inverseAdj[vertex]->get(i);
        if (visited[w->vector] == true) {
            continue;
        }
        visited[w->vector] = true;
        recurDFStopSort(w->vector, inverseAdj, visited);
    }
    cout << "->" << vertex;
}


#endif /* Graph_hpp */
