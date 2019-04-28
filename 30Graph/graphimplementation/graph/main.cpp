//
//  main.cpp
//  graph
//
//  Created by Gguomingyue on 2019/2/21.
//  Copyright © 2019 Gmingyue. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>

#include "LinkedList.hpp"

using namespace std;

class Graph {
public:
    int v; //顶点个数
    LinkedList adj[100];
    Graph();
    Graph(int vp);
    ~Graph();
};

Graph::Graph(){
    
}

Graph::Graph(int vp){
    v = vp;
    
    for (int i = 0; i < 100; i++) {
        adj[i] = -1;
    }
}



int main(int argc, const char * argv[]) {

    
    LinkedList * list = new LinkedList();

    list->add(1);
    list->add(2);
    list->add(3);

    for(int i=0; i<list->size(); i++){
        cout << list->get(i) << endl;
    }

    delete list;
    
    return 0;
}
