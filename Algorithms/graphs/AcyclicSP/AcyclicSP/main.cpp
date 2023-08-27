//
//  main.cpp
//  AcyclicSP
//
//  Created by mingyue on 2022/3/21.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <float.h>
#include <queue>
#include <stack>

using namespace std;

auto formatDobleValue(double val, int fixed) {
    auto str = std::to_string(val);
    return str.substr(0, str.find(".") + fixed + 1);
}

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
        return to_string(this->v) + "-" + to_string(this->w) + " " + formatDobleValue(this->weight, 2);
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

class DirctedCycle {
public:
    DirctedCycle() {
        
    }
    DirctedCycle(EdgeWeightedDigraph * g) {
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
    stack<int> * cycle = nullptr;
    void dfs(EdgeWeightedDigraph * g, int v) {
        onStack->at(v) = true;
        marked->at(v) = true;
        for (int w = 0; w < g->adj->at(v)->size(); w++) {
            if (hasCycle() == true) {
                return;
            }
            DirectedEdge * e = g->adj->at(v)->at(w);
            if (marked->at(e->to()) == false) {
                edgeTo->at(e->to()) = v;
                dfs(g, e->to());
            } else if (onStack->at(e->to()) == true) {
                cycle = new stack<int>();
                for (int x = v; x != g->adj->at(v)->at(w)->to(); x = edgeTo->at(x)) {
                    cycle->push(x);
                }
                cycle->push(g->adj->at(v)->at(w)->to());
                cycle->push(v);
            }
        }
        onStack->at(v) = false;
    }
};

class DepthFirstOrder {
public:
    DepthFirstOrder() {
        
    }
    DepthFirstOrder(EdgeWeightedDigraph * g) {
        marked = new vector<bool>(g->getV(), false);
        pre = new queue<int>();
        post = new queue<int>();
        reversePost = new stack<int>();
        for (int v = 0; v < g->adj->size(); v++) {
            if (marked->at(v) == false) {
                dfs(g, v);
            }
        }
    }
    ~DepthFirstOrder() {
        cout << "~DepthFirstOrder()" << endl;
        if (marked != nullptr) {
            delete marked;
        }
        if (pre != nullptr) {
            delete pre;
        }
        if (post != nullptr) {
            delete post;
        }
        if (reversePost != nullptr) {
//            delete reversePost;
        }
    }
    queue<int> * getPre() {
        return pre;
    }
    queue<int> * getPost() {
        return post;
    }
    stack<int> * getReversePost() {
        return reversePost;
    }
private:
    vector<bool> * marked;
    queue<int> * pre;
    queue<int> * post;
    stack<int> * reversePost;
    void dfs(EdgeWeightedDigraph * g, int v) {
        pre->push(v);
        marked->at(v) = true;
        for (int w = 0; w < g->adj->at(v)->size(); w++) {
            DirectedEdge * e = g->adj->at(v)->at(w);
            if (marked->at(e->to()) == false) {
                dfs(g, e->to());
            }
        }
        post->push(v);
        reversePost->push(v);
    }
};

class Topological {
public:
    Topological() {
        
    }
    Topological(EdgeWeightedDigraph * g) {
        DirctedCycle cycleFinder = DirctedCycle(g);
        if (cycleFinder.hasCycle() == false) {
            DepthFirstOrder dfs = DepthFirstOrder(g);
            order = dfs.getReversePost();
        }
    }
    ~Topological() {
        cout << "~Topological()" << endl;
        if (order != nullptr) {
            delete order;
        }
    }
    stack<int> * getOrder() {
        return order;
    }
    bool isDAG() {
        return order != nullptr;
    }
private:
    stack<int> * order;
};

class AcycliSP {
public:
    AcycliSP() {
        
    }
    AcycliSP(EdgeWeightedDigraph * g, int s) {
        edgeTo = new vector<DirectedEdge *>(g->getV());
        distTo = new vector<double>(g->getV());
        for (int v = 0; v < g->getV(); v++) {
            distTo->at(v) = DBL_MAX;
        }
        Topological top = Topological(g);
        distTo->at(top.getOrder()->top()) = 0.0;
        while (top.getOrder()->empty() == false) {
            int v = top.getOrder()->top();
            top.getOrder()->pop();
            relax(g, v);
            
        }
//        for (int v = 0; v < top.getOrder()->size(); v++) {
//            relax(g, top.getOrder()->top());
//            top.getOrder()->pop();
//        }
    }
    ~AcycliSP() {
        cout << "~AcycliSP()" << endl;
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
private:
    vector<DirectedEdge *> * edgeTo;
    vector<double> * distTo;
    void relax(EdgeWeightedDigraph * g, int v) {
        for (int i = 0; i < g->adj->at(v)->size(); i++) {
            DirectedEdge * e = g->adj->at(v)->at(i);
            int w = e->to();
            if (distTo->at(w) > distTo->at(v) + e->getWeight()) {
                distTo->at(w) = distTo->at(v) + e->getWeight();
                edgeTo->at(w) = e;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    EdgeWeightedDigraph * g = new EdgeWeightedDigraph(8);
    g->addEdges(new DirectedEdge(0, 2, 0.26));
    g->addEdges(new DirectedEdge(1, 3, 0.29));
    g->addEdges(new DirectedEdge(3, 6, 0.52));
    g->addEdges(new DirectedEdge(3, 7, 0.39));
    g->addEdges(new DirectedEdge(4, 0, 0.37));
    g->addEdges(new DirectedEdge(4, 7, 0.37));
    g->addEdges(new DirectedEdge(5, 1, 0.32));
    g->addEdges(new DirectedEdge(5, 7, 0.28));
    g->addEdges(new DirectedEdge(5, 4, 0.35));
    g->addEdges(new DirectedEdge(6, 4, 0.93));
    g->addEdges(new DirectedEdge(6, 0, 0.58));
    g->addEdges(new DirectedEdge(6, 2, 0.40));
    g->addEdges(new DirectedEdge(7, 2, 0.34));
    
    g->show();
    
    /*
    DepthFirstOrder dfo = DepthFirstOrder(g);
    cout << "pre:" << endl;
    while (dfo.getPre()->empty() == false) {
        cout << dfo.getPre()->front() << " ";
        dfo.getPre()->pop();
    }
    cout << endl;
    cout << "post:" << endl;
    while (dfo.getPost()->empty() == false) {
        cout << dfo.getPost()->front() << " ";
        dfo.getPost()->pop();
    }
    cout << endl;
    cout << "reversePost:" << endl;
    while (dfo.getReversePost()->empty() == false) {
        cout << dfo.getReversePost()->top() << " ";
        dfo.getReversePost()->pop();
    }
    cout << endl;
    
    
//    DirctedCycle dCycle = DirctedCycle(g);
//    if (dCycle.hasCycle() == true) {
//        while (dCycle.getCycle()->empty() == false) {
//            cout << dCycle.getCycle()->top() << endl;
//            dCycle.getCycle()->pop();
//        }
//    } else {
//        cout << "no cycle" << endl;
//    }
    
    Topological topoLogical = Topological(g);
    cout << "order:" << endl;
    while (topoLogical.getOrder()->empty() == false) {
        cout << topoLogical.getOrder()->top() << " ";
        topoLogical.getOrder()->pop();
    }
    cout << endl;
    */
    
    AcycliSP sp = AcycliSP(g, 0);
    sp.show();
    
    
    delete g;
    
    
    return 0;
}
