
from queue import Queue
import queue

adj_list = {
    "A": ["B", "D"],
    "B": ["A", "C"],
    "C": ["B"],
    "D": ["A", "E", "F"],
    "E": ["D", "F", "G"],
    "F": ["D", "E", "H"],
    "G": ["E", "H"],
    "H": ["G", "F"]
}

visited = {}
level = {}
parent = {}
output = []
queue = Queue()

for node in adj_list.keys():
    visited[node] = False
    parent[node] = None
    level[node] = -1


# print(visited)
# print(level)
# print(parent)

source = "A"
visited[source] = True
level[source] = 0
queue.put(source)

while not queue.empty():
    u = queue.get()
    output.append(u)

    for v in adj_list[u]:
        if not visited[v]:
            visited[v] = True
            parent[v] = u
            level[v] = level[u] + 1
            queue.put(v)

print(output)
print(level["G"])

dest = "G"
path = []

while dest is not None:
    path.append(dest)
    dest = parent[dest]
path.reverse()

print(path)
