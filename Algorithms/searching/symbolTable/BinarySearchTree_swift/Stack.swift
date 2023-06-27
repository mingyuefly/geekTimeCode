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

// MARK: - 打印栈及其类型时，输出简洁漂亮的格式
extension Stack: CustomStringConvertible, CustomDebugStringConvertible {
    
    
    /// 在打印栈及其元素时，输出简洁漂亮的格式
    /// 如果不实现这些代码，打印栈的结果为：ArrayStack<Int>(elements: [5, 44, 23])
    /// 实现下面这些代码之后，打印栈的结果为：[5, 44, 23]
    /// - returns: 返回栈及其元素的文本表示
    public var description: String {
        return elements.description
    }
    
    /// 打印时输出简洁漂亮的格式，主要用于调试
    /// - returns: 返回栈及其元素的文本表示，适用于调试
    public var debugDescription: String {
        return elements.debugDescription
    }
    
}

// MARK: - 以现有栈实例为基础，创建新的栈实例
extension Stack {
    
    /// 使用现有栈实例作为副本创建一个新的栈实例
    /// 这是一个泛型构造函数，其中占位类型S必须是符合Sequence协议的；
    /// 另外，where关键字限制了这个构造函数只对元素类型是T类型的序列有效；
    /// 最后，这个构造函数主要是用来实现在已经存在的栈实例的基础上创建一个实例：
    ///     // var myStack = [1, 2, 3]
    ///     // var anotherStack = Stack(myStack)
    ///
    /// 说明：只有实现了这个构造函数，后面才能实现字面量构造函数
    public init<S : Sequence>(_ s: S) where S.Iterator.Element == T {
        
        // 使用现有的数组副本创建一个新的数组
        // 调用reversed()函数，返回一个包含相同元素，但是顺序相反的新数组；
        // 因为栈是先入后出的数据结构，参数s调用reversed()函数，可以确保基于
        // 现有栈实例创建出来的新实例，可以以同样的次数输出元素。如果参数s不调用
        // reverse()函数，那么新创建出来的栈实例，其内部元素顺序则是反的：
        //  - 比如说，原有栈实例是这样的：var myStack = [1, 2, 3]
        //  - 如果将myStack作为参数来创建新的栈实例：var anotherStack = Stack(myStack)
        //  - 那么，anotherStack的顺序将是这样的：[3, 2, 1]
        self.elements = Array(s.reversed())
    }
}

// MARK: - 实现栈的字面量语法
extension Stack: ExpressibleByArrayLiteral {
    
    /// 实现用字面量语法初始化一个栈
    /// 比如说，你可能希望像用字面量语法创建数组一样创建Stack实例：
    ///     // var myStack: Stack = [4, 5, 6, 7]
    /// - 参数elements：它是一个变长参数，类型为T
    public init(arrayLiteral elements: T...) {
        self.init(elements)
    }
}

/********** 下面的代码是给栈添加for...in语法支持，有改进的余地 **********/


// MARK: - 定义一个ArrayIterator结构体
public struct ArrayIterator<T> : IteratorProtocol {
    
    // 临时数组
    var currentElement: [T]
    
    /// 构造函数：创建一个[T]类型的数组
    /// - 参数elements：一个[T]类型的数组
    init(elements: [T]){
        currentElement = elements
    }
    
    /// 负责返回序列中的下一个元素
    /// - returns:
    /// - 如果数组不为空，则删除并返回最后一个元素
    /// - 如果数组为空，则返回nil
    mutating public func next() -> T? {
        
        if (!currentElement.isEmpty) {
            return currentElement.popLast()
        }
        
        return nil
    }
}

// MARK: - 给栈添加for..in语法支持
//extension Stack: Sequence {
//    
//    /// 用于初始化for...in循环迭代器
//    /// - returns：返回一个ArrayIterator类型的实例
//    public func makeIterator() -> ArrayIterator<T> {
//        return ArrayIterator<T>(elements: elements)
//    }
//}

// MARK: - 给栈添加for..in语法支持
extension Stack: Sequence {

    /// 初始化循环迭代器
    /// - AnyIterator<T>: 一个泛型IteratorProtocol基类型，并且它内部有一个next()方法，
    ///   这样就不用自己去实现ArrayIterator类型的结构体了；
    /// - IndexingIterator: 它是所有集合默认的迭代器，无需自己动手实现，其工作方式是通过下
    ///   标来遍历集合中的每一个元素的；
    /// - returns：返回一个基本的迭代器
    public func makeIterator() -> AnyIterator<T> {
        return AnyIterator(IndexingIterator(_elements: elements.lazy.reversed()))
    }
}
