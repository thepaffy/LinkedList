/*
 * LinkedList.cpp
 *
 *  Created on: 23 Oct 2015
 *      Author: thepaffy
 */

#include <LinkedList.h>

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
void LinkedList<T>::prepend(T t)
{
    Link *tLink = new Link(mHead, mHead->mNext, t);
    mHead->mNext->mPre = tLink;
    mHead->mNext = tLink;
    mSize++;
}

template<typename T>
void LinkedList<T>::append(T t)
{
    Link *tLink = new Link(mEnd->mPre, mEnd, t);
    mEnd->mPre->mNext = tLink;
    mEnd->mPre = tLink;
    mSize++;
}

template<typename T>
void LinkedList<T>::insert(unsigned int xIndex, T t)
{
    if (xIndex > mSize)     // inserting can be also appending
        throw std::range_error("Index out of range!");

    Link *tLinkOnIndex = linkToIndex(xIndex);
    Link *tLink = new Link(tLinkOnIndex->mPre, tLinkOnIndex, t);
    tLinkOnIndex->mPre->mNext = tLink;
    tLinkOnIndex->mPre = tLink;
    mSize++;
}

template<typename T>
T LinkedList<T>::at(unsigned int xIndex)
{
    if (xIndex >= mSize)
        throw std::range_error("Index out of range!");

    Link *tLinkOnIndex = linkToIndex(xIndex);
    return tLinkOnIndex->mValue;
}

template<typename T>
void LinkedList<T>::assign(unsigned int xIndex, T t)
{
    if (xIndex >= mSize)
        throw std::range_error("Index out of range!");

    Link *tLinkOnIndex = linkToIndex(xIndex);
    tLinkOnIndex->mValue = t;
}

template<typename T>
T LinkedList<T>::remove(unsigned int xIndex)
{
    if (xIndex >= mSize)
        throw std::range_error("Index out of range!");

    Link *tLinkOnIndex = linkToIndex(xIndex);
    tLinkOnIndex->mPre->mNext = tLinkOnIndex->mNext;
    tLinkOnIndex->mNext->mPre = tLinkOnIndex->mPre;
    T tValue = tLinkOnIndex->mValue;
    delete tLinkOnIndex;
    return tValue;
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
typename LinkedList<T>::Link *LinkedList<T>::linkToIndex(unsigned int xIndex)
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

// bool
//template class LinkedList<bool> ;
//
//// characters & strings
//template class LinkedList<char> ;
//template class LinkedList<char *> ;
//template class LinkedList<const char *> ;
//
//// integers
//template class LinkedList<signed char> ;
//template class LinkedList<unsigned char> ;
//template class LinkedList<short> ;
//template class LinkedList<unsigned short> ;
template class LinkedList<int> ;
//template class LinkedList<unsigned int> ;
//template class LinkedList<long> ;
//template class LinkedList<unsigned long> ;
//template class LinkedList<long long> ;
//template class LinkedList<unsigned long long> ;
//
//// floats
//template class LinkedList<float> ;
//template class LinkedList<double> ;
//template class LinkedList<long double> ;

