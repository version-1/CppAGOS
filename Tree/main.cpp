//
//  main.cpp
//  Tree
//
//  Created by Administlator on 2020/07/20.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

void split(const std::string& str, std::vector<std::string>& cont, char delim = ' ')
{
    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

std::vector<std::vector<std::string>> prompt() {
    std::vector<std::vector<std::string>> input;
    std::cout << "input:" ;
    
    std::string line;
    int count = 0;
    int length = -1;
    while (getline(std::cin, line))
    {
        if (count > 0 && line.length() > 0) {
            std::vector<std::string> splitedLine;
            split(line, splitedLine, ' ');
            input.push_back(splitedLine);
        }
        
        if (count == 0) {
            length = std::stoi(line);
        }
        if (count >= length) {
            break;
        }
        count++;
    }
    
    return input;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<std::vector<std::string>> input = prompt();
    
    return 0;
}
