//
//  Evaluation.cpp
//  Recursion
//
//  Created by Administlator on 2020/06/26.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include "Evaluation.hpp"
#include <iostream>
#include <regex>

int calc(std::string expr, int left, int right) {
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
        return stoi(str);
    }
    
    std::regex re2("\\([0-9][+*][0-9]\\)");
    if (regex_match(str, re2)) {
        int left = stoi(str.substr(1,1));
        std::string expr = str.substr(2,1);
        int right = stoi(str.substr(3,1));
        return calc(expr, left, right);
    }
    
    std::regex re3("\\([0-9][+*]\\(.+\\)\\)");
    if (regex_match(str, re3)) {
        int left = stoi(str.substr(1,1));
        std::string expr = str.substr(2,1);
        std::string right = str.substr(3, (str.length() - 1) - 3);
        int i_right = evaluate(right);
        return calc(expr, left, i_right);
    }
    
    std::regex re4("^\\(\\(.+\\)[+*][0-9]\\)$");
    if (regex_match(str, re4)) {
        std::string left = str.substr(1, (str.length() - 1) - 3);
        int i_left = evaluate(left);
        std::string expr = str.substr(str.length()-3,1);
        int right = stoi(str.substr(str.length()-2,1));
        
        return calc(expr, i_left, right);
    }
    
    std::regex re5("\\((\\(.+\\))[+*](\\(.+\\))\\)");
    std::smatch sm;
    regex_search(str, sm, re5);
    if (sm.size() >= 3) {
        std::string left = sm[1];
        std::string expr = str.substr(1 + left.length(),1);
        std::string right = sm[2];
        int i_left = evaluate(left);
        int i_right = evaluate(right);
        return calc(expr, i_left, i_right);
    }
        
    return -1;
}
