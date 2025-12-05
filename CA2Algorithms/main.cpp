#include <iostream>
#include "BinaryTree.h"
#include "Utils.h"
using namespace std;

int main()
{
    BinaryTree<Zombie> tree;

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

    for (Zombie z : zombies) tree.add(z);

    cout << "\n=== Zombies In-Order ===\n";
    tree.printInOrder();

    // Balance tree before displaying
    balanceBST(tree);

    displayTree(tree);

    Zombie target(700, "");
    BSTNode<Zombie>* found = findNode(tree.root, target);
    if (found) cout << "\nFound zombie: " << found->getItem() << endl;

    cout << "\nRemoving danger 20...\n";
    tree.remove(Zombie(20, ""));
    displayTree(tree);

    return 0;
}
