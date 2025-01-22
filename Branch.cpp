#include "Branch.h"
#include <cstdlib> // для std::rand

// Реализация методов класса Branch
short Branch::getTreesAmount() const {
    return 5;
}

short Branch::getBigBranchesPerTree() const {
    return 3 + std::rand() % 3;
}

short Branch::getAvarageBranchesPerBigBranch() const {
    return 2 + std::rand() % 2;
}

short Branch::getDeep() const {
    if (parent == nullptr)
        return 1;
    return 1 + parent->getDeep();
}

void Branch::createForest() {
    const short DEEP = getDeep();

    if (DEEP > 3) return;

    static char character = 65;

    const int BRANCHES_COUNT = (DEEP == 1) ? getTreesAmount() 
                            : (DEEP == 2) ? getBigBranchesPerTree() 
                            : getAvarageBranchesPerBigBranch();

    for (int i = 0; i < BRANCHES_COUNT; i++) {
        Branch* newBranch = new Branch((DEEP == 1) ? 'N' : character % 128);
        character++;
        newBranch->parent = this;
        children.push_back(newBranch);
        newBranch->createForest();
    }
}

void Branch::printIt() const {
    const short DEEP = getDeep();

    std::string tabs = (DEEP == 4) ? "\t\t\t - (Avarage Branch)" : (DEEP == 3) ? "\t\t - (Big Branch)" 
                        : (DEEP == 2) ? "\t - (Three)" : " - (Forest)";

    bool printed = false;

    if (children.empty()) {
        std::cout << tabs << elfName << std::endl;
        return;
    }

    for (const auto& child : children) {
        if (!printed) {
            std::cout << tabs << elfName << std::endl;
            printed = true;
        }
        child->printIt();
    }
}

void Branch::printNeighbors(const char inElfName) const {
    if (inElfName != elfName)
        std::cout << "Elf " << elfName << std::endl;

    for (const auto& child : children) {
        getDeep();
        child->printNeighbors(inElfName);
    }
}

bool Branch::find(char inElfName) const {
    if (elfName == inElfName) {
        if (getDeep() == 3)
            printNeighbors(inElfName);
        return true;
    }

    for (const auto& child : children) {
        if (child->find(inElfName)) {
            if (getDeep() == 3)
                printNeighbors(inElfName);
            return true;
        }
    }

    return false;
}

Branch::Branch(char name) : elfName(name), parent(nullptr) {}

Branch::~Branch() {
    for (Branch* child : children)
        delete child;
}

void Branch::generate() {
    if (this->parent != nullptr) {
        std::cerr << "Error: This function can only be used with main object!" << std::endl;
        return;
    }
    createForest();
}

void Branch::display() const {
    if (parent != nullptr) {
        std::cerr << "Error: This function can only be used with main object!" << std::endl;
        return;
    }
    printIt();
}

bool Branch::neighborhood(char inElfName) const {
    if (parent != nullptr) {
        std::cerr << "Error: This function can only be used with main object!" << std::endl;
        return false;
    }
    return find(inElfName);
}