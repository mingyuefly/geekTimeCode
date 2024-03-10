export class LSD {
  static sorts(a: Array<string>, W: number) {
    let N = a.length;
    let R = 256;
    let aux: Array<string> = new Array<string>(N);
    console.log('');
    for (let d = W - 1; d >= 0; d--) {
      let count: Array<number> = new Array<number>(R + 1);
      for (let i = 0; i < count.length; i++) {
        count[i] = 0
      } // 是否有更便捷的初始化数组方法，同时初始化长度和默认值
      // console.log('count = ', count.toString())
      for (let i = 0; i < N; i++) {
        // let index: number = a[i].charCodeAt(d) + 1;
        // console.log('index = ' + index.toString());
        count[a[i].charCodeAt(d)+1]++;
      }
      // console.log('count = ', count.toString())
      for (let r = 0; r < R; r++) {
        count[r + 1] += count[r];
      }
      for (let i = 0; i < N; i++) {
        // let index: number = count[a[i].charCodeAt(d)];
        // console.log('index = ', index.toString())
        aux[count[a[i].charCodeAt(d)]++] = a[i];
        // console.log('aux = ' + aux.toString())
      }
      for (let i = 0; i < N; i++) {
        a[i] = aux[i];
      }
    }
  }
}




