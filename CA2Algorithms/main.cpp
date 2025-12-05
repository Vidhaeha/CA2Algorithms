#include <iostream>
#include "BinaryTree.h"
#include "Utils.h"
#include "Zombie.h"
using namespace std;

int main()
{
    BinaryTree<Zombie> tree;

	// Sample zombies with various danger levels
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
        //{400, "Corner-lurking ambush zombie"},
        {450, "Pack hunter — calls others over"},
        {500, "Screaming sprint zombie"},
        {20,  "Limb-dragging crawler"},
        {45,  "Lost wanderer moaning at birds"},
        {80,  "Freshly turned suburban dad"},
        {120, "One-eyed shuffler"},
        {180, "Missing-jaw groaner that can’t bite properly"}
    };

    cout << "\n=== B.R.A.I.N.S. ===\n";
    cout << "Binary Search Tree of Zombie Danger Levels\n";

	// Add zombies to the tree
    for (Zombie z : zombies) tree.add(z);

	// Display tree before balancing
    cout << "\n=== Zombies In-Order ===\n";
    tree.printInOrder();
	balanceBST(tree);
    displayTree(tree);

    // Add more manually as needed
    tree.add(Zombie(400, "Corner-lurking ambush zombie"));
    balanceBST(tree);
    displayTree(tree);


	// Test finding zombies by danger level
    printZombieTypeByDanger(tree, 700);


	// Test removing a zombie
    cout << "\nRemoving danger 20...\n";
    tree.remove(Zombie(20, ""));
    displayTree(tree);

	// Re-balance after removal
    cout << "\nBalancing tree...\n";
    balanceBST(tree);
    displayTree(tree);

    return 0;
}
