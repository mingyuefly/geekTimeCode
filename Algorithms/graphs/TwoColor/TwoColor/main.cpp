//
//  main.cpp
//  TwoColor
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

class TwoColor {
public:
    TwoColor() {
        
    }
    TwoColor(Graph * g) {
        marked = new vector<bool>(g->getV(), false);
        color = new vector<bool>(g->getV(), false);
        for (int s = 0; s < g->getV(); s++) {
            if (marked->at(s) == false) {
                dfs(g, s);
            }
        }
    }
    ~TwoColor() {
        cout << "~TwoColor()" << endl;
        delete marked;
        delete color;
    }
    bool getIsTwoColorable() {
        return isTwoColorable;
    }
private:
    vector<bool> * marked;
    vector<bool> * color;
    bool isTwoColorable = true;
    void dfs(Graph * g, int v) {
        marked->at(v) = true;
        for (int w = 0; w < g->adj->at(v)->size(); w++) {
            if (marked->at(g->adj->at(v)->at(w)) == false) {
                color->at(g->adj->at(v)->at(w)) = !color->at(v);
                dfs(g, g->adj->at(v)->at(w));
            } else if (color->at(g->adj->at(v)->at(w)) == color->at(v)) {
                isTwoColorable = false;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    
    Graph * g = new Graph(4);
    g->addEdge(0, 1);
    g->addEdge(1, 2);
    g->addEdge(2, 3);
    g->addEdge(3, 0);
//    g->addEdge(1, 3);
    g->show();
    
    TwoColor twoColor = TwoColor(g);
    cout << twoColor.getIsTwoColorable() << endl;
    
    
    delete g;
    
    return 0;
}
