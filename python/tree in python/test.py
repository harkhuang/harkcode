class Tree:
    def __init__(self, cargo, left=None, right=None):
        self.cargo = cargo
        self.left  = left
        self.right = right
    def __str__(self):
        return str(self.cargo)
def total(tree):
    if tree == None: return 0
    return total(tree.left) + total(tree.right) + tree.cargo
def print_tree(tree):
    if tree == None: return
    print tree.cargo,
    print_tree(tree.left)
    print_tree(tree.right)
    print("\n");

tree = Tree('+', Tree(1), Tree('*', Tree(2), Tree(3)))
print_tree(tree)