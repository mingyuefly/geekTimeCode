//
//  queue.swift
//  binarySearchST_swift
//
//  Created by gmy on 2023/6/6.
//

import Foundation

//MARK: - 队列的基本实现
public struct Queue<T> {
    
    // 泛型数组：用于存储数据元素
    fileprivate var data = [T]()
    
    
    
    /// 构造函数：创建一个空的队列
    public init() {}
    
    
    
    /// 入队列操作：将元素添加到队列的末尾
    /// -复杂度: O(1)
    /// -参数element: 一个类型为T的元素
    public mutating func enqueue(_ element: T) {
        data.append(element)
    }
    
    
    
    /// 出队列操作：删除并返回队列中的第一个元素
    /// -returns:
    /// -如果队列不为空，则返回第一个类型为T的元素
    /// -如果队列为空，则返回nil
    public mutating func dequeue() -> T? {
        return data.removeFirst()
    }

    
    
    /// 返回队列中的第一个元素(不删除)
    /// -returns:
    /// -如果队列不为空，则返回第一个类型为T的元素
    /// -如果队列为空，则返回nil
    public func peek() -> T? {
        return data.first
    }
    
    /// 将队列重置为空状态
    public mutating func clear() {
        data.removeAll()
    }
    
    /// 返回队列中元素的个数
    public var count: Int {
        return data.count
    }
    
    /// 计算属性：返回队列的存储容量
    /// - get：获取队列的存储空间，但不会分配新的存储空间
    /// - set：分配足够的空间来存储指定数量的元素
    public var capacity: Int {
        get {
            return data.capacity
        }
        set {
            data.reserveCapacity(newValue)
        }
    }
    
    /// 检查队列是否已满
    /// -returns: 如果队列已满，则返回true，否则返回false
    public func isFull() -> Bool {
        return count == data.capacity
    }
    
    /// 检查队列是否为空
    /// - returns: 如果队列为空，则返回true，否则返回false
    public func isEmpty() -> Bool {
        return data.isEmpty
    }
    
    
    
    /// 检查队列中的索引是否合法
    fileprivate func checkIndex(_ index: Int) {
        if index < 0 || index > count {
            fatalError("Index out of range")
        }
    }
}



// MARK: - 打印队列及其类型时，输出简洁漂亮的格式
extension Queue: CustomStringConvertible, CustomDebugStringConvertible {
    
    /// 在打印队列及其元素时，输出简洁漂亮的格式
    /// 如果不实现这些代码，打印队列的结果为：Queue<Int>(data: [125, 130])
    /// 实现下面这些代码之后，打印队列的结果为：[125, 130]
    /// - returns: 返回队列及其元素的文本表示
    public var description: String {
        return data.description
    }
    
    
    /// 打印时输出简洁漂亮的格式，主要用于调试
    /// - returns: 返回队列及其元素的文本表示，适用于调试
    public var debugDescription: String {
        return data.debugDescription
    }
}



// MARK: - 以现有队列实例为基础，创建新的队列实例
extension Queue {
    
    /// 构造函数：用于从序列中创建队列(可参见Stack中的相关注释)
    /// 实现这个方法可以让你通过现有的队列实例来创建一个新的队列实例：
    ///     // var queue: Queue = [1, 2, 3]
    ///     // var myQueue = Queue(queue)  // 使用现有的队列实例queue来创建新的队列实例
    ///
    /// - 参数elements：其类型为S，并且限定遵守Sequence协议，where关键字限制了这个构造函数只
    ///                对元素类型是T类型的序列有效；
    public init<S: Sequence>(_ elements: S) where S.Iterator.Element == T {
        
        // 将一个elements序列添加到数组data末尾
        data.append(contentsOf: elements)
    }
}



// MARK: - 使用字面量语法来创建队列实例
extension Queue: ExpressibleByArrayLiteral {
    
    /// 使用字面量语法来创建队列实例
    public init(arrayLiteral elements: T...) {
        self.init(elements)
    }
}



// MARK: - 根据索引返回指定的位置
/// 补充说明一点，因为MutableCollection协议是遵守Collection协议的，
/// 而Collection协议又是遵守Sequence协议的，所以从理论上讲，我们这里
/// 已经遵守了MutableCollection协议，后面就没必要再遵守Collection
/// 协议和Sequence协议了。但是，从语义和逻辑清晰的角度来讲，明确遵守某
/// 个协议有利于我们对代码的理解
extension Queue: MutableCollection {
    
    /// 队列的起始索引
    /// - returns：返回队列开始的索引
    public var startIndex: Int {
        return 0
    }
    
    /// 队列的末尾索引
    /// - returns：返回队列末尾的索引，如果队列为空，则返回0，否则返回count - 1
    public var endIndex: Int {
        return count == 0 ? 0 : count - 1
    }
    
    
    /// 返回指定位置后面的索引，并且索引i必须比endIndex小，否则越界
    /// - returns：返回指定索引后面的位置
    public func index(after i: Int) -> Int {
        
        // 检查索引值i是否合法
        checkIndex(i)
        
        // 返回i后面的索引
        return data.index(after: i)
    }
    
    
    
    /// 通过指定的下标值来获取/设置队列中的元素
    /// - get：获取队列中指定下标元素的值
    /// - set：修改队列中指定下标元素的值
    public subscript(index: Int) -> T {
        
        get {
            // 检查下标值是否合法
            checkIndex(index)
            return data[index]
        }
        
        set(newValue) {
            // 检查下标值是否合法
            checkIndex(index)
            data[index] = newValue
        }
    }
}


// MARK: - 添加for...in等循环支持
extension Queue: Sequence {
    
    /// 返回此序列的元素的迭代器
    /// - 复杂度: O(1)
    public func makeIterator() -> AnyIterator<T> {
        return AnyIterator(IndexingIterator(_elements: data.lazy))
    }
}
