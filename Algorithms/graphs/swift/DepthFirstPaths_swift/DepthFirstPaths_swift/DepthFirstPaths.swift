//
//  DepthFirstPaths.swift
//  DepthFirstPaths_swift
//
//  Created by gmy on 2023/7/22.
//

import Foundation

class DepthFirstPaths {
    private var marked: [Bool]
    private var count: Int = 0
    init(marked: [Bool]) {
        self.marked = marked
    }
    convenience init(g: inout Graph, s: Int) {
        var marked = [Bool](repeating: false, count: g.getV())
        self.init(marked: marked)
        dfs(&g, s)
    }
    func dfs(_ g: inout Graph, _ v: Int) {
        marked[v] = true
        count += 1
        g.adj[v].forEach { v1 in
            if !marked[v1] {
                dfs(&g, v1)
                marked[v1] = true
            }
        }
    }
    func getMarked(_ v: Int) -> Bool {
        return marked[v]
    }
    func getCount() -> Int {
        return count
    }
}
