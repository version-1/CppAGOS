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
    vector<int> rank, parents;
    UnionFind() {}
    UnionFind(int n) {  // make n trees.
        rank.resize(n, 0);
        parents.resize(n, 0);
        for (int i = 0; i < n; i++) {
            makeTree(i);
        }
    }
    void makeTree(int x) {
        parents[x] = x;  // the parent of x is x
        rank[x] = 0;
    }
    bool isSame(int x, int y) {
        return findRoot(x) == findRoot(y);
    }
    void unite(int x, int y) {
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
    int findRoot(int x) {

        if (x != parents[x]) parents[x] = findRoot(parents[x]);
        return parents[x];
    }
};
 
struct Edge {
    long long u;
    long long v;
    long long cost;
};
bool comp_e(const Edge &e1, const Edge &e2) { return e1.cost < e2.cost; }
 
struct Kruskal {
    UnionFind uft;
    long long sum;
    vector<Edge> edges;
    int V;
    Kruskal(const vector<Edge> &edges_, int V_) : edges(edges_), V(V_) {
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
    int N, M, D;
    cout << "input:\n";
    cin >> N >> M >> D;
    vector<Edge> edges(M);
    long sum = 0;
    for (int i = 0; i < M; i++) {
        long long s, t, w;
        cin >> s >> t >> w;
        Edge e = {s - 1, t -1, w};
        edges[i] = e;
        if (i < M - 1) {
          sum += w;
        }
    }
    
    Kruskal krs(edges, N);
    
    if (sum == krs.sum) {
        return 0;
    }
    
    for (int i = krs.edges.size() - 1; i >= 0; i--) {
        sum -= krs.edges[i].cost;
        if (sum <= krs.sum) {
            return krs.edges.size() - i;
        }
    }
    
    return 0;
}
