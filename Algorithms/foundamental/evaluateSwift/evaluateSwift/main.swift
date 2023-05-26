//
//  main.swift
//  evaluateSwift
//
//  Created by gmy on 2023/5/26.
//

import Foundation

let str1: String = "(1 + ((2 * 3) * (4 * 5)))"

let evaluate = Evaluate()
print(evaluate.compute(str1) ?? 0)

