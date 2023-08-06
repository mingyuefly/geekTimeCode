//
//  MinPQ.swift
//  PriorityQueue_swift
//
//  Created by gmy on 2023/6/3.
//

import Foundation


class MinPQ {
    private var pq:[Edge] = [Edge]()
    private var N: Int = 0
    init(maxSize: Int) {
        let c = Edge(v: -1, w: -1, weight: -1)
        pq = [Edge](repeating: c, count: maxSize + 1)
        N = 0
    }
    deinit {
        print("MaxPQ deinit")
    }
    func insert(_ a: Edge) {
        N += 1
        pq[N] = a
//        pq.append(a)
        swim(N)
    }
    func isEmpty() -> Bool {
        return N == 0
    }
    func deleteMin() -> Edge? {
        guard N > 0 else {
            return nil
        }
        let min = pq[1]
        exch(1, N)
        let c = Edge(v: -1, w: -1, weight: -1)
        pq[N] = c
//        pq.removeLast()
        N -= 1
        if N > 1 {
            sink(1)
        }
        return min
    }
    func show() {
        pq.forEach { edge in
            print(edge.toString(), terminator: " ")
        }
        print("")
    }
    private func sink(_ k: Int) {
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
    private func swim(_ k: Int) {
        var n = k
        while n > 1 && less(pq[n], pq[n / 2]) {
            exch(n / 2, n)
            n /= 2
        }
    }
    private func less(_ v: Edge, _ w: Edge) -> Bool {
        return v.getWeight() < w.getWeight()
    }
    private func exch( _ v: Int, _ w: Int) {
        let tmp = pq[w]
        pq[w] = pq[v]
        pq[v] = tmp
    }
}

