// ======================================================================================
// File: cheap.cpp (Spring 2018)
// ======================================================================================
// Programmer: Jennifer King
// Project: CHeap
// Date: 5/3/2018
// Professor: Scott Edwards
// Class: CSCI 223F | TR 4:30PM
// ======================================================================================

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;


// == DestroyHeap =======================================================================
// Destroys the heap.
//
// Input:
//              N/A
//
// Output:
//              void
// ======================================================================================
template <typename HeapType>
void CHeap<HeapType>::DestroyHeap()
{
    CSimpleList<HeapType>::DestroyList();
} // end of DestroyList

// == Insert ============================================================================
// Inserts an item into the tree.
//
// Input:
//              item    --      the item to be added to the tree
//
// Output:
//              void
// ======================================================================================
template <typename HeapType>
void CHeap<HeapType>::Insert(const HeapType &item)
{
    int index = CSimpleList<HeapType>::GetNumItems() + 1;
    HeapType insert;
    insert = item;

    try
    {
        CSimpleList<HeapType>::Insert(index, insert);
    }
    catch(const CListEx &listEx)
    {
        switch(listEx.GetExType())
        {
            case L_EMPTY:
                throw CHeapEx(H_EMPTY);
                break;
            case L_INVALID_INDEX:
                throw CHeapEx(H_ERROR);
                break;
            default:
                break;
        }
    }

    HeapType newEntry;
    HeapType upperEntry;
    int parent;

    bool bContinueLoop = true;

    do
    {
        parent = (index - 1)/2;
        CSimpleList<HeapType>::GetItem(index, newEntry);
        CSimpleList<HeapType>::GetItem(parent, upperEntry);

        if(newEntry > upperEntry)
        {
            swap(newEntry, upperEntry);
            index = parent;
        }
        else
        {
            bContinueLoop == false;
        }
    }while(bContinueLoop == true);

} // end of Insert

// == PeekTop ===========================================================================
// Allows the user to see the root of the tree.
//
// Input:
//              item    --      item to be set to root value
//
// Output:
//              void
// ======================================================================================
template <typename HeapType>
void CHeap<HeapType>::PeekTop(HeapType &item) const
{
    CSimpleList<HeapType>::GetItem(0, item);
} // end of PeekTop

// == Remove ============================================================================
// Removes an item from the tree.
//
// Input:
//              item    --      item to be removed
//
// Output:
//              void
// ======================================================================================
template <typename HeapType>
void CHeap<HeapType>::Remove(HeapType &item)
{
    int numItems = CSimpleList<HeapType>::GetNumItems();
    int index = 0;

    HeapType object;
    bool bContinueLoop = true;

    for(; index < numItems || bContinueLoop == false; index++)
    {
        CSimpleList<HeapType>::GetItem(index, object);
        if(object == item)
        {
            bContinueLoop = false;
        }
    }
    if(bContinueLoop == true)
    {
        throw CHeapEx(H_ERROR);
    }

    try
    {
        CSimpleList<HeapType>::Remove(index);
    }
    catch(const CListEx &listEx)
    {
        switch(listEx.GetExType())
        {
            case L_EMPTY:
                throw CHeapEx(H_EMPTY);
                break;
            case L_INVALID_INDEX:
                throw CHeapEx(H_ERROR);
                break;
            default:
                break;
        }
    }

    RebuildHeap(index);

} // end of Remove

// == RebuildHeap =======================================================================
// Rebuilds the tree after an item is removed.
//
// Input:
//              rootIndex       --      the index of the root of the tree
//
// Output:
//              void
// ======================================================================================
template <typename HeapType>
void CHeap<HeapType>::RebuildHeap(int rootIndex)
{
    int index = (CSimpleList<HeapType>::GetNumItems()) - 1;

    HeapType root;
    HeapType last;

    CSimpleList<HeapType>::GetItem(index, last);
    CSimpleList<HeapType>::GetItem(rootIndex, root);

    swap(root, last);
    Remove(last);
    index = rootIndex;

    int left, right;
    HeapType    L, R, max;

    bool bContinueLoop = true;

    do
    {
        left = (2*index) + 1;
        right = (2*index) + 2;

        CSimpleList<HeapType>::GetItem(left, L);
        CSimpleList<HeapType>::GetItem(right, R);
        CSimpleList<HeapType>::GetItem(index, root);

        if(L > R)
        {
            max = L;
        }
        else
        {
            max = R;
        }

        if(root < max)
        {
            swap(root, max);
            if(max == R)
            {
                index = right;
            }
            else
            {
                index = left;
            }
        }
        else
        {
            bContinueLoop = false;
        }
    }while(bContinueLoop == true);
} // end of RebuildHeap

