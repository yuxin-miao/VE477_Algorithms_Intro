from FibonacciHeap import FibHeap

get_input = False

if __name__ == '__main__':
    graph = {}
    nodes = []
    fibNodeList = {}
    fh = FibHeap()
    pred = dict()
    if get_input:
        print('Begin')
    edge_num = int(input())
    if get_input:
        print(edge_num)

    for i in range(edge_num):
        x, y, w = input().split()
        if get_input:
            print(str(x) + ' ' + str(y) + ' ' + str(w))
        if x not in graph:
            graph[x] = {}
        graph[x][y] = int(w)
        nodes.append(x)
        nodes.append(y)

    if get_input:
        print('Finish graph')

    start_point = input()
    if get_input:
        print('Finish start', start_point)
    end_point = input()
    if get_input:
        print('Finish end', end_point)

    fib = FibHeap()
    vis = {}
    info = {}  # store distance / node, used to decrease key

    nodes = list(set(nodes))
    for node in nodes:
        fib_node = fib.insert(x=float('inf'), vertex=(node, graph[node]))
        vis[node] = False
        info[node] = [float('inf'), fib_node]
    if get_input:
        print('Finish fib')

    fib.decrease_key(info[start_point][1], 0)
    vis[start_point] = True

    prev = {}  # store the previous point
    # print(info.values())
    while False in vis.values():
        node_min = fib.extract_min()
        v = node_min.value[1]  # dict object
        vis[node_min.value[0]] = True
        for adj_v, w in v.items():  # adj_v: vertex's name, w: weight
            if vis[adj_v]:
                continue
            # print(int(node_min.key) + int(w))
            # print(info[adj_v][0])
            if node_min.key + int(w) < info[adj_v][0]:
                fib.decrease_key(info[adj_v][1], node_min.key + int(w))
                info[adj_v][0] = node_min.key + int(w)
                prev[adj_v] = node_min.value[0]
    if get_input:
        print('Finish dijk')

    result = [end_point]
    while end_point != start_point:
        result.insert(0, prev[end_point])
        end_point = prev[end_point]

    print(result)
