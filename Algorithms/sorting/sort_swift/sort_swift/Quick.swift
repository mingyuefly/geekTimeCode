//
//  Quick.swift
//  sort_swift
//
//  Created by gmy on 2023/6/2.
//

import Foundation

class Quick<T: Comparable> {
    static func sort(_ a: inout [ComparableObject<T>]) {
        let l = 0
        let r = a.count - 1
        sort(&a, l, r)
    }
    static func isSorted(_ a: [ComparableObject<T>]) -> Bool {
//        print(a)
        for i in 1..<a.count {
            let v = a[i - 1]
            let w = a[i]
            if less(v, w) == false {
                return false
            }
        }

        return true
    }
    static func show(_ a: [ComparableObject<T>]) {
        a.forEach { num in
            print(num.value, terminator: " ")
        }
        print("")
    }
    
    static private func sort(_ a: inout [ComparableObject<T>], _ l: Int, _ r: Int) {
        if r <= l {
            return
        }
        let part = partition(&a, l, r)
        sort(&a, l, part - 1)
        sort(&a, part + 1, r)
    }
    static private func partition(_ a: inout [ComparableObject<T>], _ l: Int, _ r: Int) -> Int {
        let compare = a[l]
        var leftMid = l
        var rightMid = r
        while true {
            while less(a[leftMid], compare) {
                if leftMid == r {
                    break
                }
                leftMid += 1
            }
            while less(a[rightMid], compare) == false {
                if rightMid == l {
                    break
                }
                rightMid -= 1
            }
            if leftMid >= rightMid {
                break
            } else {
                exch(&a, leftMid, rightMid)
            }
        }
        exch(&a, l, rightMid)
        return rightMid
    }
    static private func less(_ v: ComparableObject<T>, _ w: ComparableObject<T>) -> Bool {
        return v.compareTo(w)
    }
    static private func exch(_ a: inout [ComparableObject<T>], _ v: Int, _ w: Int) {
        let tmp = a[w]
        a[w] = a[v]
        a[v] = tmp
    }
}
