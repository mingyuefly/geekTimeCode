//
//  main.cpp
//  PrimMST
//
//  Created by mingyue on 2022/3/13.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <float.h>

using namespace std;

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

class Edge {
public:
    Edge() {
        
    }
    Edge(int v, int w, double weight) {
        this->v = v;
        this->w = w;
        this->weight = weight;
    }
    ~Edge() {
        cout << "~Edge()" << endl;
    }
    double getWeight() {
        return weight;
    }
    int getEither() {
        return v;
    }
    int getOther(int vertex) {
        if (vertex == v) {
            return w;
        } else if (vertex == w) {
            return v;
        } else {
            return -1;
        }
    }
    int compare(Edge * that) {
        if (this->weight < that->weight) {
            return -1;
        } else if (this->weight > that->weight) {
            return 1;
        } else {
            return 0;
        }
    }
    string toString() {
        return to_string(this->v) + "-" + to_string(this->w) + " " + to_string(this->weight);
    }
private:
    int v;
    int w;
    double weight;
};

class EdgeWeightGraph {
public:
    vector<vector<Edge *> *> * adj;
    EdgeWeightGraph() {
        
    }
    EdgeWeightGraph(int V) {
        this->V = V;
        this->E = 0;
        adj = new vector<vector<Edge *> *>(this->V);
        for (int v = 0; v < V; v++) {
            adj->at(v) = new vector<Edge *>(0);
        }
        edges = new vector<Edge *>();
    }
    int getV() {
        return V;
    }
    int getE() {
        return E;
    }
    void addEdge(Edge * e) {
        int v = e->getEither();
        int w = e->getOther(v);
        adj->at(v)->push_back(e);
        adj->at(w)->push_back(e);
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
    vector<Edge *> * getEdges() {
        if (edges != nullptr && edges->size() > 0) {
            return edges;
        }
        for (int v = 0; v < V; v++) {
            for (int w = 0; w < adj->at(v)->size(); w++) {
                if (adj->at(v)->at(w)->getOther(v) > v) {
                    edges->push_back(adj->at(v)->at(w));
                }
            }
        }
        return edges;
    }
    ~EdgeWeightGraph() {
        cout << "~EdgeWeightGraph()" << endl;
        edges = getEdges();
        for (int i = 0; i < edges->size(); i++) {
            delete edges->at(i);
        }
        for (int i = 0; i < V; i++) {
            delete adj->at(i);
        }
    }
private:
    int V;
    int E;
    vector<Edge *> * edges;
};

class PrimMST {
public:
    PrimMST() {
        
    }
    PrimMST(EdgeWeightGraph * g) {
        edge = new vector<Edge *>(g->getV());
        distTo = new vector<double>(g->getV());
        marked = new vector<bool>(g->getV(), false);
        for (int v = 0; v < g->getV(); v++) {
            distTo->at(v) = DBL_MAX;
        }
        pq = new IndexMinPQ(100);
        distTo->at(0) = 0.0;
        pq->insert(0, 0.0);
        
        while (pq->isEmpty() == false) {
            visit(g, pq->delMin());
        }
    }
    ~PrimMST() {
        cout << "~PrimMST()" << endl;
    }
    void show() {
        for (int i = 1; i < edge->size(); i++) {
            Edge * e = edge->at(i);
            int v = e->getEither();
            cout << i << " " << v << "--" << e->getOther(v) << " " << distTo->at(i) << endl;
        }
        cout << endl;
    }
private:
    vector<Edge *> * edge;
    vector<double> * distTo;
    vector<bool> * marked;
    IndexMinPQ * pq;
    void visit(EdgeWeightGraph * g, int v) {
        marked->at(v) = true;
        for (int i = 0; i < g->adj->at(v)->size(); i++) {
            Edge * e = g->adj->at(v)->at(i);
            int w = e->getOther(v);
            if (marked->at(w) == true) {
                continue;
            }
            if (e->getWeight() < distTo->at(w)) {
                edge->at(w) = e;
                distTo->at(w) = e->getWeight();
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
    
    EdgeWeightGraph * g = new EdgeWeightGraph(8);
    g->addEdge(new Edge(4, 5, 0.35));
    g->addEdge(new Edge(4, 7, 0.37));
    g->addEdge(new Edge(5, 7, 0.28));
    g->addEdge(new Edge(0, 7, 0.16));
    g->addEdge(new Edge(1, 5, 0.32));
    g->addEdge(new Edge(0, 4, 0.38));
    g->addEdge(new Edge(2, 3, 0.17));
    g->addEdge(new Edge(1, 7, 0.19));
    g->addEdge(new Edge(0, 2, 0.26));
    g->addEdge(new Edge(1, 2, 0.36));
    g->addEdge(new Edge(1, 3, 0.29));
    g->addEdge(new Edge(2, 7, 0.34));
    g->addEdge(new Edge(6, 2, 0.40));
    g->addEdge(new Edge(3, 6, 0.52));
    g->addEdge(new Edge(6, 0, 0.58));
    g->addEdge(new Edge(6, 4, 0.93));
    
    g->show();
    
    PrimMST primMST = PrimMST(g);
    primMST.show();
    
    delete g;
    
    return 0;
}
