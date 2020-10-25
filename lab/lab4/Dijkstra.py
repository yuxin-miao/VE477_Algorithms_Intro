from FibonacciHeap import FibHeap
from graph import DGraph

get_input = True

d_graph = DGraph()
edge_num = int(input())
if get_input:
    print(edge_num)
vis = {}
info = {}  # store distance / node, used to decrease key
for i in range(edge_num):
    x, y, w = input().split(" ")
    if get_input:
        print(str(x) + ' ' + str(y) + ' ' + str(w) + '\n')
    d_graph.add_edge(x, y, w)

start_point = input()
end_point = input()
if get_input:
    print(start_point)
    print(end_point)
d_graph.print_graph()

fib = FibHeap()
for key, vertex in d_graph.v_dict.items():
    # key: vertex's name, vertex: Vertex type object
    if key == start_point:
        node = fib.insert(x=0, vertex=vertex)
        info[key] = [0, node]
        vis[key] = True
    else:
        node = fib.insert(x=float('inf'), vertex=vertex)
        info[key] = [float('inf'), node]
        vis[key] = False

prev = {}  # store the previous point
# print(info.values())
while False in vis.values():
    node_min = fib.extract_min()
    v = node_min.value  # Vertex object
    vis[v.return_name()] = True
    for adj_v, w in v.adjacent.items():  # adj_v: vertex's name, w: weight
        if vis[adj_v]:
            continue
        # print(int(node_min.key) + int(w))
        # print(info[adj_v][0])
        if node_min.key + int(w) < info[adj_v][0]:
            fib.decrease_key(info[adj_v][1], node_min.key + int(w))
            info[adj_v][0] = node_min.key + int(w)
            prev[adj_v] = v.return_name()

result = [end_point]
while end_point is not start_point:
    result.insert(0, prev[end_point])
    end_point = prev[end_point]


print(result)
