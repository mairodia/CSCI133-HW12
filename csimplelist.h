// ============================================================================
// File: csimplelist.h (Spring 2018)
// ============================================================================
// Programmer: Jennifer King
// Date: 5/3/2018
// Project: CHeap
// Professor: Scott Edwards
// Class: CSCI 133F | TR 9:30am
// Description:
// Header file for the CSimpleList class.
// ============================================================================

#ifndef CSIMPLE_LIST_HEADER
#define CSIMPLE_LIST_HEADER

// enumerated list for list exceptions
enum    ListExType { L_FULL
                   , L_EMPTY
                   , L_ERROR
                   , L_SUCCESS
                   , L_INVALID_INDEX
                   , L_DUPLICATE
                   , L_NOT_EXIST
                   };


// exception class for CSimpleList
class   CListEx
{
public:
    CListEx(ListExType  exType) : m_exType(exType) {}
    ListExType  GetExType() const { return  m_exType; }

private:
    ListExType      m_exType;
};


// constants
const   int     DEFAULT_NUM_ITEMS = 5;
const   int     MOVE_TOWARDS_BACK = 0;
const   int     MOVE_TOWARDS_FRONT  = 1;


// class declaration
template    <typename  ListType>
class   CSimpleList
{
public:
    // constructors and destructors
    CSimpleList(int  numItems = DEFAULT_NUM_ITEMS);
    CSimpleList(const CSimpleList  &other);
    virtual ~CSimpleList()  { DestroyList(); }

    // member functions
    void    DestroyList();
    void    GetItem(int  index, ListType  &item) const;
    int     GetNumItems() const { return m_numItems; }
    void    Insert(int  index, const ListType  &item);
    bool    IsEmpty() const { return (0 == m_numItems); }
    bool    IsFull() const { return (m_currMax == m_numItems); }
    void    Remove(int  index);
    void    SetListSize(int numItems);

    // overloaded operators
    CSimpleList<ListType>&  operator=(const CSimpleList  &rhs);
    ListType&               operator[](int  index);

private:
    // data members
    int             m_currMax;
    int             m_numItems;
    ListType        *m_items;

    // member functions
    int             CopyList(const CSimpleList  &other);
    int             MoveItems(int  index, int  direction);
};

#include    "csimplelist.cpp"

#endif  // CSIMPLE_LIST_HEADER
