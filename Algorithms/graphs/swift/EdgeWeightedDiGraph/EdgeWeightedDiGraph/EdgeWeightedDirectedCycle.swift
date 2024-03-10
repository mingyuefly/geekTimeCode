//
//  EdgeWeightedDirectedCycle.swift
//  EdgeWeightedDiGraph
//
//  Created by GMY on 2023/8/30.
//

import Foundation

class EdgeWeightedDirectedCycle {
    private var marked: [Bool]
    private var edgeTo: [DirectedEdge]
    private var onStack: [Bool]
    private var cycle: Stack<DirectedEdge>?
    init(marked: [Bool], edgeTo: [DirectedEdge], onStack: [Bool], cycle: Stack<DirectedEdge>?) {
        self.marked = marked
        self.edgeTo = edgeTo
        self.onStack = onStack
        self.cycle = cycle
    }
    convenience init(g: inout EdgeWeightedDigraph) {
        let marked = [Bool](repeating: false, count: g.getV())
        let edgeTo = [DirectedEdge](repeating: DirectedEdge(-1, -1, -1), count: g.getV())
        let onStack = [Bool](repeating: false, count: g.getV())
        self.init(marked: marked, edgeTo: edgeTo, onStack: onStack, cycle: nil)
        for v in 0..<g.getV() {
            if !self.marked[v] {
                dfs(&g, v)
            }
        }
    }
    func dfs(_ g: inout EdgeWeightedDigraph, _ v: Int) {
        onStack[v] = true
        marked[v] = true
        for e in g.adj[v] {
            let w = e.to()
            if cycle != nil {
                return
            } else if !marked[w] {
                edgeTo[w] = e
                dfs(&g, w)
            } else if onStack[w] {
                cycle = Stack<DirectedEdge>()
                var f = e
                while f.from() != w {
                    cycle?.push(f)
                    f = edgeTo[f.from()]
                }
                cycle?.push(f)
                return
            }
        }
        onStack[v] = false
    }
    func getCycle() -> Stack<DirectedEdge>? {
        return cycle
    }
}
