//
//  main.cpp
//  Dijksta
//
//  Created by mingyue on 2022/3/20.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <float.h>

using namespace std;

auto formatDobleValue(double val, int fixed) {
    auto str = std::to_string(val);
    return str.substr(0, str.find(".") + fixed + 1);
}

class IndexMinPQ {
public:
    IndexMinPQ() {
        
    }
    IndexMinPQ(size_t maxN) {
        this->maxN = maxN;
        keys = new vector<double>(maxN + 1);
        for (int i = 0; i < maxN + 1; i++) {
            keys->at(i) = -1.0;
        }
        N = 0;
        pq = new vector<int>(maxN + 1, -1);
        qp = new vector<int>(maxN + 1, -1);
        cout << "pq size = " << pq->size() << endl;
    }
    ~IndexMinPQ() {
        cout << "~IndexMinPQ()" << endl;
        delete pq;
        delete qp;
        delete keys;
    }
    bool contains(int i) {
        if (validateIndex(i) == false) {
            return false;
        }
        return qp->at(i) != -1;
    }
    int size() {
        return N;
    }
    bool isEmpty() {
        return N == 0;
    }
    void insert(int i, double key) {
        if (validateIndex(i) == false) {
            return;
        }
        if (contains(i)) {
            cout << "contains" << " " << i << endl;
            return;
        }
        N++;
        qp->at(i) = N;
        pq->at(N) = i;
        keys->at(i) = key;
        swim(N);
    }
    int minIndex() {
        if (N == 0) {
            return -1;
        }
        return pq->at(1);
    }
    double minKey() {
        if (N == 0) {
            return -1.0;
        }
        return keys->at(pq->at(1));
    }
    int delMin() {
        if (N == 0) {
            return -1;
        }
        int min = pq->at(1);
        exch(1, N--);
        sink(1);
        if (min != pq->at(N + 1)) {
            return -1;
        }
        qp->at(min) = -1;
        keys->at(min) = -1.0;
        pq->at(N + 1) = -1;
        return min;
    }
    double keyOf(int i) {
        if (validateIndex(i) == false) {
            return -1.0;
        }
        if (!contains(i)) {
            return -1.0;
        }
        return keys->at(i);
    }
    void changeKey(int i, double key) {
        if (validateIndex(i) == false) {
            return;
        }
        if (!contains(i)) {
            return;
        }
        keys->at(i) = key;
        swim(qp->at(i));
        sink(qp->at(i));
    }
    void deleteIndex(int i) {
        if (!validateIndex(i)) {
            return;
        }
        if (!contains(i)) {
            return;
        }
        int index = qp->at(i);
        exch(index, N--);
        swim(index);
        sink(index);
        keys->at(i) = -1.0;
        qp->at(i) = -1;
    }
    void show() {
        size_t count = N;
        for (int i = 0; i <= count; i++) {
            cout << pq->at(i) << ' ' << keys->at(i) << " " << qp->at(i) << endl;
        }
        cout << endl;
    }
private:
    vector<double > *keys;
    int N = 0;
    vector<int> * pq;
    vector<int> * qp;
    size_t maxN = 100;
    bool validateIndex(int k) {
        if (k >= maxN || k < 0) {
            return false;
        }
        return true;
    }
    bool greater(int i, int j) {
        return (keys->at(pq->at(i)) - (keys->at(pq->at(j)))) > 0.0;
    }
    void exch(int i, int j) {
        int swap = pq->at(i);
        pq->at(i) = pq->at(j);
        pq->at(j) = swap;
        qp->at(pq->at(i)) = i;
        qp->at(pq->at(j)) = j;
    }
    void swim(int k) {
        while (k > 1 && greater(k / 2, k)) {
            exch(k, k / 2);
            k = k / 2;
        }
    }
    void sink(int k) {
        while (2 * k <= N) {
            int j = 2 * k;
            if (j < N && greater(j, j+1)) {
                j++;
            }
            if (!greater(k, j)) {
                break;
            }
            exch(k, j);
            k = j;
        }
    }
};

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

class DijkstraSP {
public:
    DijkstraSP() {
        
    }
    DijkstraSP(EdgeWeightedDigraph * g, int s) {
        edges = new vector<DirectedEdge *>(g->getV());
        distTo = new vector<double>(g->getV());
        pq = new IndexMinPQ(100);
        for (int v = 0; v < g->getV(); v++) {
            distTo->at(v) = DBL_MAX;
        }
        distTo->at(s) = 0.0;
        pq->insert(s, 0.0);
        while (pq->isEmpty() == false) {
            relax(g, pq->delMin());
        }
    }
    ~DijkstraSP() {
        cout << "~DijkstraSP()" << endl;
    }
    void show() {
        for (int i = 1; i < edges->size(); i++) {
            DirectedEdge * e = edges->at(i);
            cout << i << " " << e->from() << "--" << e->to() << " " << distTo->at(i) << endl;
        }
        cout << endl;
    }
    double getDistTo(int v) {
        return distTo->at(v);
    }
    bool hasPathTo(int v) {
        return distTo->at(v) < DBL_MAX;
    }
private:
    vector<DirectedEdge *> * edges;
    vector<double> * distTo;
    IndexMinPQ * pq;
    void relax(EdgeWeightedDigraph * g, int v) {
        for (int i = 0; i < g->adj->at(v)->size(); i++) {
            DirectedEdge * e = g->adj->at(v)->at(i);
            int w = e->to();
            if (distTo->at(w) > distTo->at(v) + e->getWeight()) {
                distTo->at(w) = distTo->at(v) + e->getWeight();
                edges->at(w) = e;
                if (pq->contains(w)) {
                    pq->changeKey(w, distTo->at(w));
                } else {
                    pq->insert(w, distTo->at(w));
                }
            }
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
    g->addEdges(new DirectedEdge(6, 4, 0.93));
    g->addEdges(new DirectedEdge(6, 0, 0.58));
    g->addEdges(new DirectedEdge(6, 2, 0.40));
    g->addEdges(new DirectedEdge(7, 3, 0.39));
    g->addEdges(new DirectedEdge(7, 5, 0.28));
    
    g->show();
    
    DijkstraSP sp = DijkstraSP(g, 0);
    sp.show();
    
    delete g;
    
    return 0;
}
