//
//  main.cpp
//  Recursion
//
//  Created by Administlator on 2020/06/24.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include "Evaluation.hpp"
#include "Backtracking.hpp"



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "############## roll dice combi ##";
    std::cout << "\n";
    std::cout << rollDiceCombination(3);
    std::cout << "\n\n\n";
    
    std::cout << "############## evaluate ##";
    std::cout << "\n";
    std::cout << evaluate("7");
    std::cout << "\n";
    std::cout << evaluate("(2*2)");
    std::cout << "\n";
    std::cout << evaluate("(1+(2*5))");
    std::cout << "\n";
    std::cout << evaluate("((2*4)+1)");
    std::cout << "\n";
    std::cout << evaluate("((3*5)+((1+2)*5))");
    std::cout << "\n";
    return 0;
}
