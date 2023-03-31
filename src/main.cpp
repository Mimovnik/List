#include <iostream>

#include "List.hpp"

int main() {
    List<int> list;
    for(int i = 0; i < 100; i++){
        list.append(i);
    }
    list.print();
    return 0;
}