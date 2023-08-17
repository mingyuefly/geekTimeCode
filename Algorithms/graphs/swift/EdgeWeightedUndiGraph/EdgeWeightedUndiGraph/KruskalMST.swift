//
//  KruskalMST.swift
//  EdgeWeightedUndiGraph
//
//  Created by GMY on 2023/8/15.
//

import Foundation

class KruskalMST {
    private var mst: Queue<Edge>
    init(mst: Queue<Edge>) {
        self.mst = mst
    }
    convenience init(g: inout EdgeWeightedUndiGraph) {
        let mst = Queue<Edge>()
        self.init(mst: mst)
        let pq = MinPQ(maxSize: 100)
        g.getEdges().forEach { edge in
            pq.insert(edge)
        }
        let uf = UF(N: g.getV())
        while pq.isEmpty() == false && mst.count < g.getV() - 1 {
            if let edge = pq.deleteMin() {
                let v = edge.getEither()
                let w = edge.getOther(v)
                if uf.connected(v, w) {
                    continue
                }
                uf.union(v, w)
                self.mst.enqueue(edge)
            }
        }
    }
    func edges() -> Queue<Edge> {
        return mst
    }
}
