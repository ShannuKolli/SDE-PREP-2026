// =============================================
// UNION-FIND (DISJOINT SET UNION) TEMPLATE
// Use when: connected components, cycle detection (undirected), grouping
// =============================================

class UnionFind {
    vector<int> parent, rank_;
public:
    UnionFind(int n) {
        parent.resize(n);
        rank_.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    // Union by rank
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false; // already connected (cycle if undirected)

        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

// PROBLEMS USING THIS:
// - LC 684. Redundant Connection (find the edge that creates cycle)
// - LC 323. Number of Connected Components
// - LC 547. Number of Provinces
// - LC 721. Accounts Merge
// - LC 1971. Find if Path Exists in Graph
// - LC 990. Satisfiability of Equality Equations
