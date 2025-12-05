#include <iostream>
#include <vector>
#include <chrono>
#include "BinaryTree.h"
#include "Utils.h"
#include "Zombie.h"
using namespace std;

int main()
{
    BinaryTree<Zombie> tree;
    vector<Zombie> linearList;

    Zombie zombies[] = {
        {880,  "Hive-mind necro leader"},
        {920,  "Berserker juggernaut"},
        {970,  "Shadow phase assassin zombie"},
        {999,  "Titan necromancer — controls hordes"},
        {1000, "DO NOT ENGAGE — Apocalypse Class Entity (world ender)"},
        {560, "Wall-climbing creeper"},
        {640, "Acid spit mutant"},
        {700, "Muscle-enhanced brute"},
        {760, "Tactical stalker — moves silently"},
        {800, "Infection thrower — spreads plague clouds"},
        {260, "Grocery-store bargainer zombie"},
        {310, "Fast teen runner zombie"},
        {400, "Corner-lurking ambush zombie"},
        {450, "Pack hunter — calls others over"},
        {500, "Screaming sprint zombie"},
        {20,  "Limb-dragging crawler"},
        {45,  "Lost wanderer moaning at birds"},
        {80,  "Freshly turned suburban dad"},
        {120, "One-eyed shuffler"},
        {180, "Missing-jaw groaner that can’t bite properly"}
    };

    // Add zombies manually
    for (Zombie z : zombies)
    {
        tree.add(z);              // BST
        linearList.push_back(z);  // Linear array
    }

    cout << "\n=== Zombies In-Order (BST) ===\n";
    tree.printInOrder();
    balanceBST(tree);
    displayTree(tree);

    int targetDanger = 760;

    // BST Search
    auto start = chrono::high_resolution_clock::now();
    printZombieTypeByDanger(tree, targetDanger);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "BST search took " << duration << " microseconds.\n";

    // Linear Search
    cout << "\nSearching in linear array...\n";
    start = chrono::high_resolution_clock::now();
    bool found = false;
    for (Zombie z : linearList)
    {
      if (z.dangerLevel == targetDanger)
        {
            cout << "Found zombie: " << z.type << "\n";
            found = true;
            break;
        }
    }
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "Linear search took " << duration << " microseconds.\n";

    if (!found)
        cout << "Zombie not found in linear array.\n";

    // Remove timing
    cout << "\nRemoving danger 20 from BST...\n";
    start = chrono::high_resolution_clock::now();
    tree.remove(Zombie(20, ""));
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "BST remove took " << duration << " microseconds.\n";
    displayTree(tree);

    // Balance timing
    cout << "\nBalancing BST...\n";
    start = chrono::high_resolution_clock::now();
    balanceBST(tree);
    end = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::microseconds>(end - start).count();
    cout << "BST balance took " << duration << " microseconds.\n";
    displayTree(tree);

    return 0;
}
