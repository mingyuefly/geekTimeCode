//
//  main.swift
//  evaluateSwift
//
//  Created by gmy on 2023/5/26.
//

import Foundation

let str1: String = "(12.3 + ((23.4 * 34.5) * (45.6 * 96.7)))"

let evaluate = Evaluate()
print(evaluate.compute(str1) ?? 0)

print(12.3 + ((23.4 * 34.5) * (45.6 * 96.7)))

let str2: String = "(12.3 + ((23.4 * 34.5) * sqrt(2)))"
print(evaluate.compute(str2) ?? 0)
print(12.3 + ((23.4 * 34.5) * sqrt(2)))

print(sqrt(13))

func tupleTest() -> (Double, String)? {
    return (1.0, "result")
}

print(tupleTest())
