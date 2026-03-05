#include <iostream>
#include "Vector.h"

int main()
{
    Vector<int> vec;
    vec.PushBack(1);
    vec.PushBack(2);
    vec.PushBack(3);

    std::cout << "Vector contents: ";
    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\nSize: " << vec.Size() << std::endl;

    return 0;
}
