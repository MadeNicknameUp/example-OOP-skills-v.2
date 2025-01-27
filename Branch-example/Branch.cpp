#include "Branch.h"
#include <cstdlib> // for std::rand

// Implementation of Branch class methods

short Branch::getTreesAmount() const {
    return 5; // Return the fixed number of trees in the forest
}

short Branch::getBigBranchesPerTree() const {
    return 3 + std::rand() % 3; // Return a random number of big branches per tree (3 to 5)
}

short Branch::getAvarageBranchesPerBigBranch() const {
    return 2 + std::rand() % 2; // Return a random number of average branches per big branch (2 to 3)
}

short Branch::getDeep() const {
    if (parent == nullptr)
        return 1; // If this is the root branch, return depth 1
    return 1 + parent->getDeep(); // Recursively calculate the depth
}

void Branch::createForest() {
    const short DEEP = getDeep(); // Get the current depth of the branch

    if (DEEP > 3) return; // Stop recursion if depth exceeds 3

    static char character = 65; // Start with character 'A' for elf names

    const int BRANCHES_COUNT = (DEEP == 1) ? getTreesAmount() 
                            : (DEEP == 2) ? getBigBranchesPerTree() 
                            : getAvarageBranchesPerBigBranch(); // Determine the number of branches to create

    for (int i = 0; i < BRANCHES_COUNT; i++) {
        Branch* newBranch = new Branch((DEEP == 1) ? 'N' : character % 128); // Create a new branch with a name
        character++; // Increment the character for the next elf name
        newBranch->parent = this; // Set the parent of the new branch
        children.push_back(newBranch); // Add the new branch to the children list
        newBranch->createForest(); // Recursively create the forest structure
    }
}

void Branch::printIt() const {
    const short DEEP = getDeep(); // Get the current depth of the branch

    std::string tabs = (DEEP == 4) ? "\t\t\t - (Avarage Branch)" : (DEEP == 3) ? "\t\t - (Big Branch)" 
                        : (DEEP == 2) ? "\t - (Three)" : " - (Forest)"; // Format the output based on depth

    bool printed = false; // Flag to control printing

    if (children.empty()) {
        std::cout << tabs << elfName << std::endl; // Print the current branch if it has no children
        return;
    }

    for (const auto& child : children) {
        if (!printed) {
            std::cout << tabs << elfName << std::endl; // Print the current branch name
            printed = true;
        }
        child->printIt(); // Recursively print the child branches
    }
}

void Branch::printNeighbors(const char inElfName) const {
    if (inElfName != elfName)
        std::cout << "Elf " << elfName << std::endl; // Print the elf name if it's not the one being searched for

    for (const auto& child : children) {
        getDeep(); // Calculate the depth (not used directly here)
        child->printNeighbors(inElfName); // Recursively print the neighbors
    }
}

bool Branch::find(char inElfName) const {
    if (elfName == inElfName) {
        if (getDeep() == 3)
            printNeighbors(inElfName); // Print neighbors if the elf is found at depth 3
        return true; // Return true if the elf is found
    }

    for (const auto& child : children) {
        if (child->find(inElfName)) {
            if (getDeep() == 3)
                printNeighbors(inElfName); // Print neighbors if the elf is found in a child branch
            return true; // Return true if the elf is found
        }
    }

    return false; // Return false if the elf is not found
}

Branch::Branch(char name) : elfName(name), parent(nullptr) {} // Constructor implementation

Branch::~Branch() {
    for (Branch* child : children)
        delete child; // Recursively delete all child branches
}

void Branch::generate() {
    if (this->parent != nullptr) {
        std::cerr << "Error: This function can only be used with main object!" << std::endl;
        return; // Prevent generating from non-root branches
    }
    createForest(); // Start creating the forest structure
}

void Branch::display() const {
    if (parent != nullptr) {
        std::cerr << "Error: This function can only be used with main object!" << std::endl;
        return; // Prevent displaying from non-root branches
    }
    printIt(); // Print the forest structure
}

bool Branch::neighborhood(char inElfName) const {
    if (parent != nullptr) {
        std::cerr << "Error: This function can only be used with main object!" << std::endl;
        return false; // Prevent neighborhood search from non-root branches
    }
    return find(inElfName); // Start searching for the elf
}