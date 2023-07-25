//
//  SCC.swift
//  digraph
//
//  Created by gmy on 2023/7/25.
//

import Foundation

class KosarajuSCC {
    private var marked: [Bool]
    private var id: [Int]
    private var count: Int = 0
    init(marked: [Bool], id: [Int], count: Int) {
        self.marked = marked
        self.id = id
        self.count = count
    }
    convenience init(_ g: inout Digraph) {
        let marked = [Bool](repeating: false, count: g.getV())
        let id = [Int](repeating: 0, count: g.getV())
        self.init(marked: marked, id: id, count: 0)
        var gReverse = g.reverse()
        let order = DepthFirstOrder(g: &gReverse)
        order.getReversePost().forEach { s in
            if !self.marked[s] {
                dfs(&g, s)
                count += 1
            }
        }
    }
    func stronglyConnected(_ v: Int, _ w: Int) -> Bool {
        return id[v] == id[w]
    }
    func id(_ v: Int) -> Int {
        return id[v]
    }
    func getCount() -> Int {
        return count
    }
    func showIds() {
        for i in 0..<id.count {
            print("(\(i) : \(id[i]))")
        }
    }
    private func dfs(_ g: inout Digraph, _ s: Int) {
        marked[s] = true
        id[s] = count
        g.adj[s].forEach { v in
            if !marked[v] {
                dfs(&g, v)
            }
        }
    }
}
