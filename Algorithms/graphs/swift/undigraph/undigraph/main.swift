//
//  main.swift
//  DepthFirstPaths_swift
//
//  Created by gmy on 2023/7/22.
//

import Foundation

print("Hello, World!")

var g = Graph(6)
//var g = Graph(8)
g.addEdge(0, 2)
g.addEdge(0, 1)
g.addEdge(0, 5)
g.addEdge(2, 1)
g.addEdge(2, 3)
g.addEdge(2, 4)
g.addEdge(3, 4)
g.addEdge(3, 5)
//g.addEdge(7, 6)

g.show()
print(g.getV())
print(g.getE())

/// MARK: depth first paths
/**
 depth first paths
 */

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

/// MARK: breadth first paths
/**
 breadth first paths
 */

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


print("end")
