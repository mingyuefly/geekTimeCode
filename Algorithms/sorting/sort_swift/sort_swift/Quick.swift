//
//  Quick.swift
//  sort_swift
//
//  Created by gmy on 2023/6/2.
//

import Foundation

class Quick<T: Comparable> {
    func sort(_ a: inout [ComparableObject<T>]) {
        
    }
    func show(_ a: [ComparableObject<T>]) {
        a.forEach { num in
            print(num.value, terminator: " ")
        }
        print("")
    }
    
    private func less(_ v: ComparableObject<T>, _ w: ComparableObject<T>) -> Bool {
        return v.compareTo(a: w)
    }
    private func exch(_ a: inout [ComparableObject<T>], _ v: Int, _ w: Int) {
        let tmp = a[w]
        a[w] = a[v]
        a[v] = tmp
    }
}
