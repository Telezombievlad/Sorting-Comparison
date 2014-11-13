#include "TXLib.h"
#include "classes.h"

//----------------------------------------------------------------------------
//{ Sorting algorithms
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//{ Bubble sorting
//----------------------------------------------------------------------------

Counters bubbleSort (int array[], int arraySize)
{

    assert (array);
    assert (0 <= arraySize);
    if (arraySize <= 1) return {0, 0, 0};

    bool isSortingNeeded = true;
    int  swapCount       =    0;
    int  compareCount    =    0;
    LARGE_INTEGER start, finish;
    QueryPerformanceCounter (&start);

    while (isSortingNeeded)
    {
        isSortingNeeded = false;

        for (int i = 0; i < arraySize - 1; i++)
        {
            assert (0 <= i && i < arraySize);

            if (array[i] > array[i + 1])
            {
                swapVars (&array[i], &array[i + 1]);

                isSortingNeeded = true;

                swapCount++;
            }

            compareCount++;
        }
    }

    QueryPerformanceCounter (&finish);

    assert (array);
    assert (0 <= arraySize);

    return {swapCount, compareCount, ROUND ((int) (finish.QuadPart - start.QuadPart))};
}
//}
//-----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Selection sorting
//----------------------------------------------------------------------------

Counters selectionSort (int array[], int arraySize)
{
    assert (array);
    assert (0 <= arraySize);
    if (arraySize <= 1) return {0, 0, 0};

    int swapCount    = 1;
    int compareCount = 1;
    LARGE_INTEGER start, finish;
    QueryPerformanceCounter (&start);

    for (int i = 0; i < arraySize; i++)
    {
        assert (0 <= i && i < arraySize);

        swapVars (&array[findMin (array, arraySize, i, arraySize - 1, &compareCount)], &array[i]);

        swapCount++;
    }

    QueryPerformanceCounter (&finish);

    assert (array);
    assert (0 <= arraySize);

    return {swapCount - 1, compareCount - 1, ROUND ((int) (finish.QuadPart - start.QuadPart))};
}

//}
//-----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Insertion sorting
//----------------------------------------------------------------------------

Counters insertionSort (int array[], int arraySize)
{
    assert (array);
    assert (0 <= arraySize);
    if (arraySize <= 1) return {0, 0, 0};

    int swapCount    = 1;
    int compareCount = 1;
    LARGE_INTEGER start, finish;
    QueryPerformanceCounter (&start);

    for (int i = 1; i < arraySize; i++)
    {
        assert (1 <= i && i < arraySize);

        rotateRight (array, arraySize, findInsertIndex (array, arraySize, i, &compareCount), i, &swapCount);
    }

    QueryPerformanceCounter (&finish);

    assert (array);
    assert (0 <= arraySize);

    return {swapCount - 1, compareCount - 1, ROUND ((int) (finish.QuadPart - start.QuadPart))};
}

//}
//-----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Binary Insertion sorting
//----------------------------------------------------------------------------

Counters binaryInsertionSort (int array[], int arraySize)
{
    assert (array);
    assert (0 <= arraySize);
    if (arraySize <= 1) return {0, 0, 0};

    int swapCount    = 1;
    int compareCount = 1;
    LARGE_INTEGER start, finish;
    QueryPerformanceCounter (&start);

    for (int i = 1; i < arraySize; i++)
    {
        assert (1 <= i && i < arraySize);

        rotateRight (array, arraySize, findInsertIndexBinary (array, arraySize, i, &compareCount), i, &swapCount);
    }

    QueryPerformanceCounter (&finish);

    assert (array);
    assert (0 <= arraySize);

    return {swapCount - 1, compareCount - 1, ROUND ((int) (finish.QuadPart - start.QuadPart))};
}

//}
//-----------------------------------------------------------------------------


//}
//----------------------------------------------------------------------------
