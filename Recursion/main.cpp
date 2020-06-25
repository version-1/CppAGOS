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


//void evaluateRecursion(std::string str, int sum) {
//  if (regex_match (str, re(/[0-9]/) ) {
//      return sum
//  }
//   if (regex_match(str, refex())
//
//
//    return evaluate(str, sum);
//}


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
