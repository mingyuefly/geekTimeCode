//
//  main.cpp
//  KosarajuSCC
//
//  Created by mingyue on 2022/3/11.
//  Copyright © 2022 Gmingyue. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
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

class DepthFirstOrder {
public:
    DepthFirstOrder() {
        
    }
    DepthFirstOrder(Digraph * g) {
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
    void dfs(Digraph * g, int v) {
        pre->push(v);
        marked->at(v) = true;
        for (int w = 0; w < g->adj->at(v)->size(); w++) {
            if (marked->at(g->adj->at(v)->at(w)) == false) {
                dfs(g, g->adj->at(v)->at(w));
            }
        }
        post->push(v);
        reversePost->push(v);
    }
};

class KosarajuSCC {
public:
    KosarajuSCC() {
        
    }
    KosarajuSCC(Digraph * g) {
        marked = new vector<bool>(g->getV(), false);
        id = new vector<int>(g->getV(), -1);
        DepthFirstOrder order = DepthFirstOrder(g->reverse());
        while (order.getReversePost()->empty() == false) {
            if (marked->at(order.getReversePost()->top()) == false) {
                dfs(g, order.getReversePost()->top());
                count++;
            } else {
                order.getReversePost()->pop();
            }
        }
    }
    ~KosarajuSCC() {
        cout << "~KosarajuSCC()" << endl;
        delete marked;
        delete id;
    }
    bool stronglyConnected(int v, int w) {
        return id->at(v) == id->at(w);
    }
    vector<int> * getId() {
        return id;
    }
    int getVId(int v) {
        return id->at(v);
    }
    int getCount() {
        return count;
    }
private:
    vector<bool> * marked;
    vector<int> * id;
    int count = 0;
    void dfs(Digraph * g, int v) {
        marked->at(v) = true;
        id->at(v) = count;
        for (int w = 0; w < g->adj->at(v)->size(); w++) {
            if (marked->at(g->adj->at(v)->at(w)) == false) {
                dfs(g, g->adj->at(v)->at(w));
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Digraph * g = new Digraph(13);
    g->addEdge(0, 5);
    g->addEdge(0, 1);
    g->addEdge(2, 0);
    g->addEdge(2, 3);
    g->addEdge(3, 2);
    g->addEdge(3, 5);
    g->addEdge(4, 3);
    g->addEdge(5, 4);
    g->addEdge(6, 4);
    g->addEdge(6, 9);
    g->addEdge(7, 6);
    g->addEdge(7, 8);
    g->addEdge(8, 7);
    g->addEdge(8, 9);
    g->addEdge(9, 10);
    g->addEdge(9, 11);
    g->addEdge(10, 12);
    g->addEdge(11, 12);
    g->addEdge(12, 9);
    
    g->show();
    
    KosarajuSCC kjscc = KosarajuSCC(g);
    for (int i = 0; i < kjscc.getId()->size(); i++) {
        cout << kjscc.getId()->at(i) << " " << endl;
    }
    cout << endl;
    
    return 0;
}
