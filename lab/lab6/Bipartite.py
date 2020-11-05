from EdmondsKarp import EdmondsKarp, Graph


def Bipartite(graph, left, right):

    for l_v in left:
        graph.add_edge('s', l_v, 1)
    for r_v in right:
        graph.add_edge(r_v, 't', 1)
    return EdmondsKarp(graph, 's', 't')


# demonstrate the same graph in slides
left_ver = range(1, 6)
right_ver = range(6, 10)
g = Graph()
g.add_edge(1, 6, 4)
g.add_edge(2, 6, 4)
g.add_edge(2, 8, 3)
g.add_edge(3, 7, 2)
g.add_edge(3, 8, 7)
g.add_edge(3, 9, 10)
g.add_edge(4, 8, 1)
g.add_edge(5, 8, 2)
g.add_edge(5, 9, 3)

print(Bipartite(g, left_ver, right_ver))




