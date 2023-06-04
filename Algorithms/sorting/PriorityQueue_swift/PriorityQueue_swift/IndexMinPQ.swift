//
//  IndexMinPQ.swift
//  PriorityQueue_swift
//
//  Created by gmy on 2023/6/3.
//

import Foundation

class IndexMinPQ {
    private var keys: [ComparableObject] = [ComparableObject]()//保存具体的对象
    private var pq:[Int] = [Int]() // 保存的是索引，而不是对象本身
    private var qp: [Int] = [Int]() // 保存每一个索引对应的pq下标
    private var N: Int = 0
    private var maxN = 100
    init(maxSize: Int) {
        maxN = maxSize
        let c = ComparableObject(value: -1)
        keys = [ComparableObject](repeating: c, count: maxN + 1)
        pq = [Int](repeating: -1, count: maxN + 1)
        qp = [Int](repeating: -1, count: maxN + 1)
        N = 0
    }
    deinit {
        print("MaxPQ deinit")
    }
    func contains(_ index: Int) -> Bool {
        if !validateIndex(index) {
            return false
        }
        return qp[index] != -1
    }
    func size() -> Int {
        return N
    }
    func isEmpty() -> Bool {
        return N == 0
    }
    func insert(_ index: Int, _ key: ComparableObject) {
        guard validateIndex(index) else {
            return
        }
        if contains(index) {
            return
        }
        N += 1
        pq[N] = index
        qp[index] = N
        keys[index] = key
        swim(N)
    }
    func minIndex() -> Int {
        if N == 0 {
            return -1
        }
        return pq[1]
    }
    func minKey() -> ComparableObject {
        if N == 0 {
            return ComparableObject(value: -1)
        }
        return keys[pq[1]]
    }
    func deleteMin() -> Int {
        guard N > 0 else {    
            return -1
        }
        let min = pq[1]
        exch(1, N)
        let c = ComparableObject(value: -1)
        keys[pq[N]] = c
        qp[pq[N]] = -1
        pq[N] = -1
        N -= 1
        if N > 1 {
            sink(1)
        }
        return min
    }
    func deleteIndex(_ index: Int) {
        guard validateIndex(index) else {
            return
        }
        guard contains(index) else {
            return
        }
        let k = qp[index]
        exch(pq[index], pq[N])
        qp[pq[N]] = -1
        keys[pq[N]] = ComparableObject(value: -1)
        pq[N] = -1
        N -= 1
        swim(k)
        sink(k)
    }
    func changeKey(_ index: Int, _ key: ComparableObject) {
        guard validateIndex(index) else {
            return
        }
        guard contains(index) else {
            return
        }
        keys[index] = key
        swim(qp[index])
        sink(qp[index])
    }
    func keyOf(_ index: Int) -> ComparableObject {
        if !validateIndex(index) {
            return ComparableObject(value: -1)
        }
        if !contains(index) {
            return ComparableObject(value: -1)
        }
        return keys[index]
    }
    func show() {
        for i in 1...N {
            print(pq[i], terminator: " ")
        }
        print("")
        for i in 1...N {
            print(keys[pq[i]].value, terminator: " ")
        }
        print("")
        for i in 1...N {
            print(qp[i], terminator: " ")
        }
        print("")
    }
    private func sink(_ k: Int) {
        var n = k
        while n * 2 <= N {
            var tmp = 2 * n
            if tmp < N, less(tmp, tmp + 1) == false {
                tmp += 1
            }
            if less(n, tmp) {
                break
            }
            exch(tmp, n)
            n = tmp
        }
    }
    private func validateIndex(_ index: Int) -> Bool {
        if index >= maxN || index < 1 {
            return false
        }
        return true
    }
    private func swim(_ k: Int) {
        var n = k
        while n > 1 && less(n, n / 2) {
            exch(n / 2, n)
            n /= 2
        }
    }
    private func less(_ v: Int, _ w: Int) -> Bool {
        
        return keys[pq[v]].compareTo(keys[pq[w]])
    }
    private func exch( _ v: Int, _ w: Int) {
        let tmp = pq[w]
        pq[w] = pq[v]
        pq[v] = tmp
        qp[pq[w]] = w
        qp[pq[v]] = v
    }
}
