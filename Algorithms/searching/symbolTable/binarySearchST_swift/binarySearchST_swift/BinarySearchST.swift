//
//  BinarySearchST.swift
//  binarySearchST_swift
//
//  Created by gmy on 2023/6/6.
//

import Foundation

class BinarySearchST {
    var keys: [ComparableObject]
    var vals: [Int]
    var N: Int
    private var capicity: Int
    init(capicity: Int) {
        keys = [ComparableObject](repeating: ComparableObject(value: -1), count: capicity)
        vals = [Int](repeating: -1, count: capicity)
        self.capicity = capicity
        N = 0
    }
    deinit {
        print("deinit")
    }
    func isEmpty() -> Bool {
        return N == 0
    }
    func size() -> Int {
        return N
    }
    func rank(_ key: ComparableObject) -> Int {
        var lo = 0
        var hi = N - 1
        while lo <= hi {
            let mid = lo + (hi - lo) / 2
            if key.less(keys[mid]) {
                hi = mid - 1
            } else if key.more(keys[mid]) {
                lo = mid + 1
            } else {
                return mid
            }
        }
        return lo
    }
    func get(_ key: ComparableObject) -> Int {
        if isEmpty() {
            return -1
        }
        let i = rank(key)
        if i < N, keys[i].equal(key) {
            return vals[i]
        } else {
            return -1
        }
    }
    func put(_ key: ComparableObject, _ value: Int) {
        if N == keys.count {
            resize(2 * N)
        }
        let i = rank(key)
        if i < N, keys[i].equal(key) {
            vals[i] = value
            return
        }
        for j in (i..<N).reversed() {
            keys[j + 1] = keys[j]
            vals[j + 1] = vals[j]
        }
        keys[i] = key
        vals[i] = value
        N += 1
    }
    func deleteKey(_ key: ComparableObject) {
        if isEmpty() {
            return
        }
        let i = rank(key)
        if i >= N || !keys[i].equal(key) {
            return
        }
        N -= 1
        for j in i..<N {
            keys[j] = keys[j + 1]
            vals[j] = vals[j + 1]
        }
        keys[N] = ComparableObject(value: -1)
        vals[N] = -1
        if N > 0, N < capicity / 4 {
            resize(capicity / 2)
        }
    }
    func min() -> ComparableObject {
        if isEmpty() {
            return ComparableObject(value: -1)
        }
        return keys[0]
    }
    func max() -> ComparableObject {
        if isEmpty() {
            return ComparableObject(value: -1)
        }
        return keys[N - 1]
    }
    func select(_ k: Int) -> ComparableObject {
        if isEmpty() {
            return ComparableObject(value: -1)
        }
        return keys[k]
    }
    func ceiling(_ key: ComparableObject) -> ComparableObject {
        let k = rank(key)
        if k < N, keys[k].equal(key) {
            return keys[k]
        } else {
            if k >= 0 && k < N - 1 {
                return keys[k + 1]
            } else {
                return ComparableObject(value: -1)
            }
        }
    }
    func floor(_ key: ComparableObject) -> ComparableObject {
        let k = rank(key)
        if k < N, keys[k].equal(key) {
            return keys[k]
        } else {
            if k > 0 {
                return keys[k - 1]
            } else {
                return ComparableObject(value: -1)
            }
        }
    }
    func Iterable(lo: ComparableObject, hi: ComparableObject) -> Queue<ComparableObject> {
        var q = Queue<ComparableObject>()
        let i = rank(lo)
        let j = rank(hi)
        if i > j {
            return q
        }
        if i > N || j > N {
            return q
        }
        for k in i...j {
            q.enqueue(keys[k])
        }
        return q
    }
    func show() {
        for i in 0..<N {
            print(String(keys[i].value) + ": " + String(vals[i]))
        }
        print("")
    }
    private func resize(_ size: Int) {
        var keyArr = Array(repeating: ComparableObject(value: -1), count: size)
        keyArr.replaceSubrange(0..<N, with: keys)
        keys = keyArr
        var valArr = Array(repeating: -1, count: size)
        valArr.replaceSubrange(0..<N, with: vals)
        vals = valArr
        capicity = size
    }
}
