// =======================================================================
// File: csimplelist.cpp (Spring 2018)
// =======================================================================
// Programmer: Jennifer King
// Date: 5/3/2018
// Project: CHeap
// Professor: Scott Edwards
// Class: CSCI 133F | TR 9:30am
// Description:
//      Implementation for the CSimpleList class.
// =======================================================================

#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;
#include "csimplelist.h"

// == Copy Ctor ==========================================================
//
// =======================================================================
CSimpleList::CSimpleList(const CSimpleList &other)
{
    m_items = NULL;
    m_numItems = m_currMax = 0;
    CopyList(other);
} //end copy ctor

// == DestroyList ========================================================
// Destroys the current list.
//
// Input:
//              N/A
//
// Output:
//              void
// =======================================================================
void CSimpleList::DestroyList()
{
    m_currMax = 0;
    m_numItems = 0;
    delete []m_items;
} //end DestroyList

// == GetItem ============================================================
// Gets the item at the current index.
//
// Input:
//              index -- index of the array member to retrieve
//              item  -- address of the item to set = to the array member
//
// Output:
//              void
// =======================================================================
void CSimpleList::GetItem(int index, ListType &item) const
{
    if(IsEmpty())
    {
        throw CListEx(L_EMPTY);
    }
    if((index < 0) || (index > (m_numItems - 1)))
    {
        throw CListEx(L_INVALID_INDEX);
    }
    item = m_items[index];

} //end GetItem

// == Insert =============================================================
// Inserts an item at the stated index
//
// Input:
//              index -- index where item is inserted
//              item  -- item to be inserted
//
// Output:
//              void
// =======================================================================
void CSimpleList::Insert(int index, const ListType &item)
{
    if(IsFull())
    {
        SetListSize(m_currMax + DEFAULT_NUM_ITEMS);
    }
    if(index < 0) || (index > m_numItems))
    {
        throw CListEx(L_INVALID_INDEX);
    }
    if(index < m_numItems)
    {
        MoveItems(index, MOVE_TO_BACK);
    }
    m_items[index] = item;
    ++ m_numItems;
} //end Insert

// == Remove =============================================================
// Removes the item at the stated index
//
// Input:
//              index -- index where item is removed
//
// Output:
//              void
// =======================================================================
void CSimpleList::Remove(int index)
{
    if(isEmpty())
    {
        throw CListEx(L_EMPTY);
    }
    if((index < 0) || (index > m_currMax))
    {
        throw CListEx(L_INVALID_INDEX);
    }
    if(index < (m_numItems -1))
    {
        MoveItems(index, MOVE_TO_FRONT);
    }
    --m_numItems;
} //end Remove

// == SetListSize ========================================================
// Sets the current max equal to the number of items.
//
// Input:
//              numItems -- number of items in the list
//
// Output:
//              void
// =======================================================================
void CSimpleList::SetListSize(int numItems)
{
    m_currMax = numItems;
} //end SetListSize

// == CopyList ===========================================================
// Copies the list.
//
// Input:
//              &other -- list to be copied
//
// Output:
//              index  -- number of items copied
// =======================================================================
int     CSimpleList::CopyList(const CSimpleList &other)
{
    int index;
    if(this != &other)
    {
        DestroyList();
        SetListSize(other.m_currMax);
        m_numItems = other.m_numItems;

        for(index = 0; index < m_numItems; ++index)
        {
            m_items[index] = other.m_items[index];
        }
    }
    return index;
} //end CopyList

// == MoveItems ==========================================================
// Moves an item in the list to the front or back
//
// Input:
//              index     -- the index of the item to be moved
//              direction -- direction in which to move the item
//
// Output:
//              numItemsMoved -- the # of items moved
// =======================================================================
int CSimpleList::MoveItems(int index, int direction)
{
    int destIndex;
    int update;
    int sourceIndex;
    int numItemsMoved = 0;

    //initialize the source and destination index values
    if(MOVE_TO_BACK == direction)
    {
        sourceIndex = m_numItems - 1;
        destIndex = m_numItemsl
        update = -1; // move from higher to lower addresses
    }

    else //MOVE_TO_FRONT
    {
        sourceIndex = index + 1;
        destIndex = index;
        update = 1;
    }

    bool bContinueLoop = true;

    do
    {
        m_items[destIndex = m_items[sourceIndex];
        destIndex += update;
        sourceIndex += update;
        ++ numItemsMoved;

        if(MOVE_TO_BACK == direction)
        {
            if((sourceIndex < index) || (destIndex < 1))
            {
                bContinueLoop = false;
            }
        }
        else //MOVE_TO_FRONT
        {
            if(sourceIndex >= m_numItems
            {
                bContinueLoop - false;
            }
        }
    }while(true == bContinueLoop);

    return numItemsMoved;
} //end MoveItems

