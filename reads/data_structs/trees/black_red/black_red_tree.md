# Black and Red trees

This is a special type of binary tree. A black and red tree is a self-balancing tree, where each node of the binary
tree has an extra bit, and that bit is often interprented as the color
(red or black) of the node. These colors are used to ensure the tree remains
approximaterly balanced during insertions and deletions.

Balance is preserved by painting each node of the tree with one of the two
colors in a way that satisfies certain properties, which collectively constrain
how unbalanced the tree can become in the worst case.

The balacing of the tree is not perfect, but is good enough to allow it to
guarantee searching in O(log n) time. Where N is the number of elements in the
tree.
| Operation      | average        | Worst Case     |
| :------------- | :------------- | :------------- |
| Space          | O(n)           | O(n)           |
| search         | O(log n)       | O(log n)       |
| insert         | O(log n)       | O(log n)       |
| delete         | O(log n)       | O(log n)       |
