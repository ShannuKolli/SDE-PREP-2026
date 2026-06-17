// =============================================
// DIJKSTRA'S ALGORITHM TEMPLATE
// Use when: shortest path in WEIGHTED graph (non-negative weights)
// =============================================

// Returns shortest distances from src to all nodes
vector<int> dijkstra(int n, vector<vector<pair<int,int>>>& adj, int src) {
    // adj[u] = {{v, weight}, ...}
    vector<int> dist(n, INT_MAX);
    // min-heap: {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();

        if (d > dist[u]) continue; // stale entry

        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// KEY INSIGHT:
// - Dijkstra = BFS + priority queue (greedy: always process closest node)
// - Does NOT work with negative weights (use Bellman-Ford for that)
// - Time: O((V + E) log V) with min-heap

// PROBLEMS USING THIS:
// - LC 743. Network Delay Time (direct Dijkstra)
// - LC 787. Cheapest Flights Within K Stops (modified — BFS or Bellman-Ford better)
// - LC 1631. Path with Minimum Effort (Dijkstra on grid)
// - LC 778. Swim in Rising Water (Dijkstra on grid)
