//
//  main.cpp
//  DirectedCycle
//
//  Created by mingyue on 2022/3/8.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Digraph {
public:
    vector<vector<int> *> * adj;
    Digraph() {
        
    }
    Digraph(int V) {
        this->V = V;
        this->E = 0;
        adj = new vector<vector<int> *>(this->V);
        for (int v = 0; v < this->V; v++) {
            adj->at(v) = new vector<int>();
        }
    }
    ~Digraph() {
        cout << "~Digraph()" << endl;
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
        E++;
    }
    Digraph * reverse() {
        Digraph * r = new Digraph(V);
        for (int v = 0; v < V; v++) {
            for (int w = 0; w < adj->at(v)->size(); w++) {
                r->addEdge(adj->at(v)->at(w), v);
            }
        }
        return r;
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

class DirctedCycle {
public:
    DirctedCycle() {
        
    }
    DirctedCycle(Digraph * g) {
        marked = new vector<bool>(g->getV(), false);
        edgeTo = new vector<int>(g->getV());
        onStack = new vector<bool>(g->getV(), false);
        for (int v = 0; v < g->getV(); v++) {
            if (marked->at(v) == false) {
                dfs(g, v);
            }
        }
    }
    ~DirctedCycle() {
        cout << "~DirctedCycle()" << endl;
        delete marked;
        delete edgeTo;
        delete onStack;
        if (cycle != nullptr) {
            delete cycle;
        }
    }
    stack<int> * getCycle() {
        return cycle;
    }
    bool hasCycle() {
        return cycle != nullptr;
    }
private:
    vector<bool> * marked;
    vector<int> * edgeTo;
    vector<bool> * onStack;
    stack<int> * cycle;
    void dfs(Digraph * g, int v) {
        onStack->at(v) = true;
        marked->at(v) = true;
        for (int w = 0; w < g->adj->at(v)->size(); w++) {
            if (hasCycle() == true) {
                return;
            }
            if (marked->at(g->adj->at(v)->at(w)) == false) {
                edgeTo->at(g->adj->at(v)->at(w)) = v;
                dfs(g, g->adj->at(v)->at(w));
            } else if (onStack->at(g->adj->at(v)->at(w)) == true) {
                cycle = new stack<int>();
                for (int x = v; x != g->adj->at(v)->at(w); x = edgeTo->at(x)) {
                    cycle->push(x);
                }
                cycle->push(g->adj->at(v)->at(w));
                cycle->push(v);
            }
        }
        onStack->at(v) = false;
    }
};

int main(int argc, const char * argv[]) {
    Digraph * g = new Digraph(13);
    g->addEdge(0, 5);
    g->addEdge(0, 1);
    g->addEdge(2, 0);
    g->addEdge(2, 3);
    g->addEdge(3, 5);
    g->addEdge(3, 2);
    g->addEdge(4, 3);
    g->addEdge(4, 2);
    g->addEdge(5, 4);
    g->addEdge(6, 0);
    g->addEdge(6, 4);
    g->addEdge(6, 9);
    g->addEdge(7, 6);
    g->addEdge(7, 8);
    g->addEdge(8, 7);
    g->addEdge(8, 9);
    g->addEdge(9, 10);
    g->addEdge(9, 11);
    g->addEdge(10, 12);
    g->addEdge(11, 4);
    g->addEdge(11, 12);
    g->addEdge(12, 9);
    
    g->show();
    
    DirctedCycle dCycle = DirctedCycle(g);
    if (dCycle.hasCycle() == true) {
        while (dCycle.getCycle()->empty() == false) {
            cout << dCycle.getCycle()->top() << endl;
            dCycle.getCycle()->pop();
        }
    }
    
    delete g;
    return 0;
}
