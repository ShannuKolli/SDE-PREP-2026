// =============================================
// BFS / DFS TEMPLATES (Graph + Tree)
// Use when: traversal, shortest path (unweighted), connected components
// =============================================

// --- BFS (Level-order, shortest path in unweighted graph) ---
void bfs(vector<vector<int>>& adj, int start, int n) {
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        // process node

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// --- DFS (Recursive) ---
void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited) {
    visited[node] = true;
    // process node

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(adj, neighbor, visited);
        }
    }
}

// --- DFS on Grid (2D matrix) ---
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void dfsGrid(vector<vector<int>>& grid, int i, int j, int m, int n) {
    if (i < 0 || j < 0 || i >= m || j >= n) return;
    if (grid[i][j] == 0) return; // already visited or not valid

    grid[i][j] = 0; // mark visited

    for (int d = 0; d < 4; d++) {
        dfsGrid(grid, i + dx[d], j + dy[d], m, n);
    }
}

// --- BFS Shortest Path (return distance) ---
int bfsShortestPath(vector<vector<int>>& adj, int src, int dest, int n) {
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(src);
    dist[src] = 0;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        if (node == dest) return dist[dest];

        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return -1; // unreachable
}

// PROBLEMS USING THIS:
// - LC 200. Number of Islands (DFS Grid)
// - LC 994. Rotting Oranges (BFS Grid — multi-source)
// - LC 133. Clone Graph (DFS + hashmap)
// - LC 417. Pacific Atlantic Water Flow (DFS Grid from boundary)
// - LC 127. Word Ladder (BFS shortest path)
