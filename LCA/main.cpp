//
//  main.cpp
//  LCA
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

int main(int argc, const char * argv[]) {
    cout << "input:";
    int n;
    cin >> n;
    int i = n - 1;
    vector<vector<int>> tree(n, vector<int>(0));
    vector<int> depth(n,-1);
    vector<int> parents(n, -1);
    while(i > 0) {
        int j, k;
        cin >> j >> k;
        
        tree[j-1].push_back(k-1);
        tree[k-1].push_back(j-1);
        i--;
    }

    depth[0] = 0;
    queue<int> q;
    q.push(0);
    
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v: tree[u]) {
            if (depth[v] == -1) {
                depth[v] = depth[u] + 1;
                parents[v] = u;
                q.push(v);
            }
        }
        
    }
    
    int m;
    cin >> m;
    while(m > 0) {
        int j, k;
        cin >> j >> k;
        if (depth[j-1] < depth[k-1]) {
            int tmp  = k;
            k = j;
            j = tmp;
        }
        
        while(depth[j-1] != depth[k-1]) {
            j = parents[j-1] + 1;
        }
        
        while(j != k) {
            j = parents[j-1] + 1;
            k = parents[k-1] + 1;
        }
        
        cout << j << "\n";
        m--;
    }

    return 0;
}
