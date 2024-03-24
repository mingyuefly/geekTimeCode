export class Quick3String {
  static sorts(a: Array<string>) {
    Quick3String.sort(a, 0, a.length - 1, 0);
  }

  private static sort(a: Array<string>, lo: number, hi: number, d: number) {
    if (hi <= lo) { return; }
    let lt = lo, gt = hi;
    let v = Quick3String.charAt(a[lo], d);
    let i = lo + 1;
    while (i <= gt) {
      let t = Quick3String.charAt(a[i], d);
      if (t < v) {
        Quick3String.exch(a, lt++, i++);
      } else if (t > v) {
        Quick3String.exch(a, i, gt--);
      } else {
        i++;
      }
    }
    Quick3String.sort(a, lo, lt - 1, d);
    if (v >= 0) {
      Quick3String.sort(a, lt, gt, d + 1); // 中间这部分是相等的，可以直接进入下一位的比较
    }
    Quick3String.sort(a, gt + 1, hi, d);
  }

  private static exch(a: Array<string>, i: number, j: number) {
    let tmpS: string = a[i];
    a[i] = a[j];
    a[j] = tmpS;
  }

  private static charAt(s: string, d: number) {
    if (d < s.length) {
      return s.charCodeAt(d);
    } else {
      return -1;
    }
  }
}