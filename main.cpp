// ============================================================================
// File: main.cpp (Spring 2018)
// ============================================================================
// This is a test driver for the CHeap class.
// ============================================================================
// Programmer: Jennifer King
// Project: CHeap
// Date: 5/3/2018
// Programmer: Scott Edwards
// Class: CSCI 223F | TR 9:30PM
// Output:
//      Remove some items:
//      intVal = 20
//      intVal = 20
//      intVal = 12
//      intVal = 12
//      intVal = 7
//      intVal = 7
//      intVal = 5
//      intVal = 5
//      intVal = 4
//      intVal = 4
//      Error removing heap value...
//      Error removing heap value...
//      Error removing heap value...
// ============================================================================

#include    <iostream>
#include    <cstdlib>
using namespace std;
#include    "cheap.h"


// ==== main ==================================================================
//
// ============================================================================

int     main()
{
    CHeap<int>      myHeap;
    int             heapInts[] = { 5, 20, 4, 12, 7, 5, 20, 4, 12, 7 };
    unsigned int    index;
    int             intVal;

    // insert some values into the heap
    for (index = 0; index < (sizeof(heapInts) / sizeof(*heapInts)); ++index)
        {
        try {
            myHeap.Insert(heapInts[index]);
            }
        catch (CHeapEx&)
            {
            cerr << "Error inserting " << heapInts[index] << endl;
            exit(EXIT_FAILURE);
            }
        }

    // try removing some items (we loop a few extra times here to try out the
    // exception handling)
    cout << "Remove some items: " << endl;
    for (index = 0; index < (sizeof(heapInts) / sizeof(*heapInts)) + 3; ++index)
        {
        try {
            myHeap.Remove(intVal);
            cout << "intVal = " << intVal << endl;
            }
        catch (CHeapEx&)
            {
            cerr << "Error removing heap value..." << endl;
            }
        }

    return (EXIT_SUCCESS);

}  // end of "main"
