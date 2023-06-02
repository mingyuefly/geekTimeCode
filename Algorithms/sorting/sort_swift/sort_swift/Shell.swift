//
//  Shell.swift
//  sort_swift
//
//  Created by gmy on 2023/6/2.
//

import Foundation

class Shell<T: Comparable> {
    static func sort(_ a: inout [ComparableObject<T>]) {
        let n = a.count
        var h = 1;
        while h < n / 3 {
            h = 3 * h + 1
        }
        while h >= 1 {
            for i in h..<n {
                for j in stride(from: h, through: i, by: -h) {
                    if less(a[j], a[j - h]) {
                        exch(&a, j, j - h)
                    } else {
                        break
                    }
                }
            }
            h -= 1
        }
    }
    static func isSorted(_ a: [ComparableObject<T>]) -> Bool {
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
    
    static private func less(_ v: ComparableObject<T>, _ w: ComparableObject<T>) -> Bool {
        return v.compareTo(a: w)
    }
    static private func exch(_ a: inout [ComparableObject<T>], _ v: Int, _ w: Int) {
        let tmp = a[w]
        a[w] = a[v]
        a[v] = tmp
    }
}
