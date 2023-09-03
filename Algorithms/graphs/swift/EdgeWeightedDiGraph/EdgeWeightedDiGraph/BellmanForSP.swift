//
//  BellmanForSP.swift
//  EdgeWeightedDiGraph
//
//  Created by GMY on 2023/8/30.
//

import Foundation

class BellmanForSP {
    private var distTo: [Double]
    private var edgeTo: [DirectedEdge]
    private var onQ: [Bool]
    private var myQueue: Queue<Int>
    private var cost: Int
    private var cycle: Stack<DirectedEdge>?
    init(distTo: [Double], edgeTo: [DirectedEdge], onQ: [Bool], myQueue: Queue<Int>, cost: Int, cycle: Stack<DirectedEdge>?) {
        self.distTo = distTo
        self.edgeTo = edgeTo
        self.onQ = onQ
        self.myQueue = myQueue
        self.cost = cost
        self.cycle = cycle
    }
    convenience init(g: inout EdgeWeightedDigraph, s: Int) {
        let distTo = [Double](repeating: Double.greatestFiniteMagnitude, count: g.getV())
        let edgeTo = [DirectedEdge](repeating: DirectedEdge(-1, -1, -1), count: g.getV())
        let onQ = [Bool](repeating: false, count: g.getV())
        let myQueue = Queue<Int>()
        let cost = 0
        self.init(distTo: distTo, edgeTo: edgeTo, onQ: onQ, myQueue: myQueue, cost: cost, cycle: nil)
        self.distTo[s] = 0.0
        self.myQueue.enqueue(s)
        self.onQ[s] = true
        while !self.myQueue.isEmpty() && !hasNegativeCycle() {
            if let v = self.myQueue.dequeue() {
                self.onQ[v] = false
                relax(&g, v)
            }
        }
    }
    func getDistTo(_ v: Int) -> (Bool, Double) {
        if v < 0 || v > g.getV() {
            return (false, Double.greatestFiniteMagnitude)
        }
        return (true, distTo[v])
    }
    func hasPathTo(_ v: Int) -> Bool {
        if v < 0 || v > g.getV() {
            return false
        }
        return distTo[v] < Double.greatestFiniteMagnitude
    }
    func pathTo(_ v: Int) -> Stack<DirectedEdge>? {
        if v < 0 || v > g.getV() {
            print("Negative cost cycle exists")
            return nil
        }
        if !hasPathTo(v) {
            return nil
        }
        var path = Stack<DirectedEdge>()
        var e = edgeTo[v]
//        path.push(e)
        while e.from() != -1 && e.to() != -1 {
            path.push(e)
            e = edgeTo[e.from()]
        }
        return path
    }
    func show() {
        for i in 0..<edgeTo.count {
            let e = edgeTo[i]
            if e.from() != -1 && e.to() != -1 {
                print("\(i) \(e.from()) -- \(e.to()) \(String(format:"%.2f",distTo[i]))")
            } else {
                print("\(i)")
            }
        }
    }
    private func relax(_ g: inout EdgeWeightedDigraph, _ v: Int) {
        for edge in g.adj[v] {
            let w = edge.to()
            if distTo[w] > distTo[v] + edge.getWeight() {
                distTo[w] = distTo[v] + edge.getWeight()
                edgeTo[w] = edge
                if !onQ[w] {
                    myQueue.enqueue(w)
                    onQ[w] = true
                }
                if cost % g.getV() == 0 {
                    cost += 1
                    findNegativeCycle()
                }
            }
        }
    }
    private func findNegativeCycle() {
        let V = edgeTo.count
        var g1 = EdgeWeightedDigraph(V: V)
        for v in 0..<V {
            if edgeTo[v].from() != -1 && edgeTo[v].to() != -1 {
                g1.addEdges(edgeTo[v])
            }
        }
        let cycleFinder = EdgeWeightedDirectedCycle(g: &g1)
        cycle = cycleFinder.getCycle()
    }
    func hasNegativeCycle() -> Bool {
        return cycle != nil
    }
    func getNegativeCycle() -> Stack<DirectedEdge>? {
        return cycle
    }
}
