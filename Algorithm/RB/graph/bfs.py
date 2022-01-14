
from graph import Graph
from queue import Queue


class BFS(Graph):
    def __init__(self, nodes, edges, is_directed=False):
        super().__init__(nodes, is_directed)
        self.add_multiple_edges(edges)
        self.visited = {}
        self.level = {}
        self.parent = {}
        self.output = []
        self.queue = Queue()

        for node in self.adj_list.keys():
            self.visited[node] = False
            self.parent[node] = None
            self.level[node] = -1

    def bfs_traversal(self, source):
        self.visited[source] = True
        self.level[source] = 0
        self.queue.put(source)

        while not self.queue.empty():
            u = self.queue.get()
            self.output.append(u)
            for v in self.adj_list[u]:
                if not self.visited[v]:
                    self.visited[v] = True
                    self.parent[v] = u
                    self.level[v] = self.level[u] + 1
                    self.queue.put(v)
        return self.output

    def level_of_node(self, node):
        return self.level[node]

    def print_path(self, destination):
        path = []

        while destination is not None:
            path.append(destination)
            destination = self.parent[destination]

        path.reverse()
        return path


nodes = ["1", "2", "3", "4", "5"]
edges = [
    ("1", "3"),
    ("1", "2"),
    ("1", "4"),
    ("2", "3"),
    ("2", "5"),
    ("3", "4"),
    ("3", "5"),
    ("4", "5"),
]

# edges = [
#     ("A", "B"),
#     ("B", "C"),
#     ("A", "D"),
#     ("D", "E"),
#     ("D", "F"),
#     ("E", "F"),
#     ("E", "G"),
#     ("F", "H"),
#     ("G", "H")
# ]
bfs = BFS(nodes, edges)

print(bfs.bfs_traversal("1"))

print(bfs.level_of_node("5"))

print(bfs.print_path("5"))
