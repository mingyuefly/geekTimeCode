//
//  Evaluate.swift
//  evaluateSwift
//
//  Created by gmy on 2023/5/26.
//

import Foundation

class Evaluate {
    var evaluateStr: String?
    init() {
        
    }
    init(str: String) {
        evaluateStr = str
    }
    deinit {
        print("deinit")
    }
    func compute(_ str: String) -> Int? {
        let evaluateStr = str
        if (evaluateStr.isEmpty) {
            return 0
        }
        
        var vals = Stack<Int>()
        var ops = Stack<Character>()
        evaluateStr.forEach { s in
            if s == "(" {}
            else if s == " " {}
            else if s == "+" {
                ops.push(s)
            }
            else if s == "-" {
                ops.push(s)
            }
            else if s == "*" {
                ops.push(s)
            }
            else if s == "/" {
                ops.push(s)
            }
            else if s == ")" {
                if let s = ops.pop(), let v0 = vals.pop(), let v1 = vals.pop() {
                    //                    var v2: Int
                    if (s == "+") {
                        vals.push(v1 + v0)
                        //                        v2 = Int(v1 + v0)
                    }
                    else if (s == "-") {
                        vals.push(v1 - v0)
                        //                        v2 = Int(v1 - v0)
                    }
                    else if (s == "*") {
                        vals.push(v1 * v0)
                        //                        v2 = Int(v1 * v0)
                    }
                    else if (s == "/") {
                        vals.push(v1 / v0)
                        //                        v2 = Int(v1 / v0)
                    }
                    //                    vals.push(v2)
                }
            }
            else {
                vals.push(s.toInt() - 48)
            }
        }
        return vals.top() ?? nil
    }
};

extension Character {
    func toInt() -> Int {
        var intFromCharacter:Int = 0
        for scalar in String(self).unicodeScalars {
            intFromCharacter = Int(scalar.value)
        }
        return intFromCharacter
    }
}



