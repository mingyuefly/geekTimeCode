//
//  PQSort.swift
//  PriorityQueue_swift
//
//  Created by gmy on 2023/6/4.
//

import Foundation

class PQSort {
    private static var pq:[ComparableObject] = [ComparableObject]()
    private static var N: Int = 0
    init() {
        
    }
    deinit {
        print("MaxPQ deinit")
    }
    static func sort(_ a: inout [ComparableObject]) {
        let c = ComparableObject(value: 0)
        pq = [ComparableObject](repeating: c, count: a.count + 1)
        N = 0
        a.forEach { key in
            insert(key)
        }
        a.removeAll()
        while N > 0 {
            if let key = deleteMin() {
                a.append(key)
            }
        }
    }
    private static func insert(_ a: ComparableObject) {
        N += 1
        pq[N] = a
        swim(N)
    }
    private static func isEmpty() -> Bool {
        return N == 0
    }
    private static func deleteMin() -> ComparableObject? {
        guard N > 0 else {
            return nil
        }
        let min = pq[1]
        exch(1, N)
        let c = ComparableObject(value: 0)
        pq[N] = c
        N -= 1
        if N > 1 {
            sink(1)
        }
        return min
    }
    private static func show() {
        pq.forEach { num in
            print(num.value, terminator: " ")
        }
        print("")
    }
    private static func sink(_ k: Int) {
        var n = k
        while n * 2 <= N {
            var tmp = 2 * n
            if tmp < N, less(pq[tmp], pq[tmp + 1]) == false {
                tmp += 1
            }
            if less(pq[n], pq[tmp]) {
                break
            }
            exch(tmp, n)
            n = tmp
        }
    }
    private static func swim(_ k: Int) {
        var n = k
        while n > 1 && less(pq[n], pq[n / 2]) {
            exch(n / 2, n)
            n /= 2
        }
    }
    private static func less(_ v: ComparableObject, _ w: ComparableObject) -> Bool {
        return v.compareTo(w)
    }
    private static func exch( _ v: Int, _ w: Int) {
        let tmp = pq[w]
        pq[w] = pq[v]
        pq[v] = tmp
    }
}
