//
//  main.swift
//  GroupPresentation
//
//  Created by Administlator on 2020/07/15.
//  Copyright © 2020 Administlator. All rights reserved.
//

import Foundation

func kthSmallest(arr: inout [Int], l: Int, r: Int, k: Int) {
    
    let pivotIndex: Int = partition(arr: &arr, l: l, r: r);
    
    
    let smallesLength: Int = pivotIndex - l
    
    if smallesLength == k - 1 {
        return
    }
    
    // sort numbers on ther left of pivot index
    if smallesLength > k - 1 {
        kthSmallest(arr: &arr, l: l, r: pivotIndex - 1, k: k)
        return
    }
    
    kthSmallest(arr: &arr, l: pivotIndex + 1, r: r, k: k - pivotIndex + l - 1)
    return
}

func partition(arr: inout [Int], l: Int, r: Int) -> Int {
    let x: Int = arr[r]
    var i = l;
    if (r-1 >= l) {
        for j in l...(r-1) {
            if (arr[j] <= x) {
                arr.swapAt(i, j)
                i += 1
            }
        }
        arr.swapAt(i, r)
    }
    
    return i;
}

func kthSmallestElements () {
    let k = 3
    var arr: [Int] = Array(0...9)
    arr.shuffle()
    print(arr)
    kthSmallest(arr: &arr, l: 0, r: arr.count - 1, k: k)
    
    var list: [Int] = Array(arr[0...(k-1)])
    list.sort()
    
    print("")
    print(String(k) + "'th smallest elements are " + list.description)
}



kthSmallestElements()
