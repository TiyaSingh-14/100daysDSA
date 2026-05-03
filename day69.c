function dijkstra(graph, source):
    dist = array of size V, initialized to ∞
    dist[source] = 0

    pq = min-heap
    pq.push((0, source))

    while pq is not empty:
        (d, u) = pq.pop()

        if d > dist[u]:
            continue

        for each (v, weight) in graph[u]:
            if dist[u] + weight < dist[v]:
                dist[v] = dist[u] + weight
                pq.push((dist[v], v))

    return dist
