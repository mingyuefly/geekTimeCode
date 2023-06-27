//
//  BinarySearchTree.swift
//  BinarySearchTree_swift
//
//  Created by gmy on 2023/6/7.
//

import Foundation

class BinarySearchTree {
    class Node {
        var key: ComparableObject = ComparableObject(value: -1)
        var value: Int = -1
        var left: Node?
        var right: Node?
        var N: Int = 0
        init(key: ComparableObject, value: Int, left: Node? = nil, right: Node? = nil, N: Int) {
            self.key = key
            self.value = value
            self.left = left
            self.right = right
            self.N = N
        }
        deinit {
            print("deinit")
        }
    }
    private var root: Node?
    func size() -> Int {
        if let root = root {
            return size(root)
        }
        return 0
    }
    func size(_ node: Node?) -> Int {
        guard let node = node else {
            return 0
        }
        return node.N
    }
    func get(_ key: ComparableObject) -> Int {
        return get(root, key)
    }
    func put(_ key: ComparableObject, _ val: Int) {
        root = put(root, key, val)
    }
    func min() -> ComparableObject {
        if let root = root {
            return min(root).key
        }
        return ComparableObject(value: -1)
    }
    func max() -> ComparableObject {
        if let root = root {
            return max(root).key
        }
        return ComparableObject(value: -1)
    }
    func floor(_ key: ComparableObject) -> ComparableObject {
        let node = floor(root, key)
        if let node = node {
            return node.key
        }
        return ComparableObject(value: -1)
    }
    func select(_ k: Int) -> ComparableObject {
        if let node = select(root, k) {
            return node.key
        }
        return ComparableObject(value: -1)
    }
    func rank(_ key: ComparableObject) -> Int {
        return rank(root, key)
    }
    func deleteMin() {
        guard let root1 = root else {
            return
        }
        root = deleteMin(root1)
    }
    func deleteKey(_ key: ComparableObject) {
        root = deleteKey(root, key)
    }
    func inOrder() {
        inOrder(root)
        print("")
    }
    func inOrderWithoutRecursion() {
        inOrderWithoutRecursion(root)
        print("")
    }
    func levelOrder() {
        levelOrder(root)
        print("")
    }
    func Iterable() -> Queue<ComparableObject> {
        return Iterable(min(), max())
    }
    func Iterable(_ lo: ComparableObject, _ hi: ComparableObject) -> Queue<ComparableObject> {
        guard let root = root else {
            return Queue()
        }
        var queue = Queue<ComparableObject>()
        Iterable(root, lo, hi, &queue)
        return queue
    }
    private func get(_ node: Node?, _ key: ComparableObject) -> Int {
        guard let node = node else {
            return -1
        }
        if node.key.more(key) {
            return get(node.left, key)
        } else if node.key.less(key) {
            return get(node.right, key) 
        } else {
            return node.value
        }
    }
    private func put(_ node: Node?, _ key: ComparableObject, _ val: Int) -> Node? {
        guard let node = node else {
            return Node(key: key, value: val, N: 1)
        }
        if node.key.more(key) {
            node.left = put(node.left, key, val)
        } else if node.key.less(key) {
            node.right = put(node.right, key, val)
        } else {
            node.value = val
        }
        node.N = size(node.left) + size(node.right) + 1
        return node
    }
    private func min(_ node: Node) -> Node {
        if let node = node.left {
            return min(node)
        }
        return node
    }
    private func max(_ node: Node) -> Node {
        if let node = node.right {
            return max(node)
        }
        return node
    }
    private func floor(_ node: Node?, _ key: ComparableObject) -> Node? {
        guard let node = node else {
            return node
        }
        if node.key.equal(key) {
            return node
        }
        if node.key.more(key){
            return floor(node.left, key)
        }
        let f = floor(node.right, key)
        if f != nil {
            return f
        }
        return node
    }
    private func select(_ node: Node?, _ k: Int) -> Node? {
        guard let node = node else {
            return node
        }
        let size = size(node.left)
        if size > k {
            return select(node.left, k)
        } else if size < k {
            return select(node.right, k)
        } else {
            return node
        }
    }
    private func rank(_ node: Node?, _ key: ComparableObject) -> Int {
        guard let node = node else {
            return 0
        }
        if node.key.more(key) {
            return rank(node.left, key)
        } else if node.key.less(key) {
            return rank(node.right, key) + size(node.left) + 1
        } else {
            return size(node.left)
        }
    }
    private func deleteMin(_ node: Node) -> Node? {
        if let left = node.left {
            node.left = deleteMin(left)
            node.N = size(node.left) + size(node.right) + 1
            return node
        } else {
            return node.right
        }
    }
    private func deleteKey(_ node: Node?, _ key: ComparableObject) -> Node? {
        guard var node = node else {
            return nil
        }
        if key.less(node.key) {
            node.left = deleteKey(node.left, key)
        } else if key.more(node.key) {
            node.right = deleteKey(node.right, key)
        } else {
            guard let right = node.right else {
                return node.left
            }
            guard node.left != nil else {
                return node.right
            }
            let t = node
            node = min(right)
            node.right = deleteMin(right)
            node.left = t.left
        }
        node.N = size(node.left) + size(node.right) + 1
        return node
    }
    private func inOrder(_ node: Node?) {
        guard let node = node else {
            return
        }
        inOrder(node.left)
        print(String(node.key.value) + ":" + String(node.value))
        inOrder(node.right)
    }
    private func inOrderWithoutRecursion(_ node: Node?) {
        guard let node = node else {
            return
        }
        var stack = Stack<Node>()
        stack.push(node)
        var tmp: Node? = node
        while stack.isEmpty() == false {
            while tmp != nil && tmp?.left != nil {
                if let left = tmp?.left {
                    stack.push(left)
                }
                tmp = tmp?.left
            }
            tmp = stack.pop()
            if let tmp = tmp {
                print(tmp.key.value)
            }
            if let right = tmp?.right {
                stack.push(right)
                tmp = right
            } else {
                tmp = nil
            }
        }
    }
    private func levelOrder(_ node: Node?) {
        guard let node = node else {
            return
        }
        var queue = Queue<Node>()
        queue.enqueue(node)
        while queue.isEmpty() == false {
            guard let node = queue.dequeue() else {
                return
            }
            print(node.key.value, separator: "", terminator: " ")
            if let left = node.left {
                queue.enqueue(left)
            }
            if let right = node.right {
                queue.enqueue(right)
            }
//            print("")
        }
    }
    private func Iterable(_ node: Node?, _ lo: ComparableObject, _ hi: ComparableObject, _ queue: inout Queue<ComparableObject>) {
        guard let node = node else {
            return
        }
        let cmpL = lo.compare(node.key)
        let cmpH = hi.compare(node.key)
        if cmpL < 0 {
            Iterable(node.left, lo, hi, &queue)
        }
        if cmpL <= 0 && cmpH >= 0 {
            queue.enqueue(node.key)
        }
        if cmpH > 0 {
            Iterable(node.right, lo, hi, &queue)
        }
    }
}

