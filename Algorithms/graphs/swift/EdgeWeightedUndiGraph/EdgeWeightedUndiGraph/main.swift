//
//  main.swift
//  EdgeWeightedUndiGraph
//
//  Created by gmy on 2023/7/26.
//

import Foundation

print("Hello, World!")

var g = EdgeWeightedUndiGraph(V: 8)
g.addEdge(Edge(v: 4, w: 5, weight: 0.35))
g.addEdge(Edge(v: 4, w: 7, weight: 0.37))
g.addEdge(Edge(v: 5, w: 7, weight: 0.28))
g.addEdge(Edge(v: 0, w: 7, weight: 0.16))
g.addEdge(Edge(v: 1, w: 5, weight: 0.32))
g.addEdge(Edge(v: 0, w: 4, weight: 0.38))
g.addEdge(Edge(v: 2, w: 3, weight: 0.17))
g.addEdge(Edge(v: 1, w: 7, weight: 0.19))
g.addEdge(Edge(v: 0, w: 2, weight: 0.26))
g.addEdge(Edge(v: 1, w: 2, weight: 0.36))
g.addEdge(Edge(v: 1, w: 3, weight: 0.29))
g.addEdge(Edge(v: 2, w: 7, weight: 0.34))
g.addEdge(Edge(v: 6, w: 2, weight: 0.40))
g.addEdge(Edge(v: 3, w: 6, weight: 0.52))
g.addEdge(Edge(v: 6, w: 0, weight: 0.58))
g.addEdge(Edge(v: 6, w: 4, weight: 0.93))

g.show()

var lMST = LazyPrimMST(g: &g)
var edges = lMST.edges
while !edges.isEmpty() {
    if let e: Edge = edges.dequeue() {
        print(e.toString())
    }
}
