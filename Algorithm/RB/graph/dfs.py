
from graph import Graph


class DFS(Graph):
    def __init__(self, nodes, edges, is_directed=False):
        super().__init__(nodes, is_directed)
        self.add_multiple_edges(edges)
        self.color = {}
        self.parent = {}
        self.traverse_time = {}
        self.output = []
        self.time = 0

        for node in self.adj_list.keys():
            self.color[node] = "W"
            self.parent[node] = None
            self.traverse_time[node] = [-1, -1]

    def dfs_traversal(self, source):
        self.color[source] = "G"
        self.traverse_time[source][0] = self.time
        self.output.append(source)
        self.time += 1
        for v in self.adj_list[source]:
            if self.color[v] == "W":
                self.parent[v] = source
                self.dfs_traversal(v)
        self.color[source] = "B"
        self.traverse_time[source][1] = self.time
        self.time += 1
        return self.output

    def traversal_of_a_node(self, node):
        return self.traverse_time[node]

    def print_path(self, destination):
        path = []

        while destination is not None:
            path.append(destination)
            destination = self.parent[destination]

        path.reverse()

        return path


nodes = ["A", "B", "C", "D", "E", "F"]

# edges = [
#     ("A", "B"),
#     ("A", "C"),
#     ("B", "D"),
#     ("B", "E"),
#     ("C", "B"),
#     ("C", "F"),
#     ("E", "F"),
# ]

edges = [
    ("A", "B"),
    ("B", "D"),
    ("D", "C"),
    ("D", "E"),
    ("C", "F"),
]
dfs = DFS(nodes, is_directed=True, edges=edges)
# dfs.print_adj_list()

print(dfs.dfs_traversal("A"))
# print(dfs.print_path("C"))
