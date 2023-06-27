//
//  LinearProbingHashST.swift
//  linearProbingHashST_swift
//
//  Created by gmy on 2023/6/28.
//

import Foundation

class LinearProbingHashST {
    private var keys: [ComparableObject] = [ComparableObject]()
    private var vals: [Int] = [Int]()
    private var M: Int = 20
    private var N: Int = 0
    init() {
        self.keys = Array<ComparableObject>(repeating: ComparableObject(value: -1), count: M)
        self.vals = Array<Int>(repeating: -1, count: M)
    }
    init(M: Int) {
        self.M = M
        self.keys = Array<ComparableObject>(repeating: ComparableObject(value: -1), count: M)
        self.vals = Array<Int>(repeating: -1, count: M)
    }
    deinit {
        print("LinearProbingHashST deinit")
    }
    func get(_ key: ComparableObject) -> Int {
        var i = hash(key)
        while keys[i].value != -1 {
            if key.equal(keys[i]) {
                return vals[i]
            }
            i = (i + 1) % M
        }
        return -1
    }
    func put(_ key: ComparableObject, _ value: Int) {
        if N >= M/2 {
            resize(2 * M)
        }
        var i = hash(key)
        while keys[i].value != -1 {
            if key.equal(keys[i]) {
                vals[i] = value
                return
            }
            i = (i + 1) % M
        }
        keys[i] = key
        vals[i] = value
        N += 1
    }
    func delete(_ key: ComparableObject) {
        var contain = false
        for i in 0..<M {
            if key.equal(keys[i]) {
                contain = true
            }
        }
        if !contain {
            return
        }
        var i = hash(key)
        while key.value != keys[i].value {
            i = (i + 1) % M
        }
        keys[i].value = -1
        vals[i] = -1
        i = (i + 1) % M
        while keys[i].value != -1 {
            let keyToRedo = keys[i]
            let valueRedo = vals[i]
            keys[i].value = -1
            vals[i] = -1
            N -= 1
            put(keyToRedo, valueRedo)
            i = (i + 1) % M
        }
        N -= 1
        if N > 0 && N == M / 8 {
            resize(M / 2)
        }
    }
    func show() {
        for i in 0..<M {
            print(String(i) + "---" + "(" + String(keys[i].value) + ":" + String(vals[i]) + ")")
        }
    }
    private func hash(_ key: ComparableObject) -> Int {
        return key.value % M
    }
    private func resize(_ capicity: Int) {
        let t = LinearProbingHashST(M: capicity)
        for i in 0..<M {
            if keys[i].value != -1 {
                t.put(keys[i], vals[i])
            }
        }
        keys = t.keys
        vals = t.vals
        M = t.M
    }
}
