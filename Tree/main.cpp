//
//  main.cpp
//  Tree
//
//  Created by Administlator on 2020/07/20.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::string input;
    std::string line;
    std::cout << "input:" ;
    
    int count = 0;
    int length = -1;
    while (getline(std::cin, line))
    {
        input += line;
        if (count == 0) {
            length = std::stoi(line);
        }
        if (count >= length) {
            break;
        }
        count++;
    }
    std::cout << input;
    return 0;
}
