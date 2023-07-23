//
//  main.swift
//  DepthFirstPaths_swift
//
//  Created by gmy on 2023/7/22.
//

import Foundation

print("Hello, World!")

//var g = Graph(6)
var g = Graph(8)
g.addEdge(0, 2)
g.addEdge(0, 1)
g.addEdge(0, 5)
g.addEdge(2, 1)
g.addEdge(2, 3)
g.addEdge(2, 4)
g.addEdge(3, 4)
g.addEdge(3, 5)
g.addEdge(7, 6)

g.show()
print(g.getV())
print(g.getE())

/// MARK: depth first paths
/**
 depth first paths
 */
print("*****************depth first paths begin******************")
//let depthFirstPaths = DepthFirstPaths(g: &g, s: 0)
//for i in 0..<g.getV() {
//    if depthFirstPaths.getMarked(i) {
//        print("\(i) ", terminator: "")
//    }
//}
//print("")

let depthFirstPaths = DepthFirstPaths(g: &g, s: 0)
for i in 0..<g.getV() {
    print("0 has path to \(i) : \(depthFirstPaths.hasPathsTo(i))")
}

//let depthFirstPaths1 = DepthFirstPaths(g: &g, s: 6)
//for i in 0..<g.getV() {
//    print("6 has path to \(i) : \(depthFirstPaths1.hasPathsTo(i))")
//}

depthFirstPaths.showEdge()

var dPath = depthFirstPaths.pathTo(5)
while let empty = dPath.isEmpty(), !empty {
    print(dPath.pop())
}
print("*****************depth first paths end******************")

/// MARK: breadth first paths
/**
 breadth first paths
 */
print("*****************breadth first paths begin******************")
let breadthFirstPaths = BreadthFirstPaths(g: &g, s: 0)
for i in 0..<g.getV() {
    print("0 has path to \(i) : \(breadthFirstPaths.hasPathsTo(i))")
}
breadthFirstPaths.showEdge()

//let breadthFirstPaths1 = BreadthFirstPaths(g: &g, s: 6)
//for i in 0..<g.getV() {
//    print("6 has path to \(i) : \(breadthFirstPaths1.hasPathsTo(i))")
//}
//breadthFirstPaths1.showEdge()

var bPath = breadthFirstPaths.pathTo(5)
while let empty = bPath.isEmpty(), !empty {
    print(bPath.pop())
}
print("*****************breadth first paths end******************")

/**
    CC 查看图中连通分量
 */
/// MARK: CC
print("*****************CC begin******************")
let cc = CC(&g)
cc.showIds()
print("*****************CC end******************")

/**
 查看无向图中是否有环
 */
/// MARK: Cycle
print("*****************Cycle begin******************")
var g1 = Graph(13)
g1.addEdge(0, 2)
g1.addEdge(0, 1)
g1.addEdge(0, 5)
g1.addEdge(0, 6)
g1.addEdge(3, 4)
g1.addEdge(3, 5)
g1.addEdge(4, 5)
g1.addEdge(4, 6)
g1.addEdge(7, 8)
g1.addEdge(9, 10)
g1.addEdge(9, 11)
g1.addEdge(9, 12)
g1.addEdge(11, 12)
g1.show();

var cycle1 = Cycle(g: &g1);
print("g1 hasCycle: \(cycle1.getHasCycle())")
var cycle = Cycle(g: &g);
print("g hasCycle: \(cycle.getHasCycle())")
var g2 = Graph(5)
g2.addEdge(0, 2)
g2.addEdge(0, 1)
g2.addEdge(1, 3)
g2.addEdge(3, 4)
g2.show()
var cycle2 = Cycle(g: &g2);
print("g2 hasCycle: \(cycle2.getHasCycle())")
var g3 = Graph(5)
g3.addEdge(0, 2)
g3.addEdge(0, 1)
g3.addEdge(1, 3)
g3.addEdge(3, 4)
g3.addEdge(4, 2)
g3.show()
var cycle3 = Cycle(g: &g3);
print("g3 hasCycle: \(cycle3.getHasCycle())")

print("*****************Cycle end******************")


/**
 用两种颜色给图的所有顶点着色，是否可以使得每条边的两个端点是不同颜色，这个问题等价于这是否一幅二分图？
 */
/// MARK: TwoColor
print("*****************TwoColor begin******************")
var twoColorG = Graph(4)
twoColorG.addEdge(0, 1)
twoColorG.addEdge(1, 2)
twoColorG.addEdge(2, 3)
twoColorG.addEdge(3, 0)
//twoColorG.addEdge(1, 3)
twoColorG.show()

var twoColor = TwoColor(g: &twoColorG);
print("twoColorG isTwoColorable : \(twoColor.getIsTwoColorable())")
print("*****************TwoColor end******************")

print("end")
