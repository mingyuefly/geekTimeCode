//
//  main.swift
//  DepthFirstPaths_swift
//
//  Created by gmy on 2023/7/22.
//

import Foundation

print("Hello, World!")

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

let depthFirstPaths = DepthFirstPaths(g: &g, s: 0)
for i in 0..<g.getV() {
    if depthFirstPaths.getMarked(i) {
        print("\(i) ", terminator: "")
    }
}
print("")


print("end")
