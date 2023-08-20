//
//  main.swift
//  EdgeWeightedDiGraph
//
//  Created by GMY on 2023/8/17.
//

import Foundation

print("Hello, World!")

var g = EdgeWeightedDigraph(V: 8)
g.addEdges(DirectedEdge(0, 2, 0.26))
g.addEdges(DirectedEdge(0, 4, 0.38))
g.addEdges(DirectedEdge(1, 3, 0.29))
g.addEdges(DirectedEdge(2, 7, 0.34))
g.addEdges(DirectedEdge(3, 6, 0.52))
g.addEdges(DirectedEdge(4, 7, 0.37))
g.addEdges(DirectedEdge(4, 5, 0.35))
g.addEdges(DirectedEdge(5, 1, 0.32))
g.addEdges(DirectedEdge(5, 7, 0.28))
g.addEdges(DirectedEdge(5, 4, 0.35))
g.addEdges(DirectedEdge(6, 4, 0.93))
g.addEdges(DirectedEdge(6, 0, 0.58))
g.addEdges(DirectedEdge(6, 2, 0.40))
g.addEdges(DirectedEdge(7, 3, 0.39))
g.addEdges(DirectedEdge(7, 5, 0.28))

g.show()

let sp = DijkstraSP(g: &g, s: 0)
sp.show()
