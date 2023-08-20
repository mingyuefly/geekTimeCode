//
//  EdgeWeightedDigraph.swift
//  EdgeWeightedDiGraph
//
//  Created by GMY on 2023/8/17.
//

import Foundation

struct EdgeWeightedDigraph {
    private var V: Int
    private var E: Int
    private var edges: [DirectedEdge]
    var adj: [[DirectedEdge]]
    init(V: Int, E: Int, edges: [DirectedEdge], adj: [[DirectedEdge]]) {
        self.V = V
        self.E = E
        self.edges = edges
        self.adj = adj
    }
    init(V: Int) {
        let edges = [DirectedEdge]()
        let adj = [[DirectedEdge]](repeating: [DirectedEdge](), count: V)
        self.init(V: V, E: 0, edges: edges, adj: adj)
    }
    mutating func addEdges(_ e: DirectedEdge) {
        adj[e.from()].append(e)
        E += 1
    }
    func getV() -> Int {
        return V
    }
    func getE() -> Int {
        return E
    }
    mutating func getEdges() -> [DirectedEdge] {
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
