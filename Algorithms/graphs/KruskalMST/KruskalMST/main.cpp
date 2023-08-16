//
//  main.cpp
//  KruskalMST
//
//  Created by mingyue on 2022/3/19.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 浮点型转字符串小数点后保留fixed位有效数字
auto formatDobleValue(double val, int fixed) {
    auto str = to_string(val);
    return str.substr(0, str.find(".") + fixed + 1);
}

class UF {
public:
    UF() {
        
    }
    UF(int N) {
        count = N;
        id = new vector<int>(N);
        for (int i = 0; i < N; i++) {
            id->at(i) = i;
        }
    }
    ~UF() {
        cout << "~UF()" << endl;
        delete id;
    }
    int getCount() {
        return count;
    }
    bool connected(int p, int q) {
        return id->at(p) == id->at(q);
    }
    int find(int p) {
        return id->at(p);
    }
    void unionP(int p, int q) {
        int pID = id->at(p);
        int qID = id->at(q);
        if (pID == qID) {
            return;
        }
        for (int i = 0; i < id->size(); i++) {
            if (id->at(i) == pID) {
                id->at(i) = qID;
            }
        }
        count--;
    }
    void show() {
        cout << "count:" << count << endl;
        for (int i = 0; i < id->size(); i++) {
            cout << i << ":" << id->at(i) << endl;
        }
    }
private:
    vector<int> * id;
    int count;
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
        return to_string(this->v) + "-" + to_string(this->w) + " " + formatDobleValue(this->weight, 2);
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

class MinPQ {
private:
    vector<Edge *> *pq;
    size_t N;
public:
    MinPQ(size_t maxN) {
        pq = new vector<Edge *>(maxN + 1);
        N = 0;
        cout << "pq size = " << pq->size() << endl;
    }
    ~MinPQ() {
        cout << "~MinPQ()" << endl;
        delete pq;
    }
    bool isEmpty() {
        return N == 0;
    }
    size_t size() {
        return N;
    }
    void insert(Edge * e) {
        pq->at(++N) = e;
        swim(N);
    }
    Edge * delMin() {
        Edge * min = pq->at(1);
        exch(1, N--);
        pq->at(N + 1) = nullptr;
        sink(1);
        return min;
    }
    void show() {
        size_t count = pq->size();
        for (int i = 1; i < count; i++) {
            cout << pq->at(i)->toString() << " " << endl;;
        }
        cout << endl;
    }
private:
    bool more(size_t i, size_t j) {
        return (pq->at(i)->getWeight() - pq->at(j)->getWeight()) > 0.0;
    }
    void exch(size_t i, size_t j) {
        Edge * tmp = pq->at(i);
        pq->at(i) = pq->at(j);
        pq->at(j) = tmp;
    }
    void swim(size_t k) {
        while (k > 1 && more(k / 2, k)) {
            exch(k / 2, k);
            k = k / 2;
        }
    }
    void sink(size_t k) {
        while (2 * k <= N) {
            size_t j = 2 * k;
            if (j < N && more(j, j + 1)) {
                j++;
            }
            if (!more(k, j)) {
                break;
            }
            exch(k, j);
            k = j;
        }
    }
};

class KruskalMST {
public:
    KruskalMST() {
        
    }
    KruskalMST(EdgeWeightGraph * g) {
        mst = new queue<Edge *>();
        MinPQ pq = MinPQ(100);
        for (int i = 0; i < g->getEdges()->size(); i++) {
            pq.insert(g->getEdges()->at(i));
        }
        UF uf = UF(g->getV());
        while (!pq.isEmpty() && mst->size() < (g->getV() - 1)) {
            Edge * e = pq.delMin();
            int v = e->getEither();
            int w = e->getOther(v);
            if (uf.connected(v, w)) {
                continue;
            }
            uf.unionP(v, w);
            mst->push(e);
        }
    }
    ~KruskalMST() {
        cout << "~KruskalMST()" << endl;
    }
    queue<Edge *> * edges() {
        return mst;
    }
private:
    queue<Edge *> * mst;
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
    
    KruskalMST kMST = KruskalMST(g);
    while (kMST.edges()->empty() == false) {
        Edge * e = kMST.edges()->front();
        cout << e->toString() << endl;
        kMST.edges()->pop();
        delete e;
    }
    
    return 0;
}
