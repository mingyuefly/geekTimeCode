//
//  main.cpp
//  CC
//
//  Created by mingyue on 2022/3/4.
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

class CC {
public:
    CC() {
        
    }
    CC(Graph * g) {
        marked = new vector<bool>(g->getV(), false);
        id = new vector<int>(g->getV());
        for (int i = 0; i < g->getV(); i++) {
            if (marked->at(i) == false) {
                dfs(g, i);
                count++;
            }
        }
    }
    ~CC() {
        cout << "~CC()" << endl;
        delete marked;
        delete id;
    }
    bool connected(int v, int w) {
        return id->at(v) == id->at(w);
    }
    int getId(int v) {
        return id->at(v);
    }
    int getCount() {
        return count;
    }
    void showIds() {
        for (int i = 0; i < id->size(); i++) {
            cout << "(" << i << ":" << id->at(i) << ")" << endl;
        }
    }
private:
    vector<bool> * marked;
    vector<int> * id;
    int count;
    void dfs(Graph * g, int v) {
        marked->at(v) = true;
        id->at(v) = count;
        for (int i = 0; i < g->adj->at(v)->size(); i++) {
            if (marked->at(g->adj->at(v)->at(i)) == false) {
                dfs(g, g->adj->at(v)->at(i));
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
    
    CC cc = CC(g);
    cc.showIds();
    
    cout << cc.getCount() << endl;
    
    delete g;
    
    return 0;
}
