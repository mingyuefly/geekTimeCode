import {LSD} from './strings/LSD'
import {MSD} from './strings/MSD'

@Entry
@Component
struct Index {
  @State message: string = 'Hello World';

  aboutToAppear(): void {
    // test algorithms
    // this.lsdTest()

    this.msdTest()
  }

  lsdTest() {
    let s1 = "4PGC938"
    let s2 = "2IYE230"
    let s3 = "3CIO720"
    let s4 = "1ICK750"
    let s5 = "1OHV845"
    let s6 = "4JZY524"
    let s7 = "1ICK750"
    let s8 = "3CIO720"
    let s9 = "1OHV845"
    let s10 = "1OHV845"
    let s11 = "2RLA629"
    let s12 = "2RLA629"
    let s13 = "3ATW723"

    let strings: Array<string> = new Array<string>()
    strings.push(s1)
    strings.push(s2)
    strings.push(s3)
    strings.push(s4)
    strings.push(s5)
    strings.push(s6)
    strings.push(s7)
    strings.push(s8)
    strings.push(s9)
    strings.push(s10)
    strings.push(s11)
    strings.push(s12)
    strings.push(s13)

    strings.forEach((s, index) => {
      console.log(s)
    })

    console.log("")

    LSD.sorts(strings, 7)

    strings.forEach((s, index) => {
        console.log(s)
    })
  }

  msdTest() {
    let s1 = "she";
    let s2 = "sells";
    let s3 = "seashells";
    let s4 = "by";
    let s5 = "the";
    let s6 = "seashore";
    let s7 = "the";
    let s8 = "shells";
    let s9 = "she";
    let s10 = "sells";
    let s11 = "are";
    let s12 = "surely";
    let s13 = "seashells";

    let a: Array<string> = new Array<string>;
    a.push(s1);
    a.push(s2);
    a.push(s3);
    a.push(s4);
    a.push(s5);
    a.push(s6);
    a.push(s7);
    a.push(s8);
    a.push(s9);
    a.push(s10);
    a.push(s11);
    a.push(s12);
    a.push(s13);

    a.forEach((s, index) => {
      console.log(s);
    })

    console.log("******");

    MSD.sorts(a);

    a.forEach((s, index) => {
      console.log(s)
    })
  }

  build() {
    Row() {
      Column() {
        Text(this.message)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}