# =============================================
# UNION-FIND (DISJOINT SET UNION) TEMPLATE
# Use when: connected components, cycle detection (undirected), grouping
# =============================================


class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
        self.rank = [0] * n

    # Find with path compression
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])  # path compression
        return self.parent[x]

    # Union by rank
    def union(self, x, y):
        px, py = self.find(x), self.find(y)
        if px == py:
            return False  # already connected (cycle if undirected)

        if self.rank[px] < self.rank[py]:
            px, py = py, px
        self.parent[py] = px
        if self.rank[px] == self.rank[py]:
            self.rank[px] += 1
        return True

    def connected(self, x, y):
        return self.find(x) == self.find(y)


# PROBLEMS USING THIS:
# - LC 684. Redundant Connection (find the edge that creates cycle)
# - LC 323. Number of Connected Components
# - LC 547. Number of Provinces
# - LC 721. Accounts Merge
# - LC 1971. Find if Path Exists in Graph
# - LC 990. Satisfiability of Equality Equations
