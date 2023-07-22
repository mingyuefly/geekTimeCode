//
//  DepthFirstPaths.swift
//  DepthFirstPaths_swift
//
//  Created by gmy on 2023/7/22.
//

import Foundation

class DepthFirstPaths {
    private var marked: [Bool]
    private var edgeTo: [Int] // 从起点到一个顶点的已知路径上的最后一个顶点
    private var s: Int // 起点

    init(marked: [Bool], edgeTo: [Int], s: Int) {
        self.marked = marked
        self.edgeTo = edgeTo
        self.s = s
    }
    convenience init(g: inout Graph, s: Int) {
        let marked = [Bool](repeating: false, count: g.getV())
        let edgeTo = [Int](repeating: 0, count: g.getV())
        self.init(marked: marked, edgeTo: edgeTo, s: s)
        dfs(&g, s)
    }
    private func dfs(_ g: inout Graph, _ v: Int) {
        marked[v] = true
        g.adj[v].forEach { v1 in
            if !marked[v1] {
                edgeTo[v1] = v
                dfs(&g, v1)
            }
        }
    }
    func hasPathsTo(_ v: Int) -> Bool {
        return marked[v]
    }
    func showEdge() {
        for i in 0..<edgeTo.count {
            print("(\(i):\(edgeTo[i]))")
        }
    }
    func pathTo(_ v: Int) -> Stack<Int> {
        var stack = Stack<Int>()
        stack.push(v)
        var w = v
        while w != s {
            stack.push(edgeTo[w])
            w = edgeTo[w]
        }
        return stack
    }
}


//class DepthFirstPaths {
//    private var marked: [Bool]
//    private var count: Int = 0
//    init(marked: [Bool]) {
//        self.marked = marked
//    }
//    convenience init(g: inout Graph, s: Int) {
//        var marked = [Bool](repeating: false, count: g.getV())
//        self.init(marked: marked)
//        dfs(&g, s)
//    }
//    func dfs(_ g: inout Graph, _ v: Int) {
//        marked[v] = true
//        count += 1
//        g.adj[v].forEach { v1 in
//            if !marked[v1] {
//                dfs(&g, v1)
//            }
//        }
//    }
//    func getMarked(_ v: Int) -> Bool {
//        return marked[v]
//    }
//    func getCount() -> Int {
//        return count
//    }
//}
