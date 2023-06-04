//
//  Comparable.swift
//  sort_swift
//
//  Created by gmy on 2023/6/1.
//

import Foundation

// 不再使用泛型，是因为swift语法不支持初始化一个固定长度的泛型空数组

struct ComparableObject {
    var value: Int
    func compareTo(_ a: ComparableObject) -> Bool {
        return value <= a.value
    }
}

