/*
 * stack.hpp
 *
 *  Created on: 30 Oct 2015
 *      Author: thepaffy
 */

#ifndef STACK_HPP_
#define STACK_HPP_

#include <cassert>

template<typename T>
class Stack
{
    struct Node
    {
        Node(const T &xData, Node *xPrev)
                : mData(xData), mPrev(xPrev)
        {
        }
        T mData;
        Node *mPrev;
    };
public:
    explicit Stack();
    Stack(const Stack<T> &xOther);
    ~Stack();

    void push(const T &xData);
    void pop();
    T &top();
    const T &top() const;
    bool empty() const;
    unsigned int size() const;

private:
    Node *mAnchor;
    unsigned int mSize;
};

/*
 * Impl
 */

template<typename T>
Stack<T>::Stack()
{
    mAnchor = nullptr;
    mSize = 0;
}

template<typename T>
Stack<T>::Stack(const Stack<T> &xOther)
{
    mAnchor = nullptr;
    mSize = xOther.mSize;

    Node **tItr = &mAnchor;
    Node *tOtherItr = xOther.mAnchor;
    while (tOtherItr != nullptr)
    {
        *tItr = new Node(tOtherItr->mData, nullptr);
        tOtherItr = tOtherItr->mPrev;
        tItr = &((*tItr)->mPrev);
    }
}

template<typename T>
Stack<T>::~Stack()
{
    while (!empty())
    {
        pop();
    }
}

template<typename T>
void Stack<T>::push(const T &xData)
{
    mAnchor = new Node(xData, mAnchor);
    mSize++;
}

template<typename T>
void Stack<T>::pop()
{
    assert(mAnchor != nullptr);
    Node *tTemp = mAnchor;
    mAnchor = mAnchor->mPrev;
    delete tTemp;
    mSize--;
}

template<typename T>
T &Stack<T>::top()
{
    assert(mAnchor != nullptr);
    return mAnchor->mData;
}

template<typename T>
const T &Stack<T>::top() const
{
    assert(mAnchor != nullptr);
    return mAnchor->mData;
}

template<typename T>
bool Stack<T>::empty() const
{
    return mAnchor == nullptr;
}

template<typename T>
unsigned int Stack<T>::size() const
{
    return mSize;
}

#endif /* STACK_HPP_ */
