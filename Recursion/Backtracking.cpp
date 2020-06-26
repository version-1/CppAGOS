//
//  Backtracking.cpp
//  CppAGOS
//
//  Created by Administlator on 2020/06/26.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <vector>
#include "Backtracking.hpp"

using namespace std;

int rollDiceCombination(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 6;
    }
    
    return (6-n + 1) * rollDiceCombination(n-1);
}

void rollDiceSum(int n, int sum, vector<vector<int>> chocies) {
//    if (n == 0) {
//        vector<vector<int>> data(0);
//        std::cout << data;
//    }
//
//    if (n == 1) {
//        vector<vector<int>> data(0);
//        cout << data;
//    }
    return;
}

