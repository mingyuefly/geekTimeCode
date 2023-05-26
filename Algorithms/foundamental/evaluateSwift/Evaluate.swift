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
    func compute(_ str: String) -> Double? {
        let evaluateStr = str.replacingOccurrences(of: " ", with: "")
        if (evaluateStr.isEmpty) {
            return 0
        }
        
        var vals = Stack<Double>()
        var ops = Stack<Character>()
        var tmpString = String()
        let verityArray:[Character] = ["(", "+", "-", "*", "/", ")"]
        
        evaluateStr.forEach { s in
            if verityArray.contains(s) {
                if tmpString.count > 0 {
                    let num = (tmpString as NSString).doubleValue
                    vals.push(Double(num))
                }
                tmpString = ""
            }
            
            if s == "+" || s == "-" || s == "*" || s == "/" {
                ops.push(s)
            } else if s == ")" {
                if let s = ops.pop(), let v0 = vals.pop(), let v1 = vals.pop() {
                    
                    if (s == "+") {
                        vals.push(v1 + v0)
                        
                    }
                    else if (s == "-") {
                        vals.push(v1 - v0)
                        
                    }
                    else if (s == "*") {
                        vals.push(v1 * v0)
                        
                    }
                    else if (s == "/") {
                        vals.push(v1 / v0)
                        
                    }
                }
            } else if s == "(" {
                
            } else {
                tmpString.append(s)
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



//class Evaluate {
//    var evaluateStr: String?
//    init() {
//
//    }
//    init(str: String) {
//        evaluateStr = str
//    }
//    deinit {
//        print("deinit")
//    }
//    func compute(_ str: String) -> Int? {
//        let evaluateStr = str.replacingOccurrences(of: "", with: " ")
//        if (evaluateStr.isEmpty) {
//            return 0
//        }
//
//        var vals = Stack<Int>()
//        var ops = Stack<Character>()
//        evaluateStr.forEach { s in
//            if s == "(" {}
//            else if s == " " {}
//            else if s == "+" {
//                ops.push(s)
//            }
//            else if s == "-" {
//                ops.push(s)
//            }
//            else if s == "*" {
//                ops.push(s)
//            }
//            else if s == "/" {
//                ops.push(s)
//            }
//            else if s == ")" {
//                if let s = ops.pop(), let v0 = vals.pop(), let v1 = vals.pop() {
//
//                    if (s == "+") {
//                        vals.push(v1 + v0)
//
//                    }
//                    else if (s == "-") {
//                        vals.push(v1 - v0)
//
//                    }
//                    else if (s == "*") {
//                        vals.push(v1 * v0)
//
//                    }
//                    else if (s == "/") {
//                        vals.push(v1 / v0)
//
//                    }
//
//                }
//            }
//            else {
//                vals.push(s.toInt() - 48)
//            }
//        }
//        return vals.top() ?? nil
//    }
//};
//
//extension Character {
//    func toInt() -> Int {
//        var intFromCharacter:Int = 0
//        for scalar in String(self).unicodeScalars {
//            intFromCharacter = Int(scalar.value)
//        }
//        return intFromCharacter
//    }
//}
//
//
//
