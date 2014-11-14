
#include "includes.h"

//----------------------------------------------------------------------------
//{ Main
//----------------------------------------------------------------------------

int main ()
{
    int n = 0;

    SortingAlgorithm sortAlgArray[SORT_ALG_ARRAY_SIZE] =
    {
        SortingAlgorithm (         bubbleSort, { 12, 205,  90}, n++, Mode (0, 2)),
        SortingAlgorithm (      selectionSort, {205,  12,  90}, n++, Mode (0, 2)),
        SortingAlgorithm (      insertionSort, { 12,  90, 205}, n++, Mode (0, 2)),
        SortingAlgorithm (binaryInsertionSort, {112,  90, 155}, n++, Mode (0, 2))
    };

    Button buttonArray[BUTTON_ARRAY_SIZE] =
    {
        Button (Point (  0,   0),   0,  0, "BubbleSort"         ),
        Button (Point (  0,   0),   0,  0, "SelectionSort"      ),
        Button (Point (  0,   0),   0,  0, "InsertionSort"      ),
        Button (Point (  0,   0),   0,  0, "BinaryInsertionSort"),
        Button (Point (130, 405), 140, 30, "Now watching:"      ),
        Button (Point (  4, 367),  56, 26, "Play/Stop"          )
    };

    distributeButtons (buttonArray, BUTTON_ARRAY_SIZE, 4, Point (654, 140), Point (954, 440));

    Mode mode     = Mode(COMPS, 3),
    updateGraphic = Mode(    1, 2);

    _txWindowStyle &= ~WS_CAPTION;
    txCreateWindow (WIDTH, HEIGHT);
    txTextCursor (false);

    HDC background = txLoadImage ("sortTube.bmp");
    assert (background);

    while (!GetAsyncKeyState (VK_ESCAPE))
    {
        txBegin ();
        txBitBlt (txDC (), 0, 0, 960, 480, background);
        txClearConsole ();

        calculations (sortAlgArray, SORT_ALG_ARRAY_SIZE, buttonArray, BUTTON_ARRAY_SIZE, &mode, &updateGraphic);

        //rendering    (sortAlgArray, SORT_ALG_ARRAY_SIZE, buttonArray, BUTTON_ARRAY_SIZE,  mode);

        txEnd ();
        txSleep (1000/30);
    }

    txDeleteDC (background);

    return 0;
}

//}
//----------------------------------------------------------------------------
