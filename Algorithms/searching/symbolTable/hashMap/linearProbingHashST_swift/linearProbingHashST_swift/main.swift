//
//  main.swift
//  linearProbingHashST_swift
//
//  Created by gmy on 2023/6/28.
//

import Foundation

print("Hello, World!")

let lpst = LinearProbingHashST()

let key0 = ComparableObject(value: 1001)
let key1 = ComparableObject(value: 1002)
let key2 = ComparableObject(value: 1003)
let key3 = ComparableObject(value: 1004)
let key4 = ComparableObject(value: 10003)
let key5 = ComparableObject(value: 1006)
let key6 = ComparableObject(value: 1016)

let key7 = ComparableObject(value: 10006)
let key8 = ComparableObject(value: 1007)
let key9 = ComparableObject(value: 1008)
let key10 = ComparableObject(value: 1009)
let key11 = ComparableObject(value: 1011)
let key12 = ComparableObject(value: 1012)
let key13 = ComparableObject(value: 10012)

let key14 = ComparableObject(value: 10003)
let key15 = ComparableObject(value: 1000006)
let key16 = ComparableObject(value: 1000016)
let key17 = ComparableObject(value: 10017)
let key18 = ComparableObject(value: 1018)
let key19 = ComparableObject(value: 1019)
let key20 = ComparableObject(value: 1023)

let v0 = 11
let v1 = 12
let v2 = 13
let v3 = 14
let v4 = 15
let v5 = 16
let v6 = 17
let v7 = 18
let v8 = 19
let v9 = 20
let v10 = 21
let v11 = 22
let v12 = 23
let v13 = 24
let v14 = 25
let v15 = 26
let v16 = 27
let v17 = 28
let v18 = 29
let v19 = 30
let v20 = 33

lpst.put(key0, v0)
lpst.put(key1, v1)
lpst.put(key2, v2)
lpst.put(key3, v3)
lpst.put(key4, v4)
lpst.put(key5, v5)
lpst.put(key6, v6)
lpst.put(key7, v7)
lpst.put(key8, v8)
lpst.put(key9, v9)
lpst.put(key10, v10)
lpst.put(key11, v11)
lpst.put(key12, v12)
lpst.put(key13, v13)
lpst.put(key14, v14)
lpst.put(key15, v15)
lpst.put(key16, v16)
lpst.put(key17, v17)
lpst.put(key18, v18)
lpst.put(key19, v19)
lpst.put(key20, v20)

lpst.show()

lpst.delete(key7)
lpst.show()

lpst.put(key2, 113)
lpst.show()




print("end")
