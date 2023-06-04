//
//  PQSort1.swift
//  PriorityQueue_swift
//
//  Created by gmy on 2023/6/4.
//

import Foundation

class PQSort1 {
    private static var N: Int = 0
    init() {
        
    }
    deinit {
        print("MaxPQ deinit")
    }
    static func sort(_ a: inout [ComparableObject]) {
        N = a.count
        a.insert(ComparableObject(value: 0), at: 0)
        var k = N / 2
        while k >= 1 {
            sink(&a, k)
            k -= 1
        }
        while N > 1 {
            exch(&a, 1, N)
            N -= 1
            sink(&a, 1)
        }
        a.remove(at: 0)
    }
    private static func sink(_ pq: inout [ComparableObject], _ k: Int) {
        var n = k
        while n * 2 <= N {
            var tmp = 2 * n
            if tmp < N, less(pq[tmp + 1], pq[tmp]) == false {
                tmp += 1
            }
            if less(pq[tmp], pq[n]) {
                break
            }
            exch(&pq, tmp, n)
            n = tmp
        }
    }
    private static func less(_ v: ComparableObject, _ w: ComparableObject) -> Bool {
        return v.compareTo(w)
    }
    private static func exch(_ pq: inout [ComparableObject], _ v: Int, _ w: Int) {
        let tmp = pq[w]
        pq[w] = pq[v]
        pq[v] = tmp
    }
}
