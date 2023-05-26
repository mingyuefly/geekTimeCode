//
//  main.swift
//  evaluateSwift
//
//  Created by gmy on 2023/5/26.
//

import Foundation

let str1: String = "(12.3 + ((23.4 * 34.5) * (45.6 * 56.7)))"

let evaluate = Evaluate()
print(evaluate.compute(str1) ?? 0)

print(12.3 + ((23.4 * 34.5) * (45.6 * 56.7)))

