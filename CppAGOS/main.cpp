//
//  main.cpp
//  CppAGOS
//
//  Created by Administlator on 2020/06/24.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>

void printPermutations(std::string str) {
    if (str.length() == 1) {
        std::cout << str;
        std::cout << "\n";
        return;
    }
    int index = rand() % str.length();
    std::string c = str.substr(index, 1);
    std::cout << c;
    std::string new_str = str.substr(0, index) + str.substr(str.find(c) + 1);
    printPermutations(new_str);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    return 0;
}
