

from graph import Graph


class BFS(Graph):
    def __init__(self, nodes, is_directed=False):
        super().__init__(nodes, is_directed=is_directed)

    def bfs_traversal(self):
        pass


nodes = ["A", "B", "C", "D", "E"]
bfs = BFS(nodes)

bfs.display()
