//
//  main.cpp
//  Tree
//
//  Created by Administlator on 2020/07/21.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

void split(const string& str, vector<std::string>& cont, char delim = ' ')
{
    stringstream ss(str);
    string token;
    while (getline(ss, token, delim)) {
        cont.push_back(token);
    }
}

vector<vector<string>> prompt() {
    vector<vector<string>> input;
    cout << "input:" ;
    
    string line;
    int count = 0;
    int length = -1;
    while (getline(std::cin, line))
    {
        if (count > 0 && line.length() > 0) {
            vector<string> splitedLine;
            split(line, splitedLine, ' ');
            input.push_back(splitedLine);
        }
        
        if (count == 0) {
            length = stoi(line);
        }
        if (count >= length) {
            break;
        }
        count++;
    }
    
    return input;
}

void myParent(vector<vector<string>> input) {
    vector<int> parents(input.size() + 1, -1);
    for (int i = 0; i < input.size(); i++) {
        int key = stoi(input.at(i).at(0));
        int value = stoi(input.at(i).at(1));
        vector<int> parent;
        parents[value - 1] = key;
    }
    
    for (int i = 0; i < parents.size(); i++) {
        if (parents[i] != -1) {
            cout << parents[i] << "\n";
        }
    }
}

int main(int argc, const char * argv[]) {
    vector<vector<string>> input = prompt();
    myParent(input);
    
    return 0;
}
