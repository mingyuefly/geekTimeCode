//
//  main.swift
//  sort_swift
//
//  Created by gmy on 2023/6/1.
//

import Foundation

print("Hello, World!")

let arr1: [Int] = [1, 5, 8, 15, 22, 49]
let arr2: [Int] = [2, 7, 9, 10 ,11, 28, 55]

class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var i = m - 1, j = n - 1, k = m + n - 1
        while i >= 0 && j >= 0 {
            if nums1[i] >= nums2[j] {
                nums1[k] = nums1[i]
                i -= 1
                k -= 1
            } else {
                nums1[k] = nums2[j]
                j -= 1
                k -= 1
            }
        }
        while i >= 0 {
            nums1[k] = nums1[i]
            i -= 1
            k -= 1
        }
        while j >= 0 {
            nums1[k] = nums2[j]
            j -= 1
            k -= 1
        }
    }
}

func mergeFunc(arr1:[Int], arr2:[Int]) -> [Int]? {
    
    var i = 0, j = 0
    var arr3 = [Int]()
    
    while i < arr1.count && j < arr2.count {
        if arr1[i] <= arr2[j] {
            arr3.append(arr1[i])
            i += 1
        } else {
            arr3.append(arr2[j])
            j += 1
        }
    }
    while j < arr2.count {
        arr3.append(arr2[j])
        j += 1
    }
    while i < arr1.count {
        arr3.append(arr1[i])
        i += 1
    }
    
    return arr3
}

let arr3 = mergeFunc(arr1: arr1, arr2: arr2)
print(arr1)
print(arr2)
print(arr3 ?? [0])



var nums1: [Int] = [1, 5, 8, 15, 22, 49, 0, 0, 0, 0, 0, 0, 0]
let nums2: [Int] = [2, 7, 9, 10 ,11, 28, 55]

Solution().merge(&nums1, nums1.count - nums2.count, nums2, nums2.count)
print(nums1)

/// MARK: merge 归并排序
print("merge")
var nums3: [Int] = [5, 3, 1, 10, 2, 18, 38, 17, 16, 25, 10]
var nums4: [ComparableObject<Int>] = [ComparableObject<Int>]()
nums3.forEach { num in
    nums4.append(ComparableObject(value: num))
}

//let merge = Merge<Int>()
Merge<Int>.show(nums4)
Merge<Int>.sort(&nums4)
//merge.show(nums4)
if Merge<Int>.isSorted(nums4) {
    Merge<Int>.show(nums4)
}

/// MARK:  selection 选择排序
print("selection")

var nums5: [Int] = [5, 3, 1, 10, 2, 18, 38, 17, 16, 25, 10]
var nums6: [ComparableObject<Int>] = [ComparableObject<Int>]()
nums5.forEach { num in
    nums6.append(ComparableObject(value: num))
}
Selection<Int>.show(nums6)
Selection<Int>.sort(&nums6)
//merge.show(nums4)
if Selection<Int>.isSorted(nums6) {
    Selection<Int>.show(nums6)
}

/// MARK: insertion  插入排序
print("insertion")

var nums7: [Int] = [5, 3, 1, 10, 2, 18, 38, 17, 16, 25, 10]
var nums8: [ComparableObject<Int>] = [ComparableObject<Int>]()
nums7.forEach { num in
    nums8.append(ComparableObject(value: num))
}
Inserction<Int>.show(nums8)
Inserction<Int>.sort(&nums8)
//merge.show(nums4)
if Inserction<Int>.isSorted(nums8) {
    Inserction<Int>.show(nums8)
}

/// MARK: shell 希尔排序
print("shell")
var nums9: [Int] = [5, 3, 1, 10, 2, 18, 38, 17, 16, 25, 10]
var nums10: [ComparableObject<Int>] = [ComparableObject<Int>]()
nums9.forEach { num in
    nums10.append(ComparableObject(value: num))
}
Shell<Int>.show(nums8)
Shell<Int>.sort(&nums8)
//merge.show(nums4)
if Shell<Int>.isSorted(nums8) {
    Shell<Int>.show(nums8)
}

/// MARK: quick 快速排序
print("quick")
var nums11: [Int] = [5, 3, 1, 10, 2, 18, 38, 17, 16, 25, 10]
var nums12: [ComparableObject<Int>] = [ComparableObject<Int>]()
nums11.forEach { num in
    nums12.append(ComparableObject(value: num))
}
Quick<Int>.show(nums12)
Quick<Int>.sort(&nums12)
//merge.show(nums4)
if Quick<Int>.isSorted(nums12) {
    Quick<Int>.show(nums12)
}

print("end")
