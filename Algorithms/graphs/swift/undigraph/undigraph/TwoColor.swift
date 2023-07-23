//
//  TwoColor.swift
//  undigraph
//
//  Created by gmy on 2023/7/23.
//

import Foundation

class TwoColor {
    private var marked: [Bool]
    private var color: [Bool]
    private var isTwoColorable: Bool = true
    init(marked: [Bool], color: [Bool], isTwoColorable: Bool) {
        self.marked = marked
        self.color = color
        self.isTwoColorable = isTwoColorable
    }
    convenience init(g: inout Graph) {
        let marked = [Bool](repeating: false, count: g.getV())
        let color = [Bool](repeating: false, count: g.getV())
        self.init(marked: marked, color: color, isTwoColorable: true)
        for i in 0..<g.getV() {
            if !marked[i] {
                dfs(&g, i)
            }
        }
    }
    private func dfs(_ g: inout Graph, _ v: Int) {
        marked[v] = true
        g.adj[v].forEach { w in
            if !marked[w] {
                color[w] = !color[v]
                dfs(&g, w)
            } else if color[w] == color[v] {
                // w已经被标记过了，而w和v相邻而颜色不同，说明不是二分图
                isTwoColorable = false
            }
        }
    }
    func getIsTwoColorable() -> Bool {
        return isTwoColorable
    }
}
