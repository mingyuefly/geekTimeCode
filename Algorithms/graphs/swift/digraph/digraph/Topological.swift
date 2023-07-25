//
//  Topological.swift
//  digraph
//
//  Created by gmy on 2023/7/25.
//

import Foundation

class Topological {
    private var order: Stack<Int>?
    init(order: Stack<Int>? = nil) {
        self.order = order
    }
    convenience init(g: inout Digraph) {      
        let cycleFinder = DirectedCycle(g: &g)
        if !cycleFinder.hasCycle() {
            let dfs = DepthFirstOrder(g: &g)
            let order = dfs.getReversePost()
            self.init(order: order)
        } else {
            self.init(order: nil)
        }
    }
    func getOrder() -> Stack<Int>? {
        return order
    }
    func isDAG() -> Bool {
        return order != nil
    }
}
