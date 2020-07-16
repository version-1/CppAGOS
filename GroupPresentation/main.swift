//
//  main.swift
//  GroupPresentation
//
//  Created by Administlator on 2020/07/15.
//  Copyright © 2020 Administlator. All rights reserved.
//

import Foundation

var count = 0
func kthSmallest(arr: inout [Int], l: Int, r: Int, k: Int) {
    
    let pos: Int = partition(arr: &arr, l: l, r: r);
    
    if pos - l == k - 1 {
        return
    }
    if pos - l > k - 1 {
        kthSmallest(arr: &arr, l: l, r: pos - 1, k: k)
        return
    }
    
    kthSmallest(arr: &arr, l: pos + 1, r: r, k: k - pos + l - 1)
    return
}

func partition(arr: inout [Int], l: Int, r: Int) -> Int {
    let x: Int = arr[r]
    var i = l;
    if (r-1 >= l) {
        for j in l...(r-1) {
            count += 1
            if (arr[j] <= x) {
                arr.swapAt(i, j)
                i += 1
            }
        }
        arr.swapAt(i, r)
    }
    
    return i;
}

func main () {
    let k = 3
    var arr: [Int] = [3, 5, 6, 7, 8, 25]
    arr.shuffle()
    print(arr)
    kthSmallest(arr: &arr, l: 0, r: arr.count - 1, k: k)
    
    var list: [Int] = Array(arr[0...(k-1)])
    list.sort()
    
    print(String(k) + "'th smallest elements are " + list.description)
    print("count " + String(count) )
}

main()
