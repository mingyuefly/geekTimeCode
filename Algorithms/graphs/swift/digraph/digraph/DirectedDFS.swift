//
//  DirectedDFS.swift
//  digraph
//
//  Created by gmy on 2023/7/24.
//

import Foundation

class DirectedDFS {
    private var marked: [Bool]
    init(marked: [Bool]) {
        self.marked = marked
    }
    convenience init(g: inout Digraph, s: Int) {
        let marked = [Bool](repeating: false, count: g.getV())
        self.init(marked: marked)
        dfs(&g, s)
    }
    private func dfs(_ g: inout Digraph, _ s: Int) {
        marked[s] = true
        g.adj[s].forEach { w in
            if !marked[w] {
                dfs(&g, w)
            }
        }
    }
    func getMarked(_ v: Int) -> Bool {
        return marked[v]
    }
}
