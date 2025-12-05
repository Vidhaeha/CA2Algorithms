#include <iostream>
#include <vector>
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
        tree.add(z);         // BST
        linearList.push_back(z); // Linear array
    }

    cout << "\n=== Zombies In-Order (BST) ===\n";
    tree.printInOrder();
    displayTree(tree);

    printZombieTypeByDanger(tree, 700);

    // Manual comparison search
    int target = 700;
    cout << "\nSearching in linear array...\n";
    int steps = 0;
    bool found = false;
    for (Zombie z : linearList)
    {
        steps++;
        if (z.dangerLevel == target)
        {
            cout << "Found zombie: " << z.type << " in " << steps << " steps.\n";
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Zombie not found in linear array.\n";

    cout << "\nRemoving danger 20 from BST...\n";
    tree.remove(Zombie(20, ""));
    displayTree(tree);

    cout << "\nBalancing BST...\n";
    balanceBST(tree);
    displayTree(tree);

    return 0;
}
