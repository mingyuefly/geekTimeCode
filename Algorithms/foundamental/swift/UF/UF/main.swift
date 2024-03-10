//
//  main.swift
//  UF
//
//  Created by GMY on 2023/8/16.
//

import Foundation

print("Hello, World!")

// UF
//var N = 11
//var uf = UF(N: N)
//uf.show()
//var p = 8
//var q = 5
//uf.union(p, q)
//if uf.connected(p, q) {
//    print(uf.find(p))
//}
//uf.show()
//var r = 3
//uf.union(p, r)
//if uf.connected(r, q) {
//    print(uf.find(r))
//}
//uf.show()

// quick UF
var N = 11
let uf = QuickUF(N: N)
uf.show()
var p = 8
var q = 5
uf.union(p, q);
if (uf.connected(p, q)) {
    print(uf.find(p))
}
uf.show()
var r = 3
uf.union(p, r)
if (uf.connected(r, q)) {
    print(uf.find(r))
}
uf.show()
