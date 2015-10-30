/*
 * queue.hpp
 *
 *  Created on: 30 Oct 2015
 *      Author: thepaffy
 */

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <cassert>

template<typename T>
class Queue
{
    struct BaseNode
    {
        BaseNode()
                : mNext(nullptr)
        {
        }
        BaseNode *mNext;
    };

    struct Node: BaseNode
    {
        Node(const T &xData)
                : BaseNode(), mData(xData)
        {
        }
        T mData;
    };
public:
    explicit Queue();
    Queue(const Queue &xOther);
    ~Queue();

    void push(const T &xData);
    void pop();
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
    bool empty() const;
    unsigned int size() const;
private:
    BaseNode *mBegin;
    BaseNode *mEnd;
    unsigned int mSize;
};

/*
 * Impl
 */

template<typename T>
Queue<T>::Queue()
{
    mBegin = new BaseNode;
    mEnd = mBegin;
    mSize = 0;
}

template<typename T>
Queue<T>::Queue(const Queue &xOther)
{
    mBegin = new BaseNode;
    mEnd = mBegin;
    mSize = xOther.mSize;

    BaseNode **tIter = &(mBegin->mNext);
    BaseNode *tOtherIter = xOther.mBegin->mNext;
    while (tOtherIter != nullptr)
    {
        *tIter = new Node(((Node *) tOtherIter)->mData);
        mEnd = *tIter;
        tOtherIter = tOtherIter->mNext;
        tIter = &((*tIter)->mNext);
    }
}

template<typename T>
Queue<T>::~Queue()
{
    while (!empty())
    {
        pop();
    }
}

template<typename T>
void Queue<T>::push(const T &xData)
{
    mEnd->mNext = new Node(xData);
    mEnd = mEnd->mNext;
    mSize++;
}

template<typename T>
void Queue<T>::pop()
{
    assert(mBegin->mNext != nullptr);
    Node *tTemp = static_cast<Node *>(mBegin->mNext);
    mBegin->mNext = mBegin->mNext->mNext;
    delete tTemp;
    mSize--;
}

template<typename T>
T &Queue<T>::front()
{
    assert(mBegin->mNext != nullptr);
    Node *tTemp = static_cast<Node *>(mBegin->mNext);
    return tTemp->mData;
}

template<typename T>
const T &Queue<T>::front() const
{
    assert(mBegin->mNext != nullptr);
    Node *tTemp = static_cast<Node *>(mBegin->mNext);
    return tTemp->mData;
}

template<typename T>
T &Queue<T>::back()
{
    assert(mBegin->mNext != nullptr);
    Node *tTemp = static_cast<Node *>(mEnd);
    return tTemp->mData;
}

template<typename T>
const T &Queue<T>::back() const
{
    assert(mBegin->mNext != nullptr);
    Node *tTemp = static_cast<Node *>(mEnd);
    return tTemp->mData;
}

template<typename T>
bool Queue<T>::empty() const
{
    return mBegin->mNext == nullptr;
}

template<typename T>
unsigned int Queue<T>::size() const
{
    return mSize;
}

#endif /* QUEUE_HPP_ */
