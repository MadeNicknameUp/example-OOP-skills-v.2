#include "Branch.h"

int main() {
    Branch* test = new Branch; // Create a new Branch object

    test->generate(); // Generate the forest structure
    test->display(); // Display the forest structure

    char elfName;
    std::cout << "Input the name of the elf you are seeking for: " << std::endl;
    std::cin >> elfName; // Get the name of the elf to search for

    if (elfName == 'N') {
        return 1; // Exit if the input is 'N'
    }

    if (!test->neighborhood(elfName)) {
        std::cout << "Elf " << elfName << " not found!" << std::endl; // Print if the elf is not found
    }

    delete test; // Clean up the allocated memory

    int a;
    std::cin >> a; // Wait for user input before exiting

    return 0;
}