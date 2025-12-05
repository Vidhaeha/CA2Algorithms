## 😋 Overview
In this section, we will explore what a Binary Search Tree (BST) is, why it is used, and when it becomes the right choice in problem-solving. We will outline the problem it addresses, its common applications, and the reasoning behind choosing this particular data structure over others.

## What is a Binary Search Tree?

A Binary Search Tree (BST) is a form of a binary tree designed to store data in a way that allows fast searching, insertion, and deletion. Unlike a regular binary tree, a BST uses ordering rules:
The left child subtree of any node has values less than the node’s value.
The right child subtree has values greater than the node’s value.

## 🌳 Why Use a Binary Search Tree?

A BST lets you store zombies by their danger level, so you can:

Quickly find the most dangerous threats

Insert new zombie sightings fast

Remove cleared threats without reshuffling a whole list

Instead of scanning every zombie, your radar follows the BST rules:

➡️ Left = less scary zombies
➡️ Right = more terrifying ones


🧟‍♂️🧠 When is a Binary Search Tree Used?

A Binary Search Tree is used when you need to quickly search, insert, or remove data.

Because of how a BST stores information, it can perform these tasks in O(log n) time on average, which is much faster than checking every record one by one, important when the zoombies are running at you.

Example in the B.R.A.I.N.S. System:

The safe zone’s radar logs zombie threats. A BST helps by:

🧟‍♂️ Quickly finding the most dangerous zombie


➕ Adding new threats as they appear
(when scouts spot a new zombie, it enters the survival tree)

❌ Removing cleared threats
(once soldiers eliminate a zombie, it gets removed from the tree)

🔄 Keeping all danger levels sorted as the situation changes
(even if hundreds of zombies show up, the system still stays organised)

## 🧟‍♂️ B.R.A.I.N.S. — Binary Radar for Assessing Incoming Necrotic Severity(Framing The Problem)

You’re in charge of a post-apocalyptic safe zone.
A radar scans the wasteland and detects zombies approaching from far away.

Each zombie sighting has a danger score:

10 → Slow crawler missing a leg

200 → Average walker

500 → Hungry sprinting zombie

900 → Screaming mutated nightmare

The higher the score, the more dangerous it is.
