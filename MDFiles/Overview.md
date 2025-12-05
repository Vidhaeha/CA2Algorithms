## 😋 Overview
In this section, we will explore what a Binary Search Tree (BST) is, why it is used, and when it becomes the right choice in problem-solving. We will outline the problem it addresses, its common applications, and the reasoning behind choosing this particular data structure over others.

## What is a Binary Search Tree?

A Binary Search Tree (BST) is a form of a binary tree designed to store data in a way that allows fast searching, insertion, and deletion. Unlike a regular binary tree, a BST uses ordering rules:
The left child subtree of any node has values less than the node’s value.
The right child subtree has values greater than the node’s value.

## Why Use a Binary Search Tree? 😵‍💫

A Binary Search Tree is useful when you have a lot of data that needs to stay sorted and you want to find things quickly.

Instead of checking every item one by one, a BST narrows the search path step-by-step. This makes searching, adding, and removing data much faster.

Examples:

Search engines use BST-like structures to scan huge datasets and speed up search results.

Game engines, like the original Doom, used tree structures to decide what objects to draw and where they should appear on screen.

## 🕰️ When is a Binary Search Tree Used?

A BST is used when you need fast searching, inserting, and deleting.
Because of how it is organised, these operations take about O(log n) time on average, which is much faster than scanning every element.

Example:
If a website stores products and prices, a BST can help:

Quickly find the highest or lowest price

Add new products or remove old ones

Keep everything sorted as prices change

## 🧟‍♂️ Zombie Survival Radar System(Framing The Problem)

You’re in charge of a post-apocalyptic safe zone.
A radar scans the wasteland and detects zombies approaching from far away.

Each zombie sighting has a danger score:

10 → Slow crawler missing a leg

200 → Average walker

500 → Hungry sprinting zombie

900 → Screaming mutated nightmare

The higher the score, the more dangerous it is.
