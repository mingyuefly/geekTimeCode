
export class MSD {
  static sorts(a: Array<string>) {
    let N = a.length;
    MSD.aux = new Array<string>(N);
    MSD.sort(a, 0, N - 1, 0);
  }
  private static R = 256; // 基数
  private static M = 3; // 小数组的切换阈值
  private static aux: Array<string>; // 数组分类的辅助数组
  private static sort(a: Array<string>, lo: number, hi: number, d: number) {
    if (hi <= lo + MSD.M) {
      MSD.insertion(a, lo, hi, d);
      return;
    }
    let count: Array<number> = new Array<number>(MSD.R + 2);
    for (let i = 0; i < count.length; i++) {
      count[i] = 0;
    }
    for (let i = lo; i <= hi; i++) {
      count[MSD.charAt(a[i], d) + 2]++;
    }
    for (let r = 0; r < MSD.R + 1; r++) {
      count[r + 1] += count[r];
    }
    for (let i = lo; i <= hi; i++) {
      MSD.aux[count[MSD.charAt(a[i], d) + 1]++] = a[i];
    }
    for (let i = lo; i <= hi; i++) {
      a[i] = MSD.aux[i - lo];
    }
    // 递归的以每个字符为键进行排序
    for (let r = 0; r < MSD.R; r++) {
      MSD.sort(a, lo + count[r], lo + count[r + 1] - 1, d + 1);
    }
  }
  private static charAt(s: string, d: number) {
    if (d < s.length) {
      return s.charCodeAt(d);
    } else {
      return -1;
    }
  }
  private static insertion(a: Array<string>, lo: number, hi: number, d: number) {
    for(let i = lo + 1; i <= hi; i++) {
      for (let j = i; j > lo && MSD.less(a[j], a[j - 1]); j--) {
        MSD.exch(a, j, j - 1);
      }
    }
  }
  private static exch(a: Array<string>, i: number, j: number) {
    let tmpS: string = a[i];
    a[i] = a[j];
    a[j] = tmpS;
  }
  private static less(s1: string, s2: string): boolean {
    let length = 0;
    if (s1.length < s2.length) {
      length = s1.length;
    } else {
      length = s2.length;
    }
    for (let i = 0; i < length; i++) {
      if (s1.charCodeAt(i) < s2.charCodeAt(i)) {
        return true;
      }
      if (s1.charCodeAt(i) > s2.charCodeAt(i)) {
        return false;
      }
    }
    return s1.length <= s2.length;
  }
}