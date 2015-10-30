#include <iostream>
#include "stack.hpp"
#include "queue.hpp"
#include "LinkedList.hpp"

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

    /*
     Stack<int> tIntStack;
     tIntStack.push(2);
     tIntStack.push(5);
     tIntStack.push(3);
     std::cout << "Stack size: " << tIntStack.size() << "\n";
     Stack<int> tSecondStack(tIntStack);

     while (!tIntStack.empty())
     {
     std::cout << "Top: " << tIntStack.top() << "\n";
     tIntStack.pop();
     std::cout << "Stack size: " << tIntStack.size() << "\n";
     }

     while (!tSecondStack.empty())
     {
     std::cout << "Top: " << tSecondStack.top() << "\n";
     tSecondStack.pop();
     std::cout << "Stack size: " << tSecondStack.size() << "\n";
     }
     */
    /*
     Queue<int> tIntQueue;
     tIntQueue.push(2);
     tIntQueue.push(5);
     tIntQueue.push(3);
     std::cout << "Queue size: " << tIntQueue.size() << "\n";
     Queue<int> tSecondQueue(tIntQueue);

     while (!tIntQueue.empty())
     {
     std::cout << "Front: " << tIntQueue.front() << "\n";
     std::cout << "Back: " << tIntQueue.back() << "\n";
     tIntQueue.pop();
     std::cout << "Queue size: " << tIntQueue.size() << "\n";
     }
     */
    return 0;
}
