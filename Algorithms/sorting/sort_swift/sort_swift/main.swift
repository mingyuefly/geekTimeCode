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
