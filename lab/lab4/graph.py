class Vertex:
    def __init__(self, name):
        self.name = name
        self.adjacent = {}  # use a dictionary to track all the neighbors

    def add_neighbor(self, neighbor, w):
        self.adjacent[neighbor] = w

    def return_w(self, neighbor):
        return self.adjacent[neighbor]


# implementation of a class for sparse graph
class SGraph:
    def __init__(self):
        self.e_dict = {}
        self.edge_num = 0

    def add_vertex(self, v):
        self.e_dict[(v, )] = 0

    def remove_vertex(self, v):
        for pair in self.e_dict:
            if v in pair:
                pair.remove(v)
            if v in pair:
                self.e_dict.pop(pair)

    def add_edge(self, u, v, w):
        self.e_dict[(u, v)] = w
        self.edge_num = self.edge_num + 1

    def remove_edge(self, u, v):
        self.e_dict.pop((u, v))

    def is_adjacent(self, u, v):
        for pair in self.e_dict:
            if (u, v) == pair or (v, u) == pair:
                return True
        return False

    def get_edge_weight(self, u, v):
        if (u, v) in self.e_dict:
            return self.e_dict[(u, v)]
        if (v, u) in self.e_dict:
            return self.e_dict[(v, u)]
        else:
            print("no such edge")
            return 0

    def set_edge_weight(self, u, v, new_w):
        if (u, v) in self.e_dict:
            self.e_dict[(u, v)] = new_w
        if (v, u) in self.e_dict:
            self.e_dict[(v, u)] = new_w
        else:
            print("no such edge")
            return 0

    def get_vertex_value(self):
        v_name = []
        for pair, weight in self.e_dict.items():
            v_name.append(pair[0])
            v_name.append(pair[1])

        v_uni = list(set(v_name))
        print(v_uni)

    def set_vertex_value(self, v, new_val):
        for pair in self.e_dict:
            if v in pair:
                weight = self.e_dict[pair]
                if v is pair[0]:
                    new_p = (new_val, pair[1])
                else:
                    new_p = (pair[0], new_val)
                self.e_dict.pop(pair)
                self.e_dict[new_p] = weight

    def print_graph(self):
        for pair, weight in self.e_dict.items():
            print("edge: {}, w={}".format(pair, weight))


# implementation of a class for dense graph
class DGraph:
    def __init__(self):
        self.v_dict = {}
        self.v_num = 0

    def add_vertex(self, v):
        new_v = Vertex(v)
        self.v_dict[v] = new_v
        self.v_num = self.v_num + 1

    def remove_vertex(self, v):
        try:
            self.v_dict.pop(v)
        except KeyError:
            print("vertex [{}] does not exist!".format(v))

    def add_edge(self, first, second, w):
        if first not in self.v_dict:
            self.add_vertex(first)
        if second not in self.v_dict:
            self.add_vertex(second)

        (self.v_dict[first]).add_neighbor(second, w)
        (self.v_dict[second]).add_neighbor(first, w)

    def remove_edge(self, first, second):
        try:
            self.v_dict[first].adjacent.pop(second)
            self.v_dict[second].adjacent.pop(first)
        except KeyError:
            print("edge from [{}] to [{}] not exist!".format(first, second))

    def is_adjacent(self, v, u):
        if u in self.v_dict:
            return v in self.v_dict[u].adjacent
        else:
            print("vertex not exist")
            return False

    def get_edge_weight(self, v, u):
        if self.is_adjacent(v, u):
            return self.v_dict[v].return_w(u)
        else:
            print("no edge from [{}] to [{}]".format(v, u))

    def set_edge_weight(self, v, u, new_w):
        if self.is_adjacent(v, u):
            self.v_dict[v].adjacent[u] = new_w
        else:
            print("no edge from [{}] to [{}]".format(v, u))

    def get_vertex_value(self):
        print("all vertex in this graph: ", end='')
        for key in self.v_dict:
            print(key, end=' ')

    def set_vertex_value(self, v, new_value):
        if v in self.v_dict:
            self.v_dict[v] = new_value
        else:
            print("vertex [{}] do not exist".format(v))

    def print_graph(self):
        for key in self.v_dict:
            for u, w in self.v_dict[key].adjacent.items():
                print("vertex [{}] to [{}], w={}".format(key, u, w))



