#ifndef BRANCH_H
#define BRANCH_H

#include <vector>
#include <iostream>

class Branch {
private:
    Branch* parent;
    std::vector<Branch*> children;
    char elfName;

    short getTreesAmount() const;
    short getBigBranchesPerTree() const;
    short getAvarageBranchesPerBigBranch() const;
    short getDeep() const;
    void createForest();
    void printIt() const;
    void printNeighbors(const char inElfName) const;
    bool find(char inElfName) const;

public:
    Branch(char name = 'N');
    ~Branch();
    void generate();
    void display() const;
    bool neighborhood(char inElfName) const;
};

#endif // BRANCH_H