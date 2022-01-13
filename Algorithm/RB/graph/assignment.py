

from queue import Queue


class BFS:
    def __init__(self, adj_list):
        self.adj_list = adj_list
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


# adj_list = {
#     "A": ["B", "D"],
#     "B": ["A", "C"],
#     "C": ["B"],
#     "D": ["A", "E", "F"],
#     "E": ["D", "F", "G"],
#     "F": ["D", "E", "H"],
#     "G": ["E", "H"],
#     "H": ["G", "F"]
# }

rb = {
    "1": ["2", "3", "4"],
    "2": ["1", "3", "5"],
    "3": ["5", "2", "4", "1"],
    "4": ["1", "3", "5"],
    "5": ["4", "3", "2"],
}
bfs = BFS(rb)


source = input("Enter Source : ")
print(bfs.bfs_traversal(source))
destination = input("Enter Destination : ")

print(bfs.level_of_node(destination))
print(bfs.print_path(destination))
