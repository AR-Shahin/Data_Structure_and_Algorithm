
class Graph:
    def __init__(self, nodes, is_directed=False):
        self.is_directed = is_directed
        self.nodes = nodes
        self.adj_list = {}

        for node in self.nodes:
            self.adj_list[node] = []

    def print_adj_list(self):
        for node in self.nodes:
            print("{} -> {}".format(node, self.adj_list[node]))

    def add_edge(self, u, v):
        self.adj_list[u].append(v)
        if not self.is_directed:
            self.adj_list[v].append(u)

    def add_multiple_edges(self, edges):
        for u, v in edges:
            self.add_edge(u, v)

    def display(self):
        print("Ok!")


nodes = ["A", "B", "C", "D", "E"]
edges = [
    ("A", "C"),
    ("A", "B"),
    ("B", "D"),
    ("C", "D"),
    ("C", "E"),
    ("D", "E"),
]
graph = Graph(nodes)

graph.add_multiple_edges(edges)
# graph.print_adj_list()
print(type(graph.adj_list))
