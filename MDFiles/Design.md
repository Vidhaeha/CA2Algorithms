# Binary Tree-In depth
Explanation string f
## Binary tree examples
Valid

![Image](../Images/ValidFullTree.png)
![Image](../Images/ValidLineTree.png)
![Image](../Images/ValidDoubleLineTree.png)
Invalid

![Image](../Images/InvalidDouble.png)
![Image](../Images/InvalidOrder.png)
![Image](../Images/InvalidParentSmallerThenLeft.png)

## Step by step of Creating a balanced tree
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
