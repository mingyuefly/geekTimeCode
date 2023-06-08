//
//  SequentialSearchST.swift
//  SequentialSearchST_swift
//
//  Created by gmy on 2023/6/7.
//

import Foundation

class Node {
    var key: ComparableObject = ComparableObject(value: -1)
    var value: Int = -1
    var next: Node?
    init(key: ComparableObject, value: Int, next: Node? = nil) {
        self.key = key
        self.value = value
        self.next = next
    }
    deinit {
        print("deinit")
    }
}

class SequentialSearchST {
    private var first: Node?
    func get(_ key: ComparableObject) -> Int {
        var head = first
        while (head != nil) {
            if let head = head, head.key.equal(key) {
                return head.value
            }
            head = head?.next
        }
        return -1
    }
    func put(_ key: ComparableObject, _ val: Int) {
        var head = first
        while (head != nil) {
            if let head = head, head.key.equal(key) {
                head.value = val
                break
            }
            head = head?.next
        }
        first = Node(key: key, value: val, next: first)
    }
    func deleteKey(_ key: ComparableObject) {
        var pre = first
        var head = first
        while head != nil {
            if let head = head, head.key.equal(key) {
                if let first = first, first.key.equal(key) {
                    self.first = head.next
                } else {
                    pre?.next = head.next
                }
                break
            }
            pre = head
            head = head?.next
        }
    }
    func show() {
        var head = first
        while head != nil {
            if let head = head {
                print("(" + String(head.key.value) + ":" + String(head.value) + ")")
            }
            head = head?.next
        }
        print("")
    }
}
