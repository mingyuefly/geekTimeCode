//
//  Comparable.swift
//  sort_swift
//
//  Created by gmy on 2023/6/1.
//

import Foundation

struct ComparableObject<T: Comparable> {
    var value: T
    func compareTo(a: ComparableObject) -> Bool {
        return value <= a.value
    }
}

