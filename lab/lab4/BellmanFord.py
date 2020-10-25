from graph import SGraph

s_graph = SGraph()
edge_num = int(input())
dis = {}
for i in range(edge_num):
    x, y, w = input().split(" ")
    s_graph.add_edge(x, y, w)
    dis[x] = float('inf')
    dis[y] = float('inf')

start_point = input()
end_point = input()

dis[start_point] = 0
prev = {}
edge_dict = s_graph.return_edges()
for i in range(len(dis) - 1):
    for edge, w in edge_dict.items():
        if dis[edge[0]] + int(w) < dis[edge[1]]:
            dis[edge[1]] = dis[edge[0]] + int(w)
            prev[edge[1]] = edge[0]

result = [end_point]
while end_point is not start_point:
    result.insert(0, prev[end_point])
    end_point = prev[end_point]

print(result)
