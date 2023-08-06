//
//  Edge.swift
//  EdgeWeightedUndiGraph
//
//  Created by gmy on 2023/7/26.
//

import Foundation

struct Edge {
    private var v: Int
    private var w: Int
    private var weight: Double
    init(v: Int, w: Int, weight: Double) {
        self.v = v
        self.w = w
        self.weight = weight
    }
    func getWeight() -> Double {
        return weight
    }
    func getEither() -> Int {
        return v
    }
    func getOther(_ vertex: Int) -> Int {
        if vertex == v {
            return w
        } else if vertex == w {
            return v
        } else {
            return -1;
        }
    }
    func compareTo(_ that: Edge) -> Int {
        if weight < that.getWeight() {
            return -1
        } else if weight > that.getWeight() {
            return 1
        } else {
            return 0
        }
    }
    func toString() -> String {
        String(v) + "-" + String(w) + " " + String(weight)
    }
}



