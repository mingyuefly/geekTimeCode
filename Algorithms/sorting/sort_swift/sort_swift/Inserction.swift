//
//  Inserction.swift
//  sort_swift
//
//  Created by gmy on 2023/6/2.
//

import Foundation

class Inserction<T: Comparable> {
    static func sort(_ a: inout [ComparableObject<T>]) {
        for i in 1..<a.count {
            for j in (1...i).reversed() {
                if less(a[j], a[j - 1]) {
                    exch(&a, j, j - 1)
                } else {
                    break
                }
            }
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