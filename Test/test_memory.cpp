#include <iostream>
#include "Vector.h"

int main() {
    {
        Vector<int> v1;
        for(int i=0; i<100; i++) v1.PushBack(i);
        
        Vector<int> v2 = v1; // Test Copy
        Vector<int> v3 = std::move(v1); // Test Move
    } 
    std::cout << "Memory test scope finished. Check Valgrind for leaks!" << std::endl;
    return 0;
}
