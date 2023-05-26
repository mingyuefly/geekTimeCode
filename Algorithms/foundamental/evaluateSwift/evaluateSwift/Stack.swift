//
//  Stack.swift
//  evaluateSwift
//
//  Created by gmy on 2023/5/26.
//

import Foundation

public struct Stack<T> {
    fileprivate var elements = [T]()
    init() {
        
    }
    mutating public func push(_ element: T) {
        elements.append(element)
    }
    mutating public func pop() -> T? {
        return elements.popLast()
    }
    public var count: UInt {
        get {
            return UInt(elements.count)
        }
    }
    public func top() -> T? {
        return elements.last
    }
    public func isEmpty() -> Bool? {
        return elements.isEmpty
    }
}
