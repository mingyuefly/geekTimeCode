
export class TrieST {
  private static R: number = 256; // 基数
  private root: Node = new Node();
  get(key: string): number {
    let x: Node | undefined = this.getByKey(this.root, key, 0);
    if (typeof x == "undefined") {
      return -1;
    }
    return x.val;
  }
  private getByKey(x: Node, key: string, d: number): Node | undefined {
    if (typeof x == "undefined") {
      return x;
    }
    if (d == key.length) {
      return x;
    }
    let c: number = key.charCodeAt(d);
    return this.getByKey(x.next[c], key, d + 1);
  }
  put(key: string, val: number) {
    this.root = this.putByKey(this.root, key, val, 0);
  }
  private putByKey(x: Node, key: string, val: number, d: number) : Node {
    if (typeof x === "undefined") {
      x = new Node();
    }
    if (d == key.length) {
      x.val = val;
      return x;
    }
    let c = key.charCodeAt(d);
    x.next[c] = this.putByKey(x.next[c], key, val, d + 1);
    return x;
  }
}

class Node {
  val: number = -1;
  next: Array<Node> = new Array<Node>();
}

