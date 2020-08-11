//
//  main.cpp
//  DP
//
//  Created by Administlator on 2020/08/10.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    vector<long long> memo(n+1, -1);
    if (n <= 2) {
      return n;
    }
    memo[1] = 1;
    memo[2] = 2;
    int i = 3;
    while(i <= n) {
       memo[i] = memo[i - 1] + memo[i - 2];
       i++;
    }

    return memo[n];
}

int makeOne(int n) {
    vector<long long> memo(n+1, -1);
    if (n <= 2) {
      return n;
    }
    memo[1] = 1;
    memo[2] = 2;
    int i = 3;
    while(i <= n) {
       memo[i] = memo[i - 1] + memo[i - 2];
       i++;
    }

    return memo[n];
}

int twoByNTiles(int n) {
    
    return 0;
}

int twoByNTiles2(int n) {
    
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
