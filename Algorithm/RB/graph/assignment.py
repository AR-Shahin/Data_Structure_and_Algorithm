
from queue import Queue


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


class BFS(Graph):
    def __init__(self, nodes, edges, is_directed=False):
        super().__init__(nodes, is_directed)
        self.add_multiple_edges(edges)
        self.visited = {}
        self.level = {}
        self.parent = {}
        self.output = []
        self.queue = Queue()

        # initail Task
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
bfs = BFS(nodes, edges)


source = input("Enter Source : ")
print(bfs.bfs_traversal(source))
destination = input("Enter Destination : ")

print(bfs.level_of_node(destination))
print(bfs.print_path(destination))
