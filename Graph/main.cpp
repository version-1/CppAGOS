//
//  main.cpp
//  Graph
//
//  Created by Administlator on 2020/07/23.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void dfs(vector<int> g, vector<bool>* visit, int index) {
    
    int p = index;
    
    while (!visit->at(p)) {
        visit->at(p) = true;
        p = g[p] - 1;
        dfs(g, visit, p);
    }
    
}

void cyclicPermutation() {
    int t;
    cout << "input:\n";
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        int c;
        cin >> n;
        vector<int> g;
        for (int j = 0; j < n; j++) {
            cin >> c;
            g.push_back(c);
        }
        
        vector<bool> visit(g.size(), false);
        
        int p = 0;
        int count = 0;
        while(p < g.size()) {
            if (!visit[p]) {
                count++;
                dfs(g, &visit, p);
            }
            p++;
        }
        cout << count << "\n";
    }
}


int main(int argc, const char * argv[]) {
    cyclicPermutation();
    return 0;
}
