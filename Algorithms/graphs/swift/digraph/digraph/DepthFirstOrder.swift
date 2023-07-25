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
                // 每一个dfs结束，说明所有和v连通的顶点都已经被搜索到了
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
        // 每个子dfs方法结束，说明递归的一个子调用栈结束
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
