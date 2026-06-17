# =============================================
# TOPOLOGICAL SORT TEMPLATE
# Use when: ordering with dependencies, cycle detection in directed graph
# =============================================

from collections import deque


# --- Kahn's Algorithm (BFS-based, preferred in interviews) ---
def topo_sort_bfs(n, adj):
    indegree = [0] * n
    for u in range(n):
        for v in adj[u]:
            indegree[v] += 1

    queue = deque([i for i in range(n) if indegree[i] == 0])
    order = []

    while queue:
        node = queue.popleft()
        order.append(node)

        for neighbor in adj[node]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)

    # If len(order) != n → cycle exists
    return order if len(order) == n else []


# --- DFS-based Topological Sort ---
def topo_sort_dfs(n, adj):
    visited = [False] * n
    stack = []

    def dfs(node):
        visited[node] = True
        for neighbor in adj[node]:
            if not visited[neighbor]:
                dfs(neighbor)
        stack.append(node)  # post-order

    for i in range(n):
        if not visited[i]:
            dfs(i)

    return stack[::-1]  # reverse post-order


# PROBLEMS USING THIS:
# - LC 207. Course Schedule (cycle detection)
# - LC 210. Course Schedule II (return order)
# - LC 269. Alien Dictionary (build graph from comparisons)
# - LC 802. Find Eventual Safe States
