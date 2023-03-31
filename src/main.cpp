#include <iostream>

#include "List.hpp"

int main() {
    List<int> l1 = List<int>();
    l1.append(1);
    l1.append(2);
    l1.append(3);
    std::cout << "l1" << std::endl;
    l1.print();

    List<int> l2 = std::move(l1);
    std::cout << "l1" << std::endl;
    l1.print();
    std::cout << "l2" << std::endl;
    l2.print();

    return 0;
}