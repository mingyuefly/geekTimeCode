//
//  Node.swift
//  separateChainingHashST_swift
//
//  Created by gmy on 2023/6/27.
//

import Foundation

class Node {
    var key: ComparableObject
    var value: Int
    var next: Node?
    init(key: ComparableObject, value: Int, next: Node? = nil) {
        self.key = key
        self.value = value
        self.next = next
    }
    deinit {
        print("Node deinit")
    }
}
