//
//  DijkstraSP.swift
//  EdgeWeightedDiGraph
//
//  Created by GMY on 2023/8/20.
//

import Foundation

class DijkstraSP {
    private var edgeTo: [DirectedEdge]
    private var distTo: [Double]
    private var pq: IndexMinPQ
    init(edgeTo: [DirectedEdge], distTo: [Double], pq: IndexMinPQ) {
        self.edgeTo = edgeTo
        self.distTo = distTo
        self.pq = pq
    }
    convenience init(g: inout EdgeWeightedDigraph, s: Int) {
        let edgeTo = [DirectedEdge](repeating: DirectedEdge(-1, -1, -1), count: g.getV())
        let distTo = [Double](repeating: Double.greatestFiniteMagnitude, count: g.getV())
        let pq = IndexMinPQ(maxSize: 100)
        self.init(edgeTo: edgeTo, distTo: distTo, pq: pq)
        self.distTo[s] = 0.0;
        self.pq.insert(s, 0.0)
        while !self.pq.isEmpty() {
            relax(&g, self.pq.deleteMin())
        }
    }
    private func relax(_ g: inout EdgeWeightedDigraph, _ v: Int) {
        for edge in g.adj[v] {
            let w = edge.to()
            if distTo[w] > distTo[v] + edge.getWeight() {
                distTo[w] = distTo[v] + edge.getWeight()
                edgeTo[w] = edge
                if pq.contains(w) {
                    pq.changeKey(w, distTo[w])
                } else {
                    pq.insert(w, distTo[w])
                }
            }
        }
    }
    func distTo(_ v: Int) -> Double {
        return distTo[v]
    }
    func hasPathTo(_ v: Int) -> Bool {
        return distTo[v] < Double.greatestFiniteMagnitude
    }
    func show() {
        for i in 1..<edgeTo.count {
            print("\(i) (\(edgeTo[i].from())--\(edgeTo[i].to())) \(String(format:"%.2f",distTo[i]))")
        }
    }
}
