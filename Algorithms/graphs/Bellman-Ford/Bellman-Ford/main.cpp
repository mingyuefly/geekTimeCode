//
//  main.cpp
//  Bellman-Ford
//
//  Created by mingyue on 2022/3/23.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <float.h>
#include <string>

using namespace std;

class DirectedEdge {
public:
    DirectedEdge() {
        
    }
    DirectedEdge(int v, int w, double weight) {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }
    ~DirectedEdge() {
        cout << "~DirectedEdge()" << endl;
    }
    int from() {
        return v;
    }
    int to() {
        return w;
    }
    double getWeight() {
        return weight;
    }
    string toString() {
        return to_string(this->v) + "-" + to_string(this->w) + " " + to_string(this->weight);
    }
private:
    int v;
    int w;
    double weight;
};

class EdgeWeightedDigraph {
public:
    vector<vector<DirectedEdge *> *> * adj;
    EdgeWeightedDigraph() {
        
    }
    EdgeWeightedDigraph(int V) {
        this->V = V;
        this->E = 0;
        adj = new vector<vector<DirectedEdge *> *>(this->V);
        for (int v = 0; v < this->V; v++) {
            adj->at(v) = new vector<DirectedEdge *>();
        }
        edges = new vector<DirectedEdge *>();
    }
    ~EdgeWeightedDigraph() {
        cout << "~EdgeWeightedDigraph()" << endl;
        edges = getEdges();
        for (int i = 0; i < edges->size(); i++) {
            delete edges->at(i);
        }
        for (int i = 0; i < V; i++) {
            delete adj->at(i);
        }
    }
    void addEdges(DirectedEdge * e) {
        adj->at(e->from())->push_back(e);
        E++;
    }
    void show() {
        for (int i = 0; i < V; i++) {
            cout << i << ":";
            for (int j = 0; j < adj->at(i)->size(); j++) {
                cout << "(" << adj->at(i)->at(j)->toString() << ")" << " ";
            }
            cout << endl;
        }
    }
    vector<DirectedEdge *> * getEdges() {
        edges->clear();
        for (int v = 0; v < V; v++) {
            for (int w = 0; w < adj->at(v)->size(); w++) {
                edges->push_back(adj->at(v)->at(w));
            }
        }
        return edges;
    }
    int getV() {
        return V;
    }
    int getE() {
        return E;
    }
private:
    int V;
    int E;
    vector<DirectedEdge *> * edges;
};

class EdgeWeightedDirectedCycle {
public:
    EdgeWeightedDirectedCycle() {
        
    }
    EdgeWeightedDirectedCycle(EdgeWeightedDigraph * g) {
        marked = new vector<bool>(g->getV(), false);
        edgeTo = new vector<DirectedEdge *>(g->getV());
        onStack = new vector<bool>(g->getV(), false);
        for (int v = 0; v < g->getV(); v++) {
            if (!marked->at(v)) {
                dfs(g, v);
            }
        }
    }
    ~EdgeWeightedDirectedCycle() {
        cout << "~EdgeWeightedDirectedCycle()" << endl;
    }
    bool hasCycle() {
        return cycle != nullptr;
    }
    stack<DirectedEdge *> * getCycle() {
        return cycle;
    }
private:
    vector<bool> * marked;
    vector<DirectedEdge *> * edgeTo;
    vector<bool> * onStack;
    stack<DirectedEdge *> * cycle = nullptr;
    void dfs(EdgeWeightedDigraph * g, int v) {
        onStack->at(v) = true;
        marked->at(v) = true;
        for (int i = 0; i < g->adj->at(v)->size(); i++) {
            DirectedEdge * e = g->adj->at(v)->at(i);
            int w = e->to();
            if (cycle != nullptr) {
                return;
            } else if (marked->at(w) == false) {
                edgeTo->at(w) = e;
                dfs(g, w);
            } else if (onStack->at(w) == true) {
                cycle = new stack<DirectedEdge *>();
                DirectedEdge * f = e;
                while (f->from() != w) {
                    cycle->push(f);
                    f = edgeTo->at(f->from());
                }
                cycle->push(f);
                return;
            }
        }
        onStack->at(v) = false;
    }
};

class BellmanForSP {
public:
    BellmanForSP() {
        
    }
    BellmanForSP(EdgeWeightedDigraph * g, int s) {
        distTo = new vector<double>(g->getV());
        edgeTo = new vector<DirectedEdge *>(g->getV());
        onQ = new vector<bool>(g->getV(), false);
        myQueue = new queue<int>();
        for (int v = 0; v < g->getV(); v++) {
            distTo->at(v) = DBL_MAX;
        }
        distTo->at(s) = 0.0;
        myQueue->push(s);
        onQ->at(s) = true;
        while (!myQueue->empty() && !hasNegativeCycle()) {
            int v = myQueue->front();
            myQueue->pop();
            onQ->at(v) = false;
            relax(g, v);
        }
    }
    ~BellmanForSP() {
        cout << "~BellmanForSP()" << endl;
    }
    bool hasNegativeCycle() {
        return cycle != nullptr;
    }
    stack<DirectedEdge *> * getNegativeCycle() {
        return cycle;
    }
    void show() {
        for (int i = 0; i < edgeTo->size(); i++) {
            DirectedEdge * e = edgeTo->at(i);
            if (e == nullptr) {
                cout << i << endl;
                continue;
            }
            cout << i << " " << e->from() << "--" << e->to() << " " << distTo->at(i) << endl;
        }
        cout << endl;
    }
    double getDistTo(int v) {
        validateVertex(v);
        if (hasNegativeCycle()) {
            throw "Negative cost cycle exists";
        }
        return distTo->at(v);
    }
    bool hasPathTo(int v) {
        validateVertex(v);
        return distTo->at(v) < DBL_MAX;
    }
    stack<DirectedEdge *> * pathTo(int v) {
        validateVertex(v);
        if (hasNegativeCycle()) {
            throw "Negative cost cycle exists";
        }
        if (!hasPathTo(v)) {
            return nullptr;
        }
        stack<DirectedEdge *> * path = new stack<DirectedEdge *>();
        for (DirectedEdge * e = edgeTo->at(v); e != nullptr; e = edgeTo->at(e->from())) {
            path->push(e);
        }
        return path;
    }
private:
    vector<double> * distTo;
    vector<DirectedEdge *> * edgeTo;
    vector<bool> * onQ;
    queue<int> * myQueue;
    int cost;
    stack<DirectedEdge *> * cycle = nullptr;
    void relax(EdgeWeightedDigraph * g, int v) {
        for (int i = 0; i < g->adj->at(v)->size(); i++) {
            DirectedEdge * e = g->adj->at(v)->at(i);
            int w = e->to();
            if (distTo->at(w) > distTo->at(v) + e->getWeight()) {
                distTo->at(w) = distTo->at(v) + e->getWeight();
                edgeTo->at(w) = e;
                if (!onQ->at(w)) {
                    myQueue->push(w);
                    onQ->at(w) = true;
                }
            }
            if (cost++ % g->getV() == 0) {
                findNegativeCycle();
            }
        }
    }
    void findNegativeCycle() {
        int V = (int)edgeTo->size();
        EdgeWeightedDigraph * spt = new EdgeWeightedDigraph(V);
        for (int v = 0; v < V; v++) {
            if (edgeTo->at(v) != nullptr) {
                spt->addEdges(edgeTo->at(v));
            }
        }
        EdgeWeightedDirectedCycle finder = EdgeWeightedDirectedCycle(spt);
        cycle = finder.getCycle();
    }
    void validateVertex(int v) {
        int V = (int)distTo->size();
        if (v < 0 || v > V) {
            string expression = "vertex " + to_string(v) + " is not between 0 and " + to_string((V-1));
            throw expression;
        }
    }
};

int main(int argc, const char * argv[]) {
    
    EdgeWeightedDigraph * g = new EdgeWeightedDigraph(8);
    g->addEdges(new DirectedEdge(0, 2, 0.26));
    g->addEdges(new DirectedEdge(0, 4, 0.38));
    g->addEdges(new DirectedEdge(1, 3, 0.29));
    g->addEdges(new DirectedEdge(2, 7, 0.34));
    g->addEdges(new DirectedEdge(3, 6, 0.52));
    g->addEdges(new DirectedEdge(4, 7, 0.37));
    g->addEdges(new DirectedEdge(4, 5, 0.35));
    g->addEdges(new DirectedEdge(5, 1, 0.32));
    g->addEdges(new DirectedEdge(5, 7, 0.28));
    g->addEdges(new DirectedEdge(5, 4, 0.35));
    g->addEdges(new DirectedEdge(6, 4, -1.25));
    g->addEdges(new DirectedEdge(6, 0, -1.40));
    g->addEdges(new DirectedEdge(6, 2, -1.20));
    g->addEdges(new DirectedEdge(7, 3, 0.39));
    g->addEdges(new DirectedEdge(7, 5, 0.28));
    
    
//    EdgeWeightedDigraph * g = new EdgeWeightedDigraph(8);
//    g->addEdges(new DirectedEdge(0, 2, 0.26));
//    g->addEdges(new DirectedEdge(0, 4, 0.38));
//    g->addEdges(new DirectedEdge(1, 3, 0.29));
//    g->addEdges(new DirectedEdge(2, 7, 0.34));
//    g->addEdges(new DirectedEdge(3, 6, 0.52));
//    g->addEdges(new DirectedEdge(4, 7, 0.37));
//    g->addEdges(new DirectedEdge(4, 5, 0.35));
//    g->addEdges(new DirectedEdge(5, 1, 0.32));
//    g->addEdges(new DirectedEdge(5, 7, 0.28));
//    g->addEdges(new DirectedEdge(5, 4, -0.66));
//    g->addEdges(new DirectedEdge(6, 4, 0.93));
//    g->addEdges(new DirectedEdge(6, 0, 0.58));
//    g->addEdges(new DirectedEdge(6, 2, 0.40));
//    g->addEdges(new DirectedEdge(7, 3, 0.39));
//    g->addEdges(new DirectedEdge(7, 5, 0.28));
    
    g->show();
    
    BellmanForSP sp = BellmanForSP(g, 0);
    if (sp.hasNegativeCycle()) {
        cout << "has a cycle" << endl;
        for (int i = 0; i < sp.getNegativeCycle()->size(); i++) {
            cout << sp.getNegativeCycle()->top()->toString() << endl;
            sp.getNegativeCycle()->pop();
        }
    } else {
        cout << "not has a cycle" << endl;
        for (int v = 0; v < g->getV(); v++) {
            if (sp.hasPathTo(v)) {
                cout << v << ":" << endl;
                stack<DirectedEdge *> * path = sp.pathTo(v);
                while (path->empty() == false) {
                    cout << path->top()->toString() << endl;
                    path->pop();
                }
                cout << endl;
            } else {
                cout << v << " has no path" << endl;
            }
        }
    }
    sp.show();
    
    
    
    
//    EdgeWeightedDirectedCycle eCycle = EdgeWeightedDirectedCycle(g);
//    if (eCycle.hasCycle()) {
//        while (eCycle.getCycle()->empty() == false) {
//            cout << eCycle.getCycle()->top()->toString() << endl;
//            eCycle.getCycle()->pop();
//        }
//    } else {
//        cout << "no cycle" << endl;
//    }
//
    delete g;
    
    return 0;
}
