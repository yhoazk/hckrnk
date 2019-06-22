
# Sample bin tree

import pytest

class bin_tree:
    node_count = 1
    def __init__(self, n = None):
        self.val = n
        self.left = None
        self.right = None
    
    def ln(self):
        return self.left
    
    def rn(self):
        return self.right
    
    def __str__(self):
        return str(self.val)
    
    def __add__(self, new_val):
        if new_val > self.val:
            if self.right is None:
                print("New right branch. Parent {}".format(self.val))
                self.right = bin_tree()
                self.right.val = new_val    
            else:
                self.right + new_val
        else:
            if self.left is None:
                print("New left branch. Parent {}".format(self.val))
                self.left = bin_tree()
                self.left.val = new_val
            else:
                self.left + new_val
                




def test_ByfirstAdding_RootKeepsVal():
    tree = bin_tree(2)
    assert('2' == str(tree))

def test_BySecondAdd_NodeIsInsertedLeft():
    tree = bin_tree(5)
    tree + 7
    tree + 4
    tree + 2
    tree + 1
    tree + 6
    
if "__main__" == __name__:
    test_BySecondAdd_NodeIsInsertedLeft()
    
    