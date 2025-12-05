Main
1. Data Setup

An array of Zombie objects is created, each with a danger level and a type.

Zombies are added to:

Binary Search Tree (BST) – to allow fast, ordered searches.

Linear array (vector) – to illustrate simple linear search.

HashMap (unordered_map) – for constant-time average lookup.

2. BST Operations

Insertion (tree.add): Adds each zombie in the BST, keeping the binary search property (left < node < right).

Search (printZombieTypeByDanger): Traverses the BST to find a zombie by dangerLevel. This demonstrates O(log n) average-time search.

Remove (tree.remove): Deletes a node from the BST, handling three cases:

Node with no children (leaf)

Node with one child

Node with two children (replaces with in-order successor)

Balance (balanceBST): Converts the BST into a balanced BST to ensure efficient future searches.

Display (displayTree): Shows the tree sideways with indentation, representing depth visually.

3. Linear Array Operations

Search: Iterates over the array to find the zombie with the target danger level.

Counts the number of steps to find the target.

Demonstrates O(n) time complexity.

Delete: Finds the zombie and removes it using vector::erase.

Re-add: Adds the deleted zombie back to maintain data integrity.

4. HashMap Operations

Search: Uses unordered_map::find to locate the zombie by danger level.

Average time complexity O(1).

Delete: Removes the zombie using unordered_map::erase.

Re-add: Restores the deleted zombie using operator[].

5. Timing

All searches and delete operations are timed using std::chrono in microseconds, showing the efficiency difference between:

BST – logarithmic time

Linear array – linear time

HashMap – constant average time

6. Purpose

Compare search efficiency across data structures.

Demonstrate deletion and re-insertion in BST, array, and hashmap.

Show how balancing a BST improves search performance.

Visually represent the tree structure for easier understanding.

<img width="550" height="442" alt="image" src="https://github.com/user-attachments/assets/ec201b27-67cb-4bdb-a017-bf4102855e87" />

<img width="360" height="109" alt="image" src="https://github.com/user-attachments/assets/55bcf837-dc4c-40c6-9780-feae282e9115" />

<img width="163" height="38" alt="image" src="https://github.com/user-attachments/assets/9305b20c-e2cd-4cca-a6a1-f629163f476d" />

<img width="630" height="115" alt="image" src="https://github.com/user-attachments/assets/e48eeca8-b33f-4cb3-beb4-df0a205a842c" />

<img width="603" height="363" alt="image" src="https://github.com/user-attachments/assets/8a2a77df-1d10-4d7a-b446-42d98db92102" />

<img width="831" height="260" alt="image" src="https://github.com/user-attachments/assets/be518e92-df5d-4dd6-8d5a-48fcbac18a14" />

<img width="601" height="143" alt="image" src="https://github.com/user-attachments/assets/796fff0f-6d77-4009-a553-eba1c8c3d99e" />

<img width="605" height="332" alt="image" src="https://github.com/user-attachments/assets/2d1ed5de-6a68-4ba3-8b8a-0ad389b2b746" />

<img width="595" height="178" alt="image" src="https://github.com/user-attachments/assets/4e2da7d9-dc96-4374-b0ea-a11fa3ef50f7" />


