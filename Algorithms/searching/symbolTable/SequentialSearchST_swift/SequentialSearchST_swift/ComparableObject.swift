//
//  Comparable.swift
//  sort_swift
//
//  Created by gmy on 2023/6/1.
//

import Foundation

struct ComparableObject {
    var value: Int
    func less(_ a: ComparableObject) -> Bool {
        return value < a.value
    }
    func more(_ a: ComparableObject) -> Bool {
        return value > a.value
    }
    func equal(_ a: ComparableObject) -> Bool {
        return value == a.value
    }
}

