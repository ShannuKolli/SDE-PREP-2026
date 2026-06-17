# =============================================
# BFS / DFS TEMPLATES (Graph + Tree)
# Use when: traversal, shortest path (unweighted), connected components
# =============================================

from collections import deque


# --- BFS (Level-order, shortest path in unweighted graph) ---
def bfs(adj, start, n):
    visited = [False] * n
    queue = deque([start])
    visited[start] = True

    while queue:
        node = queue.popleft()
        # process node

        for neighbor in adj[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append(neighbor)


# --- DFS (Recursive) ---
def dfs(adj, node, visited):
    visited[node] = True
    # process node

    for neighbor in adj[node]:
        if not visited[neighbor]:
            dfs(adj, neighbor, visited)


# --- DFS on Grid (2D matrix) ---
def dfs_grid(grid, i, j, m, n):
    if i < 0 or j < 0 or i >= m or j >= n:
        return
    if grid[i][j] == 0:  # already visited or not valid
        return

    grid[i][j] = 0  # mark visited

    for di, dj in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
        dfs_grid(grid, i + di, j + dj, m, n)


# --- BFS Shortest Path (return distance) ---
def bfs_shortest_path(adj, src, dest, n):
    dist = [-1] * n
    queue = deque([src])
    dist[src] = 0

    while queue:
        node = queue.popleft()
        if node == dest:
            return dist[dest]

        for neighbor in adj[node]:
            if dist[neighbor] == -1:
                dist[neighbor] = dist[node] + 1
                queue.append(neighbor)

    return -1  # unreachable


# --- BFS Level-Order (useful for trees and level-based problems) ---
def bfs_levels(adj, start):
    visited = {start}
    queue = deque([start])
    level = 0

    while queue:
        for _ in range(len(queue)):  # process entire level
            node = queue.popleft()
            # process node at this level

            for neighbor in adj[node]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        level += 1


# PROBLEMS USING THIS:
# - LC 200. Number of Islands (DFS Grid)
# - LC 994. Rotting Oranges (BFS Grid — multi-source)
# - LC 133. Clone Graph (DFS + hashmap)
# - LC 417. Pacific Atlantic Water Flow (DFS Grid from boundary)
# - LC 127. Word Ladder (BFS shortest path)
