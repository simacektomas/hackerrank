def bfs(n, m, edges, s):
    distances = [-1] * (n+1)
    distances[s] = 0
    
    graph = {} 
    for i in range(0, n+1):
        graph[i] = set()
    for l, r in edges:
        graph[l].add(r)
        graph[r].add(l)
   
    # Create the tree structure
    
    current_level = [node for node in graph[s]]
    next_level = []
    
    depth = 1
    while True:
        for node in current_level:
            if distances[node] == -1: distances[node] = depth * 6
            for neigh in graph[node]:
                if distances[neigh] == -1: next_level.append(neigh) 
            
        if len(next_level) == 0:
            break
        current_level = next_level
        next_level = []
        depth += 1
    
    distances = distances[1:]
    distances.remove(0)
    return distances
