/*
 * LinkedList.h
 *
 *  Created on: 23 Oct 2015
 *      Author: thepaffy
 */

#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <cassert>

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
    ~LinkedList();

    void prepend(const T &t);
    void append(const T &t);
    void insert(unsigned int xIndex, const T &t);
    T &at(unsigned int xIndex);
    const T &at(unsigned int xIndex) const;
    void assign(unsigned int xIndex, const T &t);
    void remove(unsigned int xIndex);
    unsigned int size() const;

private:
    void init();
    Link *linkToIndex(unsigned int xIndex) const;

    unsigned int mSize;
    Link *mHead;
    Link *mEnd;
};

/*
 * Impl
 */

template<typename T>
LinkedList<T>::LinkedList()
{
    init();
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &xOther)
{
    init();

    Link *tLink = xOther.mHead->mNext;  // set link to the first element
    Link *tCopy = nullptr;
    while (tLink != xOther.mEnd)
    {
        // create the copy and migrate it to the list
        tCopy = new Link(mEnd->mPre, mEnd, tLink->mValue);
        mEnd->mPre->mNext = tCopy;
        mEnd->mPre = tCopy;
        mSize++;                        // increment the list size

        tLink = tLink->mNext;           // increment link
    }
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    Link *tLink = mEnd->mPre;
    while (tLink != mHead)
    {
        tLink = tLink->mPre;         // decrement link
        delete tLink->mNext;         // delete the element after current element
    }

    delete mEnd;
    delete mHead;
}

template<typename T>
void LinkedList<T>::prepend(const T &t)
{
    Link *tLink = new Link(mHead, mHead->mNext, t);
    mHead->mNext->mPre = tLink;
    mHead->mNext = tLink;
    mSize++;
}

template<typename T>
void LinkedList<T>::append(const T &t)
{
    Link *tLink = new Link(mEnd->mPre, mEnd, t);
    mEnd->mPre->mNext = tLink;
    mEnd->mPre = tLink;
    mSize++;
}

template<typename T>
void LinkedList<T>::insert(unsigned int xIndex, const T &t)
{
    assert(xIndex <= mSize);     // inserting can be also appending

    Link *tLinkOnIndex = linkToIndex(xIndex);
    Link *tLink = new Link(tLinkOnIndex->mPre, tLinkOnIndex, t);
    tLinkOnIndex->mPre->mNext = tLink;
    tLinkOnIndex->mPre = tLink;
    mSize++;
}

template<typename T>
T &LinkedList<T>::at(unsigned int xIndex)
{
    assert(xIndex < mSize);

    Link *tLinkOnIndex = linkToIndex(xIndex);
    return tLinkOnIndex->mValue;
}

template<typename T>
const T &LinkedList<T>::at(unsigned int xIndex) const
{
    assert(xIndex < mSize);

    Link *tLinkOnIndex = linkToIndex(xIndex);
    return tLinkOnIndex->mValue;
}

template<typename T>
void LinkedList<T>::assign(unsigned int xIndex, const T &t)
{
    assert(xIndex < mSize);

    Link *tLinkOnIndex = linkToIndex(xIndex);
    tLinkOnIndex->mValue = t;
}

template<typename T>
void LinkedList<T>::remove(unsigned int xIndex)
{
    assert(xIndex < mSize);

    Link *tLinkOnIndex = linkToIndex(xIndex);
    tLinkOnIndex->mPre->mNext = tLinkOnIndex->mNext;
    tLinkOnIndex->mNext->mPre = tLinkOnIndex->mPre;
    delete tLinkOnIndex;
}

template<typename T>
unsigned int LinkedList<T>::size() const
{
    return mSize;
}

template<typename T>
void LinkedList<T>::init()
{
    mHead = new Link(nullptr, nullptr, T());
    mEnd = new Link(nullptr, nullptr, T());
    mHead->mNext = mEnd;
    mEnd->mPre = mHead;
    mSize = 0;
}

template<typename T>
typename LinkedList<T>::Link *LinkedList<T>::linkToIndex(
        unsigned int xIndex) const
{
    Link *tWorkLink = mHead->mNext;
    unsigned int tCurrentIndex = 0;

    // Move work link to destination
    while (tCurrentIndex < xIndex)
    {
        tWorkLink = tWorkLink->mNext;
        tCurrentIndex++;
    }

    return tWorkLink;
}

#endif /* LINKEDLIST_HPP_ */
