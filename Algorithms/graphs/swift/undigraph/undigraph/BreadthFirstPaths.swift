//
//  BreadthFirstPaths.swift
//  DepthFirstPaths_swift
//
//  Created by gmy on 2023/7/23.
//

import Foundation

class BreadthFirstPaths {
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
        bfs(&g, s)
    }
    func bfs(_ g: inout Graph, _ v: Int) {
        var queue = Queue<Int>()
        marked[v] = true
        queue.enqueue(v)
        while !queue.isEmpty() {
            if let w = queue.dequeue() {
                g.adj[w].forEach { w1 in
                    if !marked[w1] {
                        edgeTo[w1] = w
                        marked[w1] = true // 一旦访问到立即标记
                        queue.enqueue(w1)
                    }
                }
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
