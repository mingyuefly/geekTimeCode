//
//  Graph.swift
//  DepthFirstPaths_swift
//
//  Created by gmy on 2023/7/22.
//

import Foundation

struct Graph {
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
        adj[w].append(v)
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
}
