//
//  DirectedCycle.swift
//  digraph
//
//  Created by gmy on 2023/7/24.
//

import Foundation


class DirectedCycle {
    private var marked: [Bool]
    private var edgeTo: [Int]
    private var cycle: Stack<Int>?
    private var onStack: [Bool]
    init(marked: [Bool], edgeTo: [Int], onStack: [Bool]) {
        self.marked = marked
        self.edgeTo = edgeTo
        self.onStack = onStack
    }
    convenience init(g: inout EdgeWeightedDigraph) {
        let marked = [Bool](repeating: false, count: g.getV())
        let edgeTo = [Int](repeating: 0, count: g.getV())
        let onStack = [Bool](repeating: false, count: g.getV())
        self.init(marked: marked, edgeTo: edgeTo, onStack: onStack)
        for v in 0..<g.getV() {
            dfs(&g, v)
        }
    }
    private func dfs(_ g: inout EdgeWeightedDigraph,_ v: Int) {
        onStack[v] = true
        marked[v] = true
        g.adj[v].forEach { e in
            if hasCycle() {
                return
            } else if !marked[e.to()] {
                edgeTo[e.to()] = v
                dfs(&g, e.to())
            } else if onStack[e.to()] {
                // w之前已经被访问过，再次被访问，说明有环存在
                cycle = Stack<Int>()
                cycle?.push(v)
                var x = v
                while x != e.to() {
                    cycle?.push(edgeTo[x])
                    x = edgeTo[x]
                }
                cycle?.push(v)
            }
        }
        onStack[v] = false
    }
    func hasCycle() -> Bool {
        return cycle != nil
    }
    func getCycle() -> Stack<Int>? {
        return cycle
    }
}
