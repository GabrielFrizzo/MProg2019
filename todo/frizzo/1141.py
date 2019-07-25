def find_insertion_nodes(nodes, word):
    eligible_children = []
    for node in nodes:
        for child in node.children:
            if child.value in word:
                eligible_children.append(child)
    if eligible_children == []:
        return nodes
    return find_insertion_nodes(eligible_children, word)

class Node:
    def __init__(self, value = None):
        self.value = value
        self.children = []

    def height(self):
        child_heights = [child.height() for child in self.children]
        if child_heights == []:
            return 1
        return max(child_heights)+1

    def print(self, tabs=0):
        for child in self.children:
            print('\t'*tabs + child.value + ':')
            child.print(tabs+1)

class Tree:
    def __init__(self):
        self.head = Node()

    def add_node(self, value):
        best_leaves = find_insertion_nodes([self.head], value)
        for leaf in best_leaves:
            leaf.children.append(Node(value))

    def height(self):
        return self.head.height()

    def print(self):
        self.head.print()

while True:
    nlines = int(input())
    if nlines == 0: break

    words = []
    for line in range(nlines):
        words.append(input())
    words = sorted(words, key = len)

    tree = Tree()
    for word in words:
        tree.add_node(word)

    print(tree.height()-1)
