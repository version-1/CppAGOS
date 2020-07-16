//
//  main.swift
//  GroupPresentation
//
//  Created by Administlator on 2020/07/15.
//  Copyright © 2020 Administlator. All rights reserved.
//

import Foundation

var count = 0
func kthSmallest(arr: inout [Int], l: Int, r: Int, k: Int) -> Int {
    
    let pos: Int = partition(arr: &arr, l: l, r: r);
    
    print("after", pos, l, k)
    if pos - l == k - 1 {
        return arr[pos];
    }
    if pos - l > k - 1 {
        return kthSmallest(arr: &arr, l: l, r: pos - 1, k: k);
    }
    
    return kthSmallest(arr: &arr, l: pos + 1, r: r, k: k - pos + l - 1);
}

func partition(arr: inout [Int], l: Int, r: Int) -> Int {
    let x: Int = arr[r]
    var i = l;
    if (r-1 > l) {
        for j in l...(r-1) {
            count += 1
            if (arr[j] <= x) {
                arr.swapAt(i, j);
                i += 1;
            }
        }
        arr.swapAt(i, r);
    }
    
    return i;
}

func main () {
    let k = 4
    var arr: [Int] = [10, 4, 7, 9, 5, 1, 2, 8, 3]
    arr.shuffle()
    print(arr)
    let smallest = kthSmallest(arr: &arr, l: 0, r: arr.count - 1, k: k)
    print(arr)
    
    var list: [Int] = [smallest]
    for item in arr {
        if (item < smallest) {
            list.append(item)
        }
    }
    
    print("K'th smallest elements are " + list.description)
    print("count " + String(count) )
}

main()
