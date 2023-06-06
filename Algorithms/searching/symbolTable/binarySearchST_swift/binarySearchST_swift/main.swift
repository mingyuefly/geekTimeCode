//
//  main.swift
//  binarySearchST_swift
//
//  Created by gmy on 2023/6/6.
//

import Foundation

print("Hello, World!")

var st = BinarySearchST(capicity: 2)
var key0 = ComparableObject(value: 3)
var key1 = ComparableObject(value: 4)
var key2 = ComparableObject(value: 5)
var key3 = ComparableObject(value: 7)
var key4 = ComparableObject(value: 9)
var key5 = ComparableObject(value: 14)

var v0 = 11
var v1 = 12
var v2 = 13
var v3 = 14
var v4 = 15
var v5 = 16

st.put(key0, v0)
st.show()
st.put(key2, v2)
st.show()
st.put(key1, v1)
st.show()
st.put(key4, v4)
st.show()
st.put(key5, v5)
st.show()
st.put(key3, v3)
st.show()

st.put(key4, 24)
st.show()

print(st.ceiling(ComparableObject(value: 8)).value)
print(st.ceiling(ComparableObject(value: 3)).value)
print(st.floor(ComparableObject(value: 8)).value)
print(st.floor(ComparableObject(value: 3)).value)
print(st.floor(ComparableObject(value: 1)).value)


st.deleteKey(key2)
st.show()
st.deleteKey(key3)
st.show()
st.deleteKey(key4)
st.show()
st.deleteKey(key5)
st.show()
st.deleteKey(key1)
st.show()
