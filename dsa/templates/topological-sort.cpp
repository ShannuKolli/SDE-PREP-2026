// =============================================
// TOPOLOGICAL SORT TEMPLATE
// Use when: ordering with dependencies, cycle detection in directed graph
// =============================================

// --- Kahn's Algorithm (BFS-based, preferred in interviews) ---
vector<int> topoSortBFS(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            indegree[neighbor]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int node = q.front(); q.pop();
        order.push_back(node);

        for (int neighbor : adj[node]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) q.push(neighbor);
        }
    }

    // If order.size() != n → cycle exists
    if (order.size() != n) return {}; // cycle detected
    return order;
}

// --- DFS-based Topological Sort ---
void dfsTopo(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor])
            dfsTopo(neighbor, adj, visited, st);
    }
    st.push(node); // post-order
}

vector<int> topoSortDFS(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;

    for (int i = 0; i < n; i++)
        if (!visited[i]) dfsTopo(i, adj, visited, st);

    vector<int> order;
    while (!st.empty()) {
        order.push_back(st.top()); st.pop();
    }
    return order;
}

// PROBLEMS USING THIS:
// - LC 207. Course Schedule (cycle detection)
// - LC 210. Course Schedule II (return order)
// - LC 269. Alien Dictionary (build graph from comparisons)
// - LC 802. Find Eventual Safe States
