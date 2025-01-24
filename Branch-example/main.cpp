#include "Branch.h"

int main() {
    Branch* test = new Branch;

    test->generate();
    test->display();

    char elfName;
    std::cout << "Input the name of the elf you are seeking for: " << std::endl;
    std::cin >> elfName;

    if (elfName == 'N') {
        return 1;
    }

    if (!test->neighborhood(elfName)) {
        std::cout << "Elf " << elfName << " not found!" << std::endl;
    }

    delete test;

    int a;
    std::cin >> a;

    return 0;
}