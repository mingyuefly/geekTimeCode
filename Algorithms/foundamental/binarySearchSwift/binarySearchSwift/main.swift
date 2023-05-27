//
//  main.swift
//  binarySearchSwift
//
//  Created by gmy on 2023/5/27.
//

import Foundation

//print("Hello, World!")

let binarySearch = BinarySearch()
let arr = [1, 3, 4, 7, 8, 22, 31, 45, 65, 99, 123]

print(binarySearch.search(k: 4, arr: arr))
print(binarySearch.search(k: 99, arr: arr))
print(binarySearch.search(k: 8, arr: arr))
print(binarySearch.search(k: 10, arr: arr))

