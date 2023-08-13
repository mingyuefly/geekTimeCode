//
//  PrimMST.swift
//  EdgeWeightedUndiGraph
//
//  Created by gmy on 2023/8/13.
//

import Foundation


class PrimMST {
    private var marked: [Bool]
    private var pq: IndexMinPQ
    private var edgeTo: [Edge]
    private var distTo: [Double]
    init(marked: [Bool], pq: IndexMinPQ, edgeTo: [Edge], distTo: [Double]) {
        self.marked = marked
        self.pq = pq
        self.edgeTo = edgeTo
        self.distTo = distTo
    }
    convenience init(g: inout EdgeWeightedUndiGraph) {
        let marked = [Bool](repeating: false, count: g.getV())
        let edgeTo = [Edge](repeating: Edge(v: -1, w: -1, weight: -1), count: g.getV())
        let pq = IndexMinPQ(maxSize: 100)
        let distTo = [Double](repeating: Double.greatestFiniteMagnitude, count: g.getV())
        self.init(marked: marked, pq: pq, edgeTo: edgeTo, distTo: distTo)
        self.distTo[0] = 0.0
        self.pq.insert(0, 0.0)
        while !pq.isEmpty() {
            visit(g, pq.deleteMin())
        }
    }
    func visit(_ g: EdgeWeightedUndiGraph, _ v: Int) {
        marked[v] = true
        for edge in g.adj[v] {
            let w = edge.getOther(v)
            if marked[w] {
                continue
            }
            if edge.getWeight() < distTo[w] {
                edgeTo[w] = edge
                distTo[w] = edge.getWeight()
                if pq.contains(w) {
                    pq.changeKey(w, distTo[w])
                } else {
                    pq.insert(w, distTo[w])
                }
            }
        }
    }
    func show() {
        for i in 1..<edgeTo.count {
            let edge = edgeTo[i]
            let v = edge.getEither()
            print("\(i) \(v)--\(edge.getOther(v)) \(distTo[i])")
        }
    }
}
