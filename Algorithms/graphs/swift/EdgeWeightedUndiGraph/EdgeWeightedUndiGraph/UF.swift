//
//  UF.swift
//  UF
//
//  Created by GMY on 2023/8/16.
//

import Foundation

class UF {
    private var count: Int
    private var id: [Int]
    init(count: Int, id: [Int]) {
        self.count = count
        self.id = id
    }
    convenience init(N: Int) {
        let id = [Int](0..<N)
        self.init(count: N, id: id)
    }
    func getCount() -> Int {
        return count
    }
    func connected(_ p: Int, _ q: Int) -> Bool {
        return id[p] == id[q]
    }
    func find(_ p: Int) -> Int {
        return id[p]
    }
    func union(_ p: Int, _ q: Int) {
        let pId = id[p]
        let qId = id[q]
        if pId == qId {
            return
        }
        for i in 0..<id.count {
            if id[i] == pId {
                id[i] = qId
            }
        }
        count -= 1
    }
    func show() {
        print("count:\(count)")
        for i in 0..<id.count {
            print("\(i):\(id[i])")
        }
    }
}
