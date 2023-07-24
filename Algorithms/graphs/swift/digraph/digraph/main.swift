//
//  main.swift
//  digraph
//
//  Created by gmy on 2023/7/24.
//

import Foundation

print("Hello, World!")

var g = Digraph(13)
g.addEdge(0, 5)
g.addEdge(0, 1)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 5)
g.addEdge(3, 2)
g.addEdge(4, 2)
g.addEdge(4, 3)
g.addEdge(5, 4)
g.addEdge(6, 0)
g.addEdge(6, 4)
g.addEdge(6, 9)
g.addEdge(7, 6)
g.addEdge(7, 8)
g.addEdge(8, 7)
g.addEdge(8, 9)
g.addEdge(9, 10)
g.addEdge(9, 11)
g.addEdge(10, 12)
g.addEdge(11, 4)
g.addEdge(11, 12)
g.addEdge(12, 9)

g.show()

//var digraph = g.reverse()
//digraph.show()
/**
 有向图深度搜索
 */
/// MARK: dfs
print("***********dfs begin***********")
var dfs = DirectedDFS(g: &g, s: 0)
for i in 0..<g.getV() {
    print("(\(i) : \(dfs.getMarked(i)))")
}
print("***********dfs end***********")

/**
 有向图环的判断
 */
/// MARK: has cycle
print("******hasCycle bengin***************")
var cycleG = Digraph(13)
cycleG.addEdge(0, 5)
cycleG.addEdge(0, 1)
cycleG.addEdge(2, 0)
cycleG.addEdge(2, 3)
cycleG.addEdge(3, 5)
cycleG.addEdge(3, 2)
cycleG.addEdge(4, 3)
cycleG.addEdge(4, 2)
cycleG.addEdge(5, 4)
cycleG.addEdge(6, 0)
cycleG.addEdge(6, 4)
cycleG.addEdge(6, 9)
cycleG.addEdge(7, 6)
cycleG.addEdge(7, 8)
cycleG.addEdge(8, 7)
cycleG.addEdge(8, 9)
cycleG.addEdge(9, 10)
cycleG.addEdge(9, 11)
cycleG.addEdge(10, 12)
cycleG.addEdge(11, 4)
cycleG.addEdge(11, 12)
cycleG.addEdge(12, 9)

cycleG.show()

var cycle = DirectedCycle(g: &cycleG)
if cycle.hasCycle() {
    if var cycle = cycle.getCycle() {
        while let empty = cycle.isEmpty(), !empty {
            print(cycle.pop())
        }
    }
}

print("******hasCycle end***************")


print("end")
