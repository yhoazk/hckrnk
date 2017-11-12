class Node:
    def __init__(self,data):
        self.right=self.left=None
        self.data = data
class Solution:
    def insert(self,root,data):
        if root==None:
            return Node(data)
        else:
            cur=Node(data)
            if data<=root.data:
                cur=self.insert(root.left,data)
                root.left=cur
            else:
                cur=self.insert(root.right,data)
                root.right=cur
        return root


    def getHeight(self,root):
        #Write your code here
        #if hasattr(root, 'left') and hasattr(root, 'left'):
        if root != None:
            try:
                return 1 + max(self.getHeight(root.left), self.getHeight(root.right))
            except AttributeError:
                pass

            try:
                return 1 + max(self.getHeight(root.left), 0)
            except AttributeError:
                pass

            try:
                return 1 + max(0, self.getHeight(root.right))
            except AttributeError:
                pass
            else:
                return 0

        else:
            return 0


T=int(raw_input())
myTree=Solution()
root=None
for i in range(T):
    data=int(raw_input())
    root=myTree.insert(root,data)
height=myTree.getHeight(root)
print height     
