// ============================================================================
// File: cheap.h (Spring 2018)
// ============================================================================
// Programmer: Jennifer King
// Project: CHeap
// Date: 5/3/2018
// Professor: Scott Edwards
// Header file for the CHeap class.
// ============================================================================

#ifndef CHEAP_HEADER
#define CHEAP_HEADER

#include "csimplelist.h"

// enumerated list for heap exceptions
enum    HeapExType { H_FULL
                   , H_EMPTY
                   , H_ERROR
                   , H_SUCCESS
                   };


// constants
const   int     DEFAULT_HEAP_ITEMS = DEFAULT_NUM_ITEMS;
enum    { MAX_HEAP, MIN_HEAP };


// exception class for CHeap class
class  CHeapEx
{
public:
    CHeapEx(HeapExType  exType) : m_exType(exType) {}
    HeapExType  GetExType() const { return  m_exType; }

private:
    HeapExType      m_exType;
};


// class declaration
template    <typename  HeapType>
class   CHeap : private CSimpleList<HeapType>
{
public:
    // constructors and destructor
    CHeap(HeapType  heapType = MAX_HEAP, int  numItems = DEFAULT_HEAP_ITEMS)
                        : CSimpleList<HeapType>(numItems)
                        , m_heapType(heapType) {}
    virtual ~CHeap() { DestroyHeap(); }

    // member functions
    void    DestroyHeap();
    void    Insert(const HeapType  &item);
    void    PeekTop(HeapType  &item) const;
    void    Remove(HeapType  &item);

private:
    // data members
    HeapType    m_heapType;

    // member functions
    void    RebuildHeap(int  rootIndex);
};

#include "cheap.cpp"
#endif  // CHEAP_HEADER
