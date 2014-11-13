
//----------------------------------------------------------------------------
//{ Additional functions
//----------------------------------------------------------------------------

void swapVars (int* varA, int* varB)
{
    assert (varA);
    assert (varB);

    int tempVar = *varA;
    *varA =   *varB;
    *varB = tempVar;

    assert (varA);
    assert (varB);
}

void fillArray (int array[], int arraySize, bool fillRand)
{
    assert (array);

    for (int i = 0; i < arraySize; i++)
    {
        assert (0 <= i && i < arraySize);

        if (fillRand) array[i] = random (999);
        else array[i] = 0;//ToDo: HERE
    }

    assert (array);
}

int find (int array[], int arraySize, int toFind, int foundEventNumber, int startIndex, int finishIndex)
{
    assert (array);

    int foundEventsRemain = foundEventNumber; //ToDo: var names make me die

    for (int i = startIndex; i < arraySize && i <= finishIndex; i++)
    {
        assert (0 <= i && i < arraySize);

        if (array[i] == toFind) foundEventsRemain--;
        if (foundEventsRemain == 0) return i;
    }

    return -1; //ToDo: Document this
}

int findMin (int array[], int arraySize, int startIndex, int finishIndex, int* compareCount)
{
    assert (array);
    assert (*compareCount);
    assert (0 <=  startIndex &&  startIndex < arraySize);
    assert (0 <= finishIndex && finishIndex < arraySize);

    int      min = array[startIndex];
    int minIndex =       startIndex;

    for (int i = startIndex + 1; i <= finishIndex && i < arraySize; i++)
    {
        assert (0 <= i && i < arraySize);

        if (min > array[i])
        {
            minIndex = i;
            min = array[i];
        }

        (*compareCount)++;
    }

    assert (array);
    assert (*compareCount);

    return minIndex;
}

int findInsertIndex (int array[], int arraySize, int orderedPart, int* compareCount)
{
    assert (array);
    assert (*compareCount);
    assert (0 <= orderedPart && orderedPart < arraySize);

    for (int i = 0; i < arraySize && i <= orderedPart; i++)
    {
        (*compareCount)++;

        //ToDo: should assert i
        if (array[orderedPart] <= array[i]) return i;
    }

    return orderedPart;
}

int findInsertIndexBinary (int array[], int arraySize, int orderedPart, int* compareCount)
{
    assert (array);
    assert (*compareCount);
    assert (0 <= orderedPart && orderedPart < arraySize);

    int  leftComparator  =               0;
    int rightComparator  = orderedPart - 1;
    int         middle   =               0;

    while (leftComparator < rightComparator)
    {
        assert (0 <= middle || middle < arraySize);

        middle = leftComparator + (rightComparator - leftComparator)/2;

        if (array[middle] == array[orderedPart]) return middle;

        if (array[middle] < array[orderedPart]) leftComparator = middle + 1;
        else rightComparator = middle;

        *(compareCount) += 2;
    }

    assert (array);
    assert (*compareCount);
    assert (0 <= rightComparator && rightComparator < arraySize);

    return rightComparator;
}

void rotateRight (int array[], int arraySize, int leftBorder, int rightBorder, int* swapCount)
{
    assert (array);
    assert (*swapCount);

    assert (0 <=  leftBorder &&  leftBorder < arraySize);
    assert (0 <= rightBorder && rightBorder < arraySize);

    int temp = array[rightBorder];

    for (int i = rightBorder - 1; 0 <= i && leftBorder <= i; i--)
    {
        assert (0 <= i && i < arraySize - 1);

        if (leftBorder != rightBorder) array[i + 1] = array[i];

        (*swapCount)++;
    }

    array[leftBorder] = temp;

    (*swapCount) += 2;

    assert (array);
    assert (*swapCount);
}

//}
//----------------------------------------------------------------------------
