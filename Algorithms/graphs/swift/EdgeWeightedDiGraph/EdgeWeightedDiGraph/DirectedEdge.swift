//
//  DirectedEdge.swift
//  EdgeWeightedDiGraph
//
//  Created by GMY on 2023/8/17.
//

import Foundation

struct DirectedEdge {
    private var v: Int
    private var w: Int
    private var weight: Double
    init(_ v: Int, _ w: Int, _ weight: Double) {
        self.v = v
        self.w = w
        self.weight = weight
    }
    func getWeight() -> Double {
        return weight
    }
    func from() -> Int {
        return v
    }
    func to() -> Int {
        return w
    }
    func toString() -> String {
        String(v) + "-" + String(w) + " " + String(weight)
    }
}
