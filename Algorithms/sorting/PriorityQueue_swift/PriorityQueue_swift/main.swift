//
//  main.swift
//  PriorityQueue_swift
//
//  Created by gmy on 2023/6/3.
//

import Foundation

print("Hello, World!")

// MaxPQ
print("MaxPQ")

var a = [5, 3, 1, 10, 2, 18, 38, 17, 16, 25]
var nums = [ComparableObject]()
for i in 0..<a.count {
    let c = ComparableObject(value: a[i])
    nums.append(c)
}

let maxPQ = MaxPQ(maxSize: a.count)
maxPQ.show()

for i in 0..<nums.count {
    maxPQ.insert(nums[i]);
}
maxPQ.show()
//print(maxPQ.deleteMax().value)
if let max = maxPQ.deleteMax() {
    print(max.value)
}
maxPQ.show()
if let max = maxPQ.deleteMax() {
    print(max.value)
}
//print(maxPQ.deleteMax().value)
maxPQ.show()


// MinPQ
print("MinPQ")
let minPQ = MinPQ(maxSize: a.count)
minPQ.show()

for i in 0..<nums.count {
    minPQ.insert(nums[i]);
}
minPQ.show()
//print(maxPQ.deleteMax().value)
if let min = minPQ.deleteMin() {
    print(min.value)
}
minPQ.show()
if let min = minPQ.deleteMin() {
    print(min.value)
}
//print(maxPQ.deleteMax().value)
minPQ.show()

minPQ.insert(ComparableObject(value: 1))
minPQ.show()

// indexMinPQ
print("indexMinPQ")

var a1 = [5, 3, 1, 10, 2, 18, 38, 17, 16, 25]
var params1 = [ComparableObject]()
for i in 0..<a1.count {
    let c = ComparableObject(value: a1[i])
    params1.append(c)
}

var indexPQ = IndexMinPQ(maxSize: 100)
for i in 0..<params1.count {
    indexPQ.insert(i + 1, params1[i])
}
indexPQ.show()
print("")
print(indexPQ.deleteMin())
indexPQ.show()
print("")
print(indexPQ.deleteMin())
indexPQ.show()
print("")
var c9 = ComparableObject(value: 9)
indexPQ.insert(11, c9);
indexPQ.show()
print("")
var c33 = ComparableObject(value: 33)
indexPQ.insert(3, c33)
indexPQ.show()
print("")
var c55 = ComparableObject(value: 55)
indexPQ.insert(5, c55);
indexPQ.show()

// PQSort
print("PQSort")
let a2 = [5, 3, 1, 10, 2, 18, 38, 17, 16, 25]
var params2 = [ComparableObject]()
for i in 0..<a2.count {
    let c = ComparableObject(value: a2[i])
    params2.append(c)
}
print(params2)
PQSort.sort(&params2)
print(params2)

// PQSort1
print("PQSort1")
let a3 = [5, 3, 1, 10, 2, 18, 38, 17, 16, 25]
var params3 = [ComparableObject]()
for i in 0..<a3.count {
    let c = ComparableObject(value: a2[i])
    params3.append(c)
}
print(params3)
PQSort1.sort(&params3)
print(params3)



print("end")
