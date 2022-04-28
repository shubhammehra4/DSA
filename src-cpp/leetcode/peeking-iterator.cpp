#include <bits/stdc++.h>
using namespace std;
/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 */
class Iterator
{
    struct Data;
    Data *data;

public:
    Iterator(const vector<int> &nums);
    Iterator(const Iterator &iter);
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};

// copy-constructor
class PeekingIterator : public Iterator
{
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {}

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        // as Interator has a copy constructor
        // we create a copy and advance on the copy to get val
        return Iterator(*this).next();
    }

    // next() & hasNext() are the same as base class
};

// stroring the next value
class PeekingIterator : public Iterator
{
private:
    int nextVal;
    bool hasNextVal;

public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        hasNextVal = Iterator::hasNext();
        if (hasNextVal)
            nextVal = Iterator::next();
    }

    int peek()
    {
        return nextVal;
    }

    // @Override
    int next()
    {
        int t = nextVal;
        hasNextVal = Iterator::hasNext();
        if (hasNextVal)
            nextVal = Iterator::next();

        return t;
    }

    // @Override
    bool hasNext() const
    {
        return hasNextVal;
    }
};