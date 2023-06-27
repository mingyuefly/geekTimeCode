//
//  SeparateChainingHashST.swift
//  separateChainingHashST_swift
//
//  Created by gmy on 2023/6/27.
//

import Foundation

class SequentialSearchST {
    private var firstNode: Node?
    init(firstNode: Node? = nil) {
        self.firstNode = firstNode
    }
    deinit {
        print("SequentialSearchST deinit")
    }
    fileprivate func get(key: ComparableObject) -> Int {
        var head = firstNode
        while let head1 = head {
            if key.equal(head1.key) {
                return head1.value
            }
            head = head1.next
        }
        return -1
    }
    fileprivate func put(key: ComparableObject, value: Int) {
        var head = firstNode
        while let head1 = head {
            if key.equal(head1.key) {
                head1.value = value
                return
            }
            head = head1.next
        }
        self.firstNode = Node(key: key, value: value, next: self.firstNode)
    }
    fileprivate func delete(_ key: ComparableObject) {
        var head = firstNode
        var pre = firstNode
        while let head1 = head {
            if key.equal(head1.key) {
                pre?.next = head1.next
                return
            }
            head = head1.next
            pre = head1
        }
    }
    fileprivate func show() {
        var head = firstNode
        while let head1 = head {
            let s = "(" + String(head1.key.value) + ":" + String(head1.value) + ")"
            print(s, terminator: " ")
            head = head1.next
        }
        print("")
    }
}

class SeparateChainingHashST {
    private var N: Int?
    private var M: Int = 0
    private var sts: [SequentialSearchST] = [SequentialSearchST]()
    init(N: Int? = nil, M: Int) {
        self.N = N
        self.M = M
        for _ in 0..<M {
            let st = SequentialSearchST()
            sts.append(st)
        }
    }
    deinit {
        print("SeparateChainingHashST deinit")
    }
    func get(_ key: ComparableObject) -> Int {
        return sts[hash(key)].get(key: key)
    }
    func put(_ key: ComparableObject, _ value: Int) {
        sts[hash(key)].put(key: key, value: value)
    }
    func delete(_ key: ComparableObject) {
        sts[hash(key)].delete(key)
    }
    func show() {
        sts.forEach { st in
            st.show()
        }
    }
    private func hash(_ key: ComparableObject) -> Int {
        return key.value % 1000
    }
}
