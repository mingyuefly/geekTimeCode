//
//  DepthFirstOrder.swift
//  digraph
//
//  Created by gmy on 2023/7/24.
//

import Foundation

class DepthFirstOrder {
    private var marked: [Bool]
    private var pre: Queue<Int>
    private var post: Queue<Int>
    private var reversePost: Stack<Int>
    init(marked: [Bool], pre: Queue<Int>, post: Queue<Int>, reversePost: Stack<Int>) {
        self.marked = marked
        self.pre = pre
        self.post = post
        self.reversePost = reversePost
    }
    convenience init(g: inout Digraph) {
        let marked = [Bool](repeating: false, count: g.getV())
        let pre = Queue<Int>()
        let post = Queue<Int>()
        let reversePost = Stack<Int>()
        self.init(marked: marked, pre: pre, post: post, reversePost: reversePost)
        for v in 0..<g.getV() {
            if !self.marked[v] {
                dfs(&g, v)
            }
        }
    }
    private func dfs(_ g: inout Digraph, _ v: Int) {
        pre.enqueue(v)
        marked[v] = true
        g.adj[v].forEach { w in
            if !marked[w] {
                dfs(&g, w)
            }
        }
        post.enqueue(v)
        reversePost.push(v)
    }
    func getPre() -> Queue<Int> {
        return pre
    }
    func getPost() -> Queue<Int> {
        return post
    }
    func getReversePost() -> Stack<Int> {
        return reversePost
    }
}
