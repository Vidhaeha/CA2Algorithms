# Binary Tree-In depth
Binary Search Tree, BST in short, is such a binary tree where every node has a unique key, every Node to the left, is smaller and every Node to the right is larger.
## Binary tree examples
### Invalid

#### There can't be duplicate
![Image](../Images/InvalidDouble.png)
#### They have to follow the correct order
Smaller numbers on the left, bigger numbers on the right
![Image](../Images/InvalidOrder.png)
#### Boundary error
Children of Left Nodes cannot be larger then their Parents
Children of Right Nodes cannot be smaller then their Parents
![Image](../Images/InvalidParentSmallerThenLeft.png)

### Valid

![Image](../Images/ValidFullTree.png)
![Image](../Images/ValidLineTree.png)
![Image](../Images/ValidDoubleLineTree.png)


## Step by step of Creating a balanced tree
![Image](../Images/Array.png)
### 1)Find root node
It is the closest number to the (lowest+highest)/2
![Image](../Images/BSTStep1.png)

### 2)Find Children
You look to the left for the closest number to the (lowest+root)/2

Then you look to the right for the closest number to the (root+highest)/2
![Image](../Images/BSTStep2.png)

### 3)Find Children of Children
Do the same step as before, look left, look right but do it for each child Node
![Image](../Images/BSTStep3.png)

### 4)Etc. until the end
![Image](../Images/BSTStep4.png)
