//
//  main.cpp
//  ShortestPath
//
//  Created by Administlator on 2020/08/10.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

struct Flight {
    int node, cost, stops;
    Flight (int n, int c, int s)
    : node(n), cost(c), stops(s) {}
};

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<int> d(N+1, INT_MAX);
    d[K] = 0;
    for (int i = 0; i < N; i++) {
        for (vector<int> e: times) {
            int u = e[0];
            int v = e [1];
            int w = e[2];
            if (d[u] != INT_MAX && d[v] > d[u] + w) {
                d[v] = d[u] + w;
            }
        }
    }
    
    int maxCost = 0;
    for (int i = 1; i <= N; i++) {
        maxCost = max(maxCost, d[i]);
    }
    return maxCost == INT_MAX ? -1 : maxCost;
}

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<vector<int>> flight_to_cost(n, vector<int>(n, -1));
    for (const auto& flight : flights) {
        flight_to_cost[flight[0]][flight[1]] = flight[2];
    }
    
    unordered_set<int> visited;
    vector<int> node_to_stops(n, numeric_limits<int>::max());
    
    auto greater_cmp = [](const Flight& x, const Flight& y) -> bool {
        return x.cost > y.cost;
    };
    priority_queue<Flight, vector<Flight>, decltype(greater_cmp)> to_process(greater_cmp);
    to_process.emplace(src, 0, 0);
    
    while(!to_process.empty()) {
        auto [node, cost, stops] = to_process.top();
        to_process.pop();
        
        if (node == dst) return cost;
        
        if (stops > K) continue;
        
        if (!visited.count(node) || visited.count(node) && stops < node_to_stops[node]) {
            visited.emplace(node);
            node_to_stops[node] = stops;
            
            for (int i = 0; i < n; ++i) {
                if (flight_to_cost[node][i] != -1) {
                    to_process.emplace(i, cost + flight_to_cost[node][i], stops + 1);
                }
            }
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
