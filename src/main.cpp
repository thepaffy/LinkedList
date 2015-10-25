#include <iostream>
#include "LinkedList.h"

int main(int argc, char **argv)
{
    LinkedList<int> tLinkedList;

    tLinkedList.append(15);
    tLinkedList.append(2);
    tLinkedList.insert(1, 32);
    tLinkedList.prepend(255);
    tLinkedList.insert(tLinkedList.size(), 6);

    for (unsigned int i = 0; i < tLinkedList.size(); i++)
    {
        std::cout << i << ": " << tLinkedList.at(i) << "\n";
    }

    return 0;
}
