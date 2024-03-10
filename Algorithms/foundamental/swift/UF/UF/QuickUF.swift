//
//  QuickUF.swift
//  UF
//
//  Created by GMY on 2023/8/16.
//

import Foundation

class QuickUF {
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
        var p1 = p
        while p1 != id[p1] {
            p1 = id[p1]
        }
        return p1
    }
    func union(_ p: Int, _ q: Int) {
        let pRoot = find(p)
        let qRoot = find(q)
        if pRoot == qRoot {
            return
        }
        id[pRoot] = qRoot
        count -= 1
    }
    func show() {
        print("count:\(count)")
        for i in 0..<id.count {
            print("\(i):\(id[i])")
        }
    }
}
