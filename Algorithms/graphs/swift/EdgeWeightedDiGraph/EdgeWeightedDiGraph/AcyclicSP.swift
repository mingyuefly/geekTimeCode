//
//  AcyclicSP.swift
//  EdgeWeightedDiGraph
//
//  Created by GMY on 2023/8/27.
//

import Foundation

class AcyclicSP {
    private var edgeTo: [DirectedEdge]
    private var distTo: [Double]
    init(edgeTo: [DirectedEdge], distTo: [Double]) {
        self.edgeTo = edgeTo
        self.distTo = distTo
    }
    convenience init(g: inout EdgeWeightedDigraph, s: Int) {
        let edgeTo = [DirectedEdge](repeating: DirectedEdge(-1, -1, -1), count: g.getV())
        let distTo = [Double](repeating: Double.greatestFiniteMagnitude, count: g.getV())
        self.init(edgeTo: edgeTo, distTo: distTo)
        let topological = Topological(g: &g)
        if var order = topological.getOrder() {
            if let top = order.top() {
                self.distTo[top] = 0.0
            }
            while let isEmplty = order.isEmpty(), !isEmplty {
                if let v = order.pop() {
                    relax(&g, v)
                }
            }
        }
    }
    private func relax(_ g: inout EdgeWeightedDigraph, _ v: Int) {
        for edge in g.adj[v] {
            let w = edge.to()
            if distTo[w] > distTo[v] + edge.getWeight() {
                distTo[w] = distTo[v] + edge.getWeight()
                edgeTo[w] = edge
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
        for i in 0..<edgeTo.count {
            let e = edgeTo[i]
            if e.from() != -1 && e.to() != -1 {
                print("\(i) \(e.from())--\(e.to()) \(String(format:"%.2f",distTo[i]))")
            } else {
                print("\(i)")
            }
        }
    }
}
