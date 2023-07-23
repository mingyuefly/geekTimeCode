//
//  Cycle.swift
//  undigraph
//
//  Created by gmy on 2023/7/23.
//

import Foundation

class Cycle {
    private var marked: [Bool]
    private var hasCycle: Bool
    init(marked: [Bool], hasCycle: Bool) {
        self.marked = marked
        self.hasCycle = hasCycle
    }
    convenience init(g: inout Graph) {
        let marked = [Bool](repeating: false, count: g.getV())
        self.init(marked: marked, hasCycle: false)
        for i in 0..<g.getV() {
            if !self.marked[i] {
                dfs(&g, i, i)
            }
        }
    }
    private func dfs(_ g: inout Graph, _ v: Int, _ u: Int) {
        marked[v] = true
        g.adj[v].forEach { w in
            if !marked[w] {
                // v和w相连
                dfs(&g, w, v)
            } else if w != u {
                // w已经被标记，w又不等于u，
                hasCycle = true
            }
        }
    }
    func getHasCycle() -> Bool {
        return hasCycle
    }
}
