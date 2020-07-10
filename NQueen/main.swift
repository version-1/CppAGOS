//
//  main.swift
//  NQueen
//
//  Created by Administlator on 2020/07/10.
//  Copyright © 2020 Administlator. All rights reserved.
//

import Foundation

var b = Board(size: 8)
var count = 0
while(b.qCount < 8) {
    solveQueens(board: &b, col: 0)
    count += b.tryCount
    if (b.qCount < 8) {
        b = Board(size: 8)
    }
}

print(b.description)
print(String(format: "%@%d", "try count: ", count))
