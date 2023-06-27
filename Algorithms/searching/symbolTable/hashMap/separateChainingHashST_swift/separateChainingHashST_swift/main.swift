//
//  main.swift
//  separateChainingHashST_swift
//
//  Created by gmy on 2023/6/27.
//

import Foundation

print("Hello, World!")

let scst = SeparateChainingHashST(M: 100)

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

scst.put(key0, v0)
scst.put(key1, v1)
scst.put(key2, v2)
scst.put(key3, v3)
scst.put(key4, v4)
scst.put(key5, v5)
scst.put(key6, v6)
scst.put(key7, v7)
scst.put(key8, v8)
scst.put(key9, v9)
scst.put(key10, v10)
scst.put(key11, v11)
scst.put(key12, v12)
scst.put(key13, v13)
scst.put(key14, v14)
scst.put(key15, v15)
scst.put(key16, v16)
scst.put(key17, v17)
scst.put(key18, v18)
scst.put(key19, v19)
scst.show()

scst.delete(key7)
scst.show()

scst.put(key2, 113)
scst.show()

print("end")

