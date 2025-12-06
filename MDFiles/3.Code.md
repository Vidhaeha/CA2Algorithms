Main
1. Data Setup
a collection of Zombie objects, each with a danger level and a type. These zombies are stored in a Binary Search Tree (BST), a linear array, and a hashmap to allow comparisons of different data structures.

2. BST Operations

In the BST, zombies are added in a way that maintains the binary search property, which allows fast, ordered searches. Searching for a zombie in the BST follows the left or right branches according to the target danger level, demonstrating efficient logarithmic-time operations.

The BST also supports deletion, handling all possible cases: leaf nodes, nodes with one child, or nodes with two children using the in-order successor. After deletion, the BST can be balanced to maintain optimal search performance.

3. Linear Array Operations

The linear array stores zombies sequentially. Searching involves iterating through each element until the target is found, demonstrating linear time complexity. Deletion is handled by erasing the element from the vector, and the deleted zombie is re-added to keep the dataset consistent.

4. HashMap Operations

The hashmap allows near-constant time lookup and deletion by using the danger level as the key. Searching uses find, deletion uses erase, and re-insertion is done with operator[], illustrating the efficiency of hash-based structures.

5. Timing

Finally, timing measurements for all operations are taken using std::chrono in microseconds. This setup provides a clear comparison of how the choice of data structure affects search speed, deletion, and overall performance, and also visualizes the structure of the BST for better understanding.

<img width="550" height="442" alt="image" src="https://github.com/user-attachments/assets/ec201b27-67cb-4bdb-a017-bf4102855e87" />

<img width="360" height="109" alt="image" src="https://github.com/user-attachments/assets/55bcf837-dc4c-40c6-9780-feae282e9115" />

<img width="163" height="38" alt="image" src="https://github.com/user-attachments/assets/9305b20c-e2cd-4cca-a6a1-f629163f476d" />

<img width="630" height="115" alt="image" src="https://github.com/user-attachments/assets/e48eeca8-b33f-4cb3-beb4-df0a205a842c" />

<img width="603" height="363" alt="image" src="https://github.com/user-attachments/assets/8a2a77df-1d10-4d7a-b446-42d98db92102" />

<img width="831" height="260" alt="image" src="https://github.com/user-attachments/assets/be518e92-df5d-4dd6-8d5a-48fcbac18a14" />

<img width="601" height="143" alt="image" src="https://github.com/user-attachments/assets/796fff0f-6d77-4009-a553-eba1c8c3d99e" />

<img width="605" height="332" alt="image" src="https://github.com/user-attachments/assets/2d1ed5de-6a68-4ba3-8b8a-0ad389b2b746" />

<img width="595" height="178" alt="image" src="https://github.com/user-attachments/assets/4e2da7d9-dc96-4374-b0ea-a11fa3ef50f7" />


