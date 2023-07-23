//
//  main.cpp
//  DepthFirstPaths
//
//  Created by mingyue on 2022/2/28.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    vector<vector<int> *> * adj;
    Graph() {
        
    }
    Graph(int V) {
        this->V = V;
        this->E = 0;
        adj = new vector<vector<int> *>(this->V);
        for (int i = 0; i < V; i++) {
            adj->at(i) = new vector<int>();
        }
    }
    ~Graph() {
        cout << "~Graph()" << endl;
        for (int i = 0; i < V; i++) {
            delete adj->at(i);
        }
        delete adj;
    }
    int getV() {
        return V;
    }
    int getE() {
        return E;
    }
    void addEdge(int v, int w) {
        adj->at(v)->push_back(w);
        adj->at(w)->push_back(v);
        E++;
    }
    void show() {
        for (int i = 0; i < adj->size(); i++) {
            cout << i << ":";
            for (int j = 0; j < adj->at(i)->size(); j++) {
                cout << adj->at(i)->at(j) << " ";
            }
            cout << endl;
        }
    }
private:
    int V;
    int E;
};

class DepthFirstPaths {
public:
    DepthFirstPaths() {
        
    }
    DepthFirstPaths(Graph * g, int s) {
        marked = new vector<bool>(g->getV(), false);
        edgeTo = new vector<int>(g->getV());
        this->s = s;
        dfs(g, s);
    }
    ~DepthFirstPaths() {
        cout << "~DepthFirstPaths()" << endl;
        delete edgeTo;
        delete marked;
    }
    bool hasPathsTo(int v) {
        return marked->at(v);
    }
    stack<int> * pathTo(int v) {
        if (hasPathsTo(v) == false) {
            return nullptr;
        }
        stack<int> * path = new stack<int>();
        for (int x = v; x != s; x = edgeTo->at(x)) {
            path->push(x);
        }
        path->push(s);
        return path;
    }
    void showEdge() {
        for (int i = 0; i < edgeTo->size(); i++) {
            cout << "(" << i << ":" << edgeTo->at(i) << ")" << endl;
        }
    }
private:
    vector<bool> * marked;
    vector<int> * edgeTo;
    int s;
    void dfs(Graph * g, int v) {
        marked->at(v) = true;
        for (int i : *g->adj->at(v)) {
            if (marked->at(i) == false) {
                edgeTo->at(i) = v;
                dfs(g, i);
            }
        }
//        for (int i = 0; i < g->adj->at(v)->size(); i++) {
//            if (marked->at(g->adj->at(v)->at(i)) == false) {
//                edgeTo->at(g->adj->at(v)->at(i)) = v;
//                dfs(g, g->adj->at(v)->at(i));
//            }
//        }
    }
};

int main(int argc, const char * argv[]) {
    
    Graph * g = new Graph(6);
    g->addEdge(0, 2);
    g->addEdge(0, 1);
    g->addEdge(0, 5);
    g->addEdge(2, 1);
    g->addEdge(2, 3);
    g->addEdge(2, 4);
    g->addEdge(3, 4);
    g->addEdge(3, 5);
    g->show();
    cout << g->getV() << endl;
    cout << g->getE() << endl;
    
    DepthFirstPaths depthFirstPaths = DepthFirstPaths(g, 0);
    depthFirstPaths.showEdge();
    
    stack<int> * s = depthFirstPaths.pathTo(5);
    while (s->empty() == false) {
        cout << s->top() << " ";
        s->pop();
    }
    cout << endl;
    delete s;
    
    delete g;
    
    return 0;
}
