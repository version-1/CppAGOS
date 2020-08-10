//
//  main.cpp
//  PipeConnection
//
//  Created by Administlator on 2020/08/06.
//  Copyright © 2020 Administlator. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
 
struct UnionFind {  // The range of node number is u 0 v n-1
    vector<long long> rank, parents;
    UnionFind() {}
    UnionFind(long long n) {  // make n trees.
        rank.resize(n, 0);
        parents.resize(n, 0);
        for (long long i = 0; i < n; i++) {
            makeTree(i);
        }
    }
    void makeTree(long long x) {
        parents[x] = x;  // the parent of x is x
        rank[x] = 0;
    }
    bool isSame(long long x, long long y) {
        return findRoot(x) == findRoot(y);
    }
    void unite(long long x, long long y) {
        x = findRoot(x);
        y = findRoot(y);
        if (rank[x] > rank[y]) {
            parents[y] = x;
        } else {
            parents[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
    long long findRoot(long long x) {
        if (x != parents[x]) parents[x] = findRoot(parents[x]);
        return parents[x];
    }
};
 
struct Edge {
    long long u;
    long long v;
    long long cost;
    bool activate;
};
bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }
 
struct Kruskal {
    UnionFind uft;
    long long sum;
    vector<Edge> edges;
    long long V;
    Kruskal(const vector<Edge> &edges_, long long V_) : edges(edges_), V(V_) {
        init();
    }
    void init() {
        sort(edges.begin(), edges.end(), comp_e);
        uft = UnionFind(V);
        sum = 0;
        for (auto e : edges) {
            if (!uft.isSame(e.u, e.v)) {
                uft.unite(e.u, e.v);
                sum += e.cost;
            }
        }
    }
};
 
int main() {
    long long N, M, D;
    cout << "input:\n";
    cin >> N >> M >> D;
    vector<Edge> edges(M);

    long long maxCostInActivated = 0;
    long long maxCostIndex = 0;
    for (long long i = 0; i < M; i++) {
        long long s, t, w;
        cin >> s >> t >> w;
        
        bool activate = i < N -1;
        Edge e = {s - 1, t -1, w, activate};
        if (activate && maxCostInActivated < w) {
            maxCostIndex = i;
            maxCostInActivated = w;
        }
        edges[i] = e;
    }
    edges[maxCostIndex].cost = edges[maxCostIndex].cost - D > 0 ? edges[maxCostIndex].cost - D : 0;
    
    
    Kruskal krs(edges, N);
    

    
    long long days = 0;
    for (long long i = 0; i < N -1; i++){
        if (!krs.edges[i].activate) {
            days++;
        }
    }
    return days;
}
