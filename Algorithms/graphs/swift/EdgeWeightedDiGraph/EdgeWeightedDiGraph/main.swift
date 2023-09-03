//
//  main.swift
//  EdgeWeightedDiGraph
//
//  Created by GMY on 2023/8/17.
//

import Foundation

print("Hello, World!")

// DijkstraSP
//var g = EdgeWeightedDigraph(V: 8)
//g.addEdges(DirectedEdge(0, 2, 0.26))
//g.addEdges(DirectedEdge(0, 4, 0.38))
//g.addEdges(DirectedEdge(1, 3, 0.29))
//g.addEdges(DirectedEdge(2, 7, 0.34))
//g.addEdges(DirectedEdge(3, 6, 0.52))
//g.addEdges(DirectedEdge(4, 7, 0.37))
//g.addEdges(DirectedEdge(4, 5, 0.35))
//g.addEdges(DirectedEdge(5, 1, 0.32))
//g.addEdges(DirectedEdge(5, 7, 0.28))
//g.addEdges(DirectedEdge(5, 4, 0.35))
//g.addEdges(DirectedEdge(6, 4, 0.93))
//g.addEdges(DirectedEdge(6, 0, 0.58))
//g.addEdges(DirectedEdge(6, 2, 0.40))
//g.addEdges(DirectedEdge(7, 3, 0.39))
//g.addEdges(DirectedEdge(7, 5, 0.28))
//
//g.show()

//let sp = DijkstraSP(g: &g, s: 0)
//sp.show()

// AcyclicSP
//var g = EdgeWeightedDigraph(V: 8)
//g.addEdges(DirectedEdge(0, 2, 0.26))
//g.addEdges(DirectedEdge(1, 3, 0.29))
//g.addEdges(DirectedEdge(3, 6, 0.52))
//g.addEdges(DirectedEdge(3, 7, 0.39))
//g.addEdges(DirectedEdge(4, 0, 0.37))
//g.addEdges(DirectedEdge(4, 7, 0.37))
//g.addEdges(DirectedEdge(5, 1, 0.32))
//g.addEdges(DirectedEdge(5, 7, 0.28))
//g.addEdges(DirectedEdge(5, 4, 0.35))
//g.addEdges(DirectedEdge(6, 4, 0.93))
//g.addEdges(DirectedEdge(6, 0, 0.58))
//g.addEdges(DirectedEdge(6, 2, 0.40))
//g.addEdges(DirectedEdge(7, 2, 0.34))
//
//g.show()

//let topological = Topological(g: &g)
//if var order = topological.getOrder() {
//    while let isEmplty = order.isEmpty(), !isEmplty {
//        if let v = order.pop() {
//            print(v)
//        }
//    }
//}

//let sp = AcyclicSP(g: &g, s: 0)
//sp.show()

// BellmanForSP
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
g.addEdges(DirectedEdge(6, 4, -1.25))
g.addEdges(DirectedEdge(6, 0, -1.40))
g.addEdges(DirectedEdge(6, 2, -1.20))
g.addEdges(DirectedEdge(7, 3, 0.39))
g.addEdges(DirectedEdge(7, 5, 0.28))

g.show()

//var cycle = EdgeWeightedDirectedCycle(g: &g)
//if var cycle1 = cycle.getCycle() {
//    while let empty = cycle1.isEmpty(), !empty {
//        if let e = cycle1.pop() {
//            print("\(e.from())--\(e.to())")
//        }
//    }
//}


var sp = BellmanForSP(g: &g, s: 0)
if sp.hasNegativeCycle() {
    print("has a cycle")
    if var cycle1 = sp.getNegativeCycle() {
        while let empty = cycle1.isEmpty(), !empty {
            if let e = cycle1.pop() {
                print("\(e.from())--\(e.to())")
            }
        }
    }
} else {
    print("not has a cycle")
    for v in 0..<g.getV() {
        if sp.hasPathTo(v) {
            print("\(v):")
            if var path = sp.pathTo(v) {
                while let empty = path.isEmpty(), !empty {
                    if let e = path.pop()  {
                        print(e.toString())
                    }
                }
            }
        } else {
            print("\(v) has no path")
        }
    }
}
sp.show()
