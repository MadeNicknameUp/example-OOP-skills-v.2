#ifndef BRANCH_H
#define BRANCH_H

#include <vector>
#include <iostream>

class Branch {
private:
    Branch* parent; // Pointer to the parent branch
    std::vector<Branch*> children; // List of child branches
    char elfName; // Name of the elf residing on this branch

    short getTreesAmount() const; // Get the number of trees in the forest
    short getBigBranchesPerTree() const; // Get the number of big branches per tree
    short getAvarageBranchesPerBigBranch() const; // Get the average number of branches per big branch
    short getDeep() const; // Get the depth of the current branch in the hierarchy
    void createForest(); // Recursively create the forest structure
    void printIt() const; // Recursively print the forest structure
    void printNeighbors(const char inElfName) const; // Print the neighbors of a specific elf
    bool find(char inElfName) const; // Find an elf by name in the forest

public:
    Branch(char name = 'N'); // Constructor with default elf name 'N'
    ~Branch(); // Destructor
    void generate(); // Generate the forest structure (only for the root branch)
    void display() const; // Display the forest structure (only for the root branch)
    bool neighborhood(char inElfName) const; // Find and display the neighborhood of an elf
};

#endif // BRANCH_H