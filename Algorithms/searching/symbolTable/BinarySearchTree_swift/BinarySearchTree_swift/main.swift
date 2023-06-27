//
//  main.swift
//  BinarySearchTree_swift
//
//  Created by gmy on 2023/6/7.
//

import Foundation

print("Hello, World!")

var bst = BinarySearchTree()

var key0 = ComparableObject(value: 18)
var key1 = ComparableObject(value: 23)
var key2 = ComparableObject(value: 4)
var key3 = ComparableObject(value: 17)
var key4 = ComparableObject(value: 0)
var key5 = ComparableObject(value: 2)
var key6 = ComparableObject(value: 12)
var key7 = ComparableObject(value: 11)
var key8 = ComparableObject(value: 15)

bst.put(key0, 100)
bst.put(key1, 101)
bst.put(key2, 102)
bst.put(key3, 103)
bst.put(key4, 104)
bst.put(key5, 105)
bst.put(key6, 106)
bst.put(key7, 107)
bst.put(key8, 108)

bst.inOrder()
bst.inOrderWithoutRecursion()
bst.levelOrder()

var queue = bst.Iterable()
while queue.isEmpty() == false {
    if let key = queue.dequeue() {
        print(key.value)
    }
}
print("")

var queue1 = bst.Iterable(ComparableObject(value: 5), ComparableObject(value: 19))
while queue1.isEmpty() == false {
    if let key = queue1.dequeue() {
        print(key.value)      
    }
}
print("")

print(bst.get(key5))

bst.put(key6, 116)
bst.inOrder()

print(bst.min().value)
print(bst.max().value)

print(bst.floor(key6).value)
print(bst.floor(ComparableObject(value: 19)).value)

var key9 = ComparableObject(value: 13)
print(bst.floor(key9).value)

print(bst.select(3).value)

print(bst.rank(ComparableObject(value: 16)))

bst.deleteMin()
bst.inOrder()

bst.deleteKey(key6)
//bst.deleteKey(key0)
bst.inOrder()

print("end")

