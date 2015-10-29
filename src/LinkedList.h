/*
 * LinkedList.h
 *
 *  Created on: 23 Oct 2015
 *      Author: thepaffy
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <stdexcept>

template<typename T>
class LinkedList
{
    class Link
    {
    public:
        Link(Link *xPre, Link *xNext, const T& xValue)
                : mPre(xPre), mNext(xNext), mValue(xValue)
        {
        }
        Link *mPre;
        Link *mNext;
        T mValue;
    };
public:
    explicit LinkedList();
    LinkedList(const LinkedList<T> &xOther);
    virtual ~LinkedList();

    inline unsigned int size() const
    {
        return mSize;
    }

    void prepend(const T &t);
    void append(const T &t);
    void insert(unsigned int xIndex, const T &t);
    T at(unsigned int xIndex);
    void assign(unsigned int xIndex, const T &t);
    T remove(unsigned int xIndex);

private:
    void init();
    Link *linkToIndex(unsigned int xIndex);

    unsigned int mSize;
    Link *mHead;
    Link *mEnd;
};

#endif /* LINKEDLIST_H_ */
