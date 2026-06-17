# =============================================
# DIJKSTRA'S ALGORITHM TEMPLATE
# Use when: shortest path in WEIGHTED graph (non-negative weights)
# =============================================

import heapq


def dijkstra(n, adj, src):
    """
    adj[u] = [(v, weight), ...]
    Returns shortest distances from src to all nodes.
    """
    dist = [float('inf')] * n
    dist[src] = 0
    # min-heap: (distance, node)
    pq = [(0, src)]

    while pq:
        d, u = heapq.heappop(pq)

        if d > dist[u]:
            continue  # stale entry

        for v, w in adj[u]:
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                heapq.heappush(pq, (dist[v], v))

    return dist


# KEY INSIGHT:
# - Dijkstra = BFS + priority queue (greedy: always process closest node)
# - Does NOT work with negative weights (use Bellman-Ford for that)
# - Time: O((V + E) log V) with min-heap
# - Python's heapq is a min-heap by default (perfect for Dijkstra)

# PROBLEMS USING THIS:
# - LC 743. Network Delay Time (direct Dijkstra)
# - LC 787. Cheapest Flights Within K Stops (modified — BFS or Bellman-Ford better)
# - LC 1631. Path with Minimum Effort (Dijkstra on grid)
# - LC 778. Swim in Rising Water (Dijkstra on grid)
