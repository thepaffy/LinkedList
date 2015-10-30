# Linked lists:
Linked list examples for teaching lessons.

## Class LinkedList:
The LinkedList class is a, java typical, doubly linked list, with index based access. It's not thought for production!
### Operations:
__void prepend(const T &t);__
Prepends an element with a copy of value _t_ to the list.

__void append(const T &t);__
Appends an element with a copy of value _t_ to the list.

__void insert(unsigned int xIndex, const T &t);__
Inserts an element with a copy of value _t_ on index _xIndex_.

__T &at(unsigned int xIndex);__
Returns a reference of the elements value, on index _xIndex_.

__const T &at(unsigned int xIndex) const;__
Returns a constant reference of the elements value, on index _xIndex_.

__void assign(unsigned int xIndex, const T &t);__
Assigns a copy of value _t_ to the elements value, on index _xIndex_.

__void remove(unsigned int xIndex);__
Remove the element on index _xIndex_.

__unsigned int size() const;__
Returns the number of elements in the list.

## Class Stack:
The Stack class is a lightwight stack implementation. The interface is insp. by the stl stack.
### Operations:
__void push(const T &xData);__
Inserts a new element at the top of the stack with a copy of _xData_.

__void pop();__
Removes the element on top of the stack.

__T &top();__
Returns a reference to the top element in the stack.

__const T &top() const;__
Returns a const reference to the top element in the stack.

__bool empty() const;__
Returns true if the stack are empty.

__unsigned int size() const;__
Returns the number of elements in the stack.

## Class Queue:
The Queue Class is a lightwight queue implementation. The interface is insp. by the stl queue.
### Operations:
__void push(const T &xData);__
Inserts a new element at the end of the queue with a copy of _xData_.

__void pop();__
Removes the element on the begin of the queue.

__T &front();__
Returns a reference to the first element in the queue.

__const T &front() const;__
Returns a const reference to the first element in the queue.

__T &back();__
Returns a reference to the last element in the queue.

__const T &back() const;__
Returns a const reference to the last element in the queue.

__bool empty() const;__
Returns true if the queue are empty.

__unsigned int size() const;__
Returns the number of elements in the queue.

