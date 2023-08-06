//
//  EdgeWeightedUndiGraph.swift
//  EdgeWeightedUndiGraph
//
//  Created by gmy on 2023/7/26.
//

import Foundation

struct EdgeWeightedUndiGraph {
    private var V: Int
    private var E: Int
    private var edges: [Edge]
    var adj: [[Edge]]
    init(V: Int, E: Int, edges: [Edge], adj: [[Edge]]) {
        self.V = V
        self.E = E
        self.edges = edges
        self.adj = adj
    }
    init(V: Int) {
        let edges = [Edge]()
        let adj = [[Edge]](repeating: [Edge](), count: V)
        self.init(V: V, E: 0, edges: edges, adj: adj)
    }
    mutating func addEdge(_ e: Edge) {
        let v = e.getEither()
        let w = e.getOther(v)
        adj[v].append(e)
        adj[w].append(e)
        E += 1
    }
    func getV() -> Int {
        return V
    }
    func getE() -> Int {
        return E
    }
    mutating func getEdges() -> [Edge] {
//        edges.removeAll()
        if !edges.isEmpty {
            return edges
        }
        for v in 0..<V {
            adj[v].forEach { edge in
                edges.append(edge)
            }
        }
        return edges
    }
    func show() {
        for v in 0..<V {
            print("\(v):", terminator: "")
            adj[v].forEach { edge in
                print("(\(edge.toString())) ", terminator: "")
            }
            print("")
        }
    }
}
