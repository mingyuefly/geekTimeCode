//
//  LazyPrimMST.swift
//  EdgeWeightedUndiGraph
//
//  Created by GMY on 2023/8/6.
//

import Foundation

class LazyPrimMST {
    private var marked: [Bool]
    private var mst: Queue<Edge>
    private var pq: MinPQ
    var edges: Queue<Edge> {
        return mst
    }
    init(marked: [Bool], mst: Queue<Edge>, pq: MinPQ) {
        self.marked = marked
        self.mst = mst
        self.pq = pq
    }
    convenience init(g: inout EdgeWeightedUndiGraph) {
        let marked = [Bool](repeating: false, count: g.getV())
        let mst = Queue<Edge>()
        let pq = MinPQ(maxSize: 100)
        self.init(marked: marked, mst: mst, pq: pq)
        visit(&g, 0)
        while !self.pq.isEmpty() {
            if let edge = self.pq.deleteMin() {
                let v = edge.getEither()
                let w = edge.getOther(v)
                if self.marked[v] && self.marked[w] {
                    // 跳过失效边
                    continue
                }
                self.mst.enqueue(edge)
                if !self.marked[v] {
                    visit(&g, v)
                }
                if !self.marked[w] {
                    visit(&g, w)
                }
            }
        }
    }
    private func visit(_ g: inout EdgeWeightedUndiGraph, _ v: Int) {
        marked[v] = true
        g.adj[v].forEach { edge in
            if !marked[edge.getOther(v)] {
                pq.insert(edge)
            }
        }
    }
}
