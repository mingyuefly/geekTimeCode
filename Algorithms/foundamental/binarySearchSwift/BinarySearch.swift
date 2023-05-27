//
//  BinarySearch.swift
//  binarySearchSwift
//
//  Created by gmy on 2023/5/27.
//

import Foundation

class BinarySearch {
    init() {
        
    }
    deinit {
        
    }
    func search(k: Int, arr: [Int]) -> Int {
        if arr.isEmpty {
            return -1
        }
        var l = 0
        var r = arr.endIndex
        while l <= r {
            var mid = l + (r - l) / 2
            if k < arr[mid] {
                r = mid - 1
            } else if k > arr[mid] {
                l = mid + 1
            } else {
                return mid
            }
        }
        return -1
    }
}
