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
//    init(str: String) {
//        evaluateStr = str
//    }
    deinit {
        print("deinit")
    }
    func compute(_ str: String) -> (Double, String)? {
        let evaluateStr = str.replacingOccurrences(of: " ", with: "")
        if (evaluateStr.isEmpty) {
            return (0.0, "算术不合法")
        }
        
        var vals = Stack<Double>()
        var ops = Stack<String>()
        var tmpString = String()
        var sqrtString = String()
        let verityArray:[String] = ["(", "+", "-", "*", "/", ")"]
        let verityArray1:[String] = ["s", "q", "r", "t"]
        let verityArray2:[String] = ["s", "q", "r", "t", "(", "+", "-", "*", "/", ")", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "."]
//        var success:Bool = false
        evaluateStr.forEach { s1 in
            
//            if !verityArray2.contains(s) {
////                success = false
//                return
//            }
            
            let s = String(s1)
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
                if let sign = ops.pop(), let v0 = vals.pop() {
                    if sign == "+", let v1 = vals.pop()  {
                        vals.push(v1 + v0)
                    } else if sign == "-", let v1 = vals.pop() {
                        vals.push(v1 - v0)
                    } else if sign == "*", let v1 = vals.pop() {
                        vals.push(v1 * v0)
                    } else if sign == "/", let v1 = vals.pop() {
                        vals.push(v1 / v0)
                    } else if (sign == "sqrt") {
                        vals.push(sqrt(v0))
                    }
                }
            } else if s == "(" {
                
            } else if verityArray1.contains(s) {
                sqrtString.append(s)
                if sqrtString == "sqrt" {
                    ops.push(sqrtString)
                    sqrtString = ""
                }
            } else {
                tmpString.append(s)
            }
        }
        if let num = vals.top() {
            return (num, "运算成功")
        } else {
            return (0.0, "算术不合法")
        }
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
