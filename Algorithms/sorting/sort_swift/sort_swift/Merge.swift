//
//  Merge.swift
//  sort_swift
//
//  Created by gmy on 2023/6/1.
//

import Foundation

class Merge<T: Comparable> {
    func sort(_ a: inout [ComparableObject<T>]) {
        var aux: [ComparableObject<T>] = Array(a)
        sort(&a, 0, a.count - 1, &aux)
    }
    func show(_ a: [ComparableObject<T>]) {
//        print("show")
        print(a)
    }
    func isSorted(_ a: [ComparableObject<T>]) -> Bool {
        for i in 1..<a.count {
            let v = a[i - 1]
            let w = a[i]
            if less(v, w) == false {
                return false
            }
        }

        return true
    }

    private func sort(_ a: inout [ComparableObject<T>], _ l: Int, _ r: Int, _ aux: inout [ComparableObject<T>]) {
        if r <= l {
            return
        }
        let mid = l + (r - l) / 2
        sort(&a, l, mid, &aux)
        sort(&a, mid + 1, r, &aux)
        merge(&a, l, mid, r, &aux)
    }
    private func merge(_ a: inout [ComparableObject<T>], _ l: Int, _ mid: Int, _ r: Int, _ aux: inout [ComparableObject<T>]) {
        var i = l
        var j = mid + 1
        for k1 in l...r {
            aux[k1] = a[k1]
        }
        for k in l...r {
            if i > mid {
                a[k] = aux[j]
                j += 1
            } else if j > r {
                a[k] = aux[i]
                i += 1
            } else if less(aux[i], aux[j]) {
                a[k] = aux[i]
                i += 1
            } else {
                a[k] = aux[j]
                j += 1
            }
        }
        print(a)
    }
    func less(_ v: ComparableObject<T>, _ w: ComparableObject<T>) -> Bool {
        return v.compareTo(a: w)
    }
    private func exch(a: inout [T], v: Int, w: Int) {
        let tmp = a[v]
        a[w] = a[v]
        a[v] = tmp
    }
}
