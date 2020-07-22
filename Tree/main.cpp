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
#include <queue>
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

void myParent() {
    vector<vector<string>> input = prompt();
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

vector<int> bfs(vector<vector<string>> input, int root) {
    vector<int> dist(input.size(), 0);
    vector<int> farNode(2, 0);
    queue<int> que;
    
    que.push(root);
  
    while(!que.empty()) {
        int v = que.front();
        que.pop();
        
        vector<string> row = input[v];
        for (int i = 1; i < row.size() - 1; i = i + 2) {
            int nodeIndex = stoi(row[i]) - 1;
            int distance = stoi(row[i+1]);
            if (nodeIndex == root || dist[nodeIndex] != 0) {
                continue;
            }
            
            // add distance
            dist[nodeIndex] = dist[v] + distance;
            if (farNode.at(1) < dist[nodeIndex]) {
                farNode[0] = nodeIndex;
                farNode[1] = dist[nodeIndex];
            }
            que.push(nodeIndex);
        }
    }
    return farNode;
}

void diameter () {
    vector<vector<string>> input = prompt();
    vector<int> farNodeFromRoot = bfs(input, 0);
    vector<int> result = bfs(input, farNodeFromRoot[0]);
    cout << result[1] << "\n";
}

int main(int argc, const char * argv[]) {
    myParent();
    diameter();
    
    return 0;
}
