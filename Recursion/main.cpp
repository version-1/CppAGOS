//
//  main.cpp
//  Recursion
//
//  Created by Administlator on 2020/06/24.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include <regex>

int calc(std::string str) {
    int left = stoi(str.substr(1,1));
    std::string expr = str.substr(2,1);
    int right = stoi(str.substr(3,1));
    
    if (expr == "+") {
        return left + right;
    }
    
    if (expr == "*") {
        return left * right;
    }
    return -1;
}

int evaluate(std::string str) {
    std::regex re1("[0-9]");
    if (regex_match(str, re1)) {
        return std::stoi(str);
    }
    
    std::regex re2("\\([0-9][+*][0-9]\\)");
    if (regex_match(str, re2)) {
        return calc(str);
    }
    
    std::regex re3("\\([0-9][+*]\\(.+\\)\\)");
    if (regex_match(str, re3)) {
        int left = stoi(str.substr(1,1));
        std::string expr = str.substr(2,1);
        std::string right = str.substr(3, (str.length() - 1) - 3);
        int i_right = evaluate(right);
        return calc("(" + std::to_string(left) + expr + std::to_string(i_right) + ")");
    }
    
    std::regex re4("\\(\\(.+\\)[+*][0-9]\\)");
    if (regex_match(str, re3)) {
        int left = stoi(str.substr(1,1));
        std::string expr = str.substr(2,1);
        std::string right = str.substr(3, (str.length() - 1) - 3);
        int i_right = evaluate(right);
        return calc("(" + std::to_string(left) + expr + std::to_string(i_right) + ")");
    }
    
    std::regex re5("\\(\\(.+\\)[+*]\\(.+\\)\\)");
    if (regex_match(str, re3)) {
        int left = stoi(str.substr(1,1));
        std::string expr = str.substr(2,1);
        std::string right = str.substr(3, (str.length() - 1) - 3);
        int i_right = evaluate(right);
        return calc("(" + std::to_string(left) + expr + std::to_string(i_right) + ")");
    }
        
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << evaluate("7");
    std::cout << "\n";
    std::cout << evaluate("(2*2)");
    std::cout << "\n";
    std::cout << evaluate("(1+(2*4))");
    std::cout << "\n";
    std::cout << evaluate("((1+3)+((1+2)*5))");
    std::cout << "\n";
    return 0;
}
