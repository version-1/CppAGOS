//
//  QueensSolver.swift
//  SwiftAGDS
//
//  Created by Derrick Park on 2019-03-13.
//  Copyright © 2019 Derrick Park. All rights reserved.
//

import Foundation

/// Write a function solveQueens that accepts a Board as a parameter
/// and tries to place 8 queens on it safely.
///
/// - Your method should stop exploring if it finds a solution
/// - You are allowed to change the function header (args or return type)
/// - Your total recursive calls should not exceed 120 times.

func solveQueens(board: inout Board, col: Int) -> String {
    board.tryCount += 1
    if (col > board.size) {
        return board.description
    }
    board.shuffleArray()
    for row in board.array {
        if board.isSafe(row: row, col: col) {
            board.place(row: row, col: col)
            break;
        }
    }
    return solveQueens(board: &board, col: col + 1)
}

