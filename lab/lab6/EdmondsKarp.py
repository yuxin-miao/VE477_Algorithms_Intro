from collections import defaultdict


class Graph:

    def __init__(self):
        # self.graph = graph  # residual graph
        self.graph = {}
        self.v_num = 0
        self.v_list = []

    def add_edge(self, u, v, w):
        if u not in self.v_list:
            self.graph[u] = {}
            self.v_num = self.v_num + 1
            self.v_list.append(u)
        if v not in self.v_list:
            self.graph[v] = {}
            self.v_num = self.v_num + 1
            self.v_list.append(v)

        self.graph[u][v] = w


def BFS(Bgraph, s, t, parent):
    vis = {}
    for num in range(Bgraph.v_num):
        vis[Bgraph.v_list[num]] = False

    queue = [s]

    vis[s] = True
    while queue:
        u = queue.pop(0)

        for key, val in Bgraph.graph[u].items():
            if not vis[key] and val > 0:
                queue.append(key)
                vis[key] = True
                parent[key] = u

    return True if vis[t] else False


# Returns tne maximum flow from s to t in the given graph
def EdmondsKarp(Bgraph, source, sink):
    parent = {}

    for num in range(Bgraph.v_num):
        parent[Bgraph.v_list[num]] = -1
    max_flow = 0
    while BFS(Bgraph, source, sink, parent):

        path_flow = float("Inf")
        s = sink
        while s != source:
            path_flow = min(path_flow, Bgraph.graph[parent[s]][s])
            s = parent[s]
        max_flow += path_flow

        v = sink
        while v != source:
            u = parent[v]
            new_val = Bgraph.graph[u][v] - path_flow
            Bgraph.graph[u][v] = new_val
            new_val = Bgraph.graph[u][v] + path_flow
            Bgraph.graph[v][u] = new_val
            v = parent[v]

    return max_flow


edge_num = int(input())
g = Graph()
for i in range(edge_num):
    nodeA, nodeB, weight = input().split()
    g.add_edge(nodeA, nodeB, int(weight))

source = input()
sink = input()

print(EdmondsKarp(g, source, sink))

# This code is contributed by Neelam Yadav
