//
//  main.cpp
//  Cycle
//
//  Created by mingyue on 2022/3/6.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>

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

class Cycle {
public:
    Cycle() {
        
    }
    Cycle(Graph * g) {
        marked = new vector<bool>(g->getV());
        for (int s = 0; s < g->getV(); s++) {
            if (marked->at(s) == false) {
                dfs(g, s, s);
            }
        }
    }
    ~Cycle() {
        cout << "~Cycle()" << endl;
        delete marked;
    }
    bool getHasCycle() {
        return hasCycle;
    }
private:
    vector<bool> * marked;
    bool hasCycle = false;
    void dfs(Graph * g, int v, int u) {
        marked->at(v) = true;
        for (int w = 0; w < g->adj->at(v)->size(); w++) {
            if (marked->at(g->adj->at(v)->at(w)) == false) {
                dfs(g, g->adj->at(v)->at(w), v);
            } else if (w != u) {
                hasCycle = true;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Graph * g = new Graph(13);
    g->addEdge(0, 2);
    g->addEdge(0, 1);
    g->addEdge(0, 5);
    g->addEdge(0, 6);
    g->addEdge(3, 4);
    g->addEdge(3, 5);
    g->addEdge(4, 5);
    g->addEdge(4, 6);
    g->addEdge(7, 8);
    g->addEdge(9, 10);
    g->addEdge(9, 11);
    g->addEdge(9, 12);
    g->addEdge(11, 12);
    g->show();
    
    Cycle cycle = Cycle(g);
    cout << cycle.getHasCycle() << endl;
    
    delete g;
    
    return 0;
}
