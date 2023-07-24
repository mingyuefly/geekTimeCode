//
//  DiGraph.swift
//  digraph
//
//  Created by gmy on 2023/7/24.
//

import Foundation

struct Digraph {
    private var V: Int
    private var E: Int
    var adj: [Array<Int>]
    init(V: Int, E: Int, adj: [Array<Int>]) {
        self.V = V
        self.E = E
        self.adj = adj
    }
    init(_ V: Int) {
        self.init(V: V, E: 0, adj: [Array<Int>](repeating: Array<Int>(), count: V))
    }
    func getV() -> Int {
        return V
    }
    func getE() -> Int {
        return E
    }
    mutating func addEdge(_ v: Int, _ w: Int) {
        adj[v].append(w)
        E += 1
    }
    func show() {
        for i in 0..<adj.count {
            print("\(i) : ", terminator: "")
            adj[i].forEach { v in
                print("\(v) ", terminator: "")
            }
            print("")
        }
    }
    func reverse() -> Digraph {
        var digraph = Digraph(V)
        for i in 0..<V {
            adj[i].forEach { w in
                digraph.addEdge(w, i)
            }
        }
        return digraph
    }
}
