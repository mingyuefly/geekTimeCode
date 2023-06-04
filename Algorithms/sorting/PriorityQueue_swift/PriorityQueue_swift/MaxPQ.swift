//
//  MaxPQ.swift
//  PriorityQueue_swift
//
//  Created by gmy on 2023/6/3.
//

import Foundation



class MaxPQ {
    private var pq:[ComparableObject] = [ComparableObject]()
    private var N: Int = 0
    init(maxSize: Int) {
        let c = ComparableObject(value: 0)
        pq = [ComparableObject](repeating: c, count: maxSize + 1)
        N = 0
    }
    deinit {
        print("MaxPQ deinit")
    }
    func insert(_ a: ComparableObject) {
        N += 1
        pq[N] = a
        swim(N)
    }
    func isEmpty() -> Bool {
        return N == 0
    }
    func deleteMax() -> ComparableObject? {
        guard N > 0 else {
            return nil
        }
        let max = pq[1]
        exch(1, N)
        let c = ComparableObject(value: 0)
        pq[N] = c
        N -= 1
        if N > 1 {
            sink(1)
        }
        return max
    }
    func show() {
        pq.forEach { num in
            print(num.value, terminator: " ")
        }
        print("")
    }
    private func sink(_ k: Int) {
        var n = k
        while n * 2 <= N {
            var tmp = 2 * n
            if tmp < N, less(pq[tmp + 1], pq[tmp]) == false {
                tmp += 1
            }
            if less(pq[tmp], pq[n]) {
                break
            }
            exch(tmp, n)
            n = tmp
        }
    }
    private func swim(_ k: Int) {
        var n = k
        while n > 1 && less(pq[n], pq[n / 2]) == false {
            exch(n / 2, n)
            n /= 2
        }
    }
    private func less(_ v: ComparableObject, _ w: ComparableObject) -> Bool {
        return v.compareTo(w)
    }
    private func exch( _ v: Int, _ w: Int) {
        let tmp = pq[w]
        pq[w] = pq[v]
        pq[v] = tmp
    }
}
