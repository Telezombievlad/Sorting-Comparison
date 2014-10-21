#include "TXLib.h"

struct GraphicParameters
{
    int x, y, x1, y1;
    int minIndex, maxIndex, stepCount;
    double scale, timeScale;
};

//----------------------------------------------------------------------------
//{ Constants
//----------------------------------------------------------------------------

const int ARRAY_SIZE = 100;
const int WIDTH = 960, HEIGHT = 480;
const int BUTTON_ARRAY_SIZE = 5, SORT_ALG_ARRAY_SIZE = 3;
const int COMPS = 0, SWAPS = 1, TIME = 2, NOTHING = 3;
const GraphicParameters GP = {3, 3, 642, 352, 1, 100, 99, 0.03, 0.5};

//}
//-----------------------------------------------------------------------------

//ToDo: Check if alg sorted the array
//ToDo: Distribute between files
//ToDo: Document EACH function
//ToDo: More sorting algorithms: Quicksort, Mergesort, Shellsort
//ToDo: MaybeDo: Array class which knows its length etc.

//----------------------------------------------------------------------------
//{ Structures & classes
//----------------------------------------------------------------------------

struct Point
{
    int x, y;
};

struct Counters
{
    int swapCount, compCount, executionTime;
};

struct Color
{
    int red, green, blue;
};

class Button
{
    int x, y, w, h;
    bool buttonPressed;
};

class SortingAlgorithm
{

    public:
        SortingAlgorithm(Counters (*sortFunc) (int array[], int arraySize), Color color, int buttonNumber);
        ~SortingAlgorithm();

        Counters (*getSortFunc())(int array[], int arraySize) const;
        Color SortingAlgorithm::getColor () const;
        SortingAlgorithm::getComps () const;


        bool ok ();

    private:
        Counters (*sortFunc_) (int array[], int arraySize);
        Color color_;

        Point* comps_;
        Point* swaps_;
        Point*  time_;

        int buttonNumber_,
            graphicDrawn_; //graphicDrawn is supposed to be int cause it is used with modeSwitchButton
};


//----------------------------------------------------------------------------
//{ Constructors & destructors
//----------------------------------------------------------------------------

SortingAlgorithm::SortingAlgorithm(Counters (*sortFunc) (int array[], int arraySize), Color color, int buttonNumber) :

    sortFunc_(sortFunc),
    color_(color),

    comps_(NULL),
    swaps_(NULL),
     time_(NULL),

    buttonNumber_(buttonNumber),
    graphicDrawn_(0)
{
    comps_ = (Point*) calloc(ARRAY_SIZE, sizeof(Point));
    assert(comps_);

    swaps_ = (Point*) calloc(ARRAY_SIZE, sizeof(Point));
    assert(swaps_);

    time_ = (Point*) calloc(ARRAY_SIZE, sizeof(Point));
    assert(time_);

    assert(ok());
}

SortingAlgorithm::~SortingAlgorithm()
{
    free(comps_);
    free(swaps_);
    free(time_);
}

//}
//-----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Getters/setters
//----------------------------------------------------------------------------

Counters (*SortingAlgorithm::getSortFunc ())(int array[], int arraySize) const
{
    assert (ok ());
    return sortFunc_;
}

Color SortingAlgorithm::getColor () const
{
    assert (ok ());
    return color_;
}

SortingAlgorithm::getComps () const
{
    assert (ok ());
    return comps_;
}

SortingAlgorithm::getSwaps () const
{
    assert (ok ());
    return swaps_;
}

SortingAlgorithm::getTime () const
{
    assert (ok ());
    return time_;
}

SortingAlgorithm::getButtonNumber () const
{
    assert (ok ());
    return buttonNumber_;
}

SortingAlgorithm::getGraphicDrawn () const
{
    assert (ok ());
    return graphicDrawn_;
}

SortingAlgorithm::setGraphicDrawn (int newGraphicDrawn)
{
    assert (ok ());
    graphicDrawn_ = newGraphicDrawn;
}

//}
//-----------------------------------------------------------------------------

struct GraphicParameters
{
    int x, y, x1, y1;
    int minIndex, maxIndex, stepCount;
    double scale, timeScale;
};

//}
//-----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//{ Prototypes
//----------------------------------------------------------------------------


void calculations (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                             Button  buttonArray[], int  buttonArraySize, int* mode, int* updateGraphic);
void rendering    (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                          Button  buttonArray[], int  buttonArraySize, int mode);

void calcGraphic (SortingAlgorithm sortAlg);
void drawGraphic (SortingAlgorithm sortAlg, int mode);

void distributeButtons (Button buttonArray[], int buttonArraySize, int buttonCount, int x, int y, int x1, int y1);
void drawButtons       (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                                  Button  buttonArray[], int  buttonArraySize);
void modeSwitchButton  (Button buttonArray[], int buttonArraySize, int buttonNumber, int* mode, int modesCount);
bool buttonPressed     (Button button);

Counters bubbleSort    (int array[], int arraySize);
Counters selectionSort (int array[], int arraySize);
Counters insertionSort (int array[], int arraySize);

void swapVars              (int* varA, int* varB);
void fillArray             (int array[], int arraySize, bool fillRand);
int  find                  (int array[], int arraySize, int toFind, int foundEventNumber, int startIndex, int finishIndex); //ToDo: foundEventNumber is stupid name
int  findMin               (int array[], int arraySize, int startIndex, int finishIndex, int* compareCount);
int  findInsertIndex       (int array[], int arraySize, int orderedPart, int* compareCount);
int  findInsertIndexBinary (int array[], int arraySize, int orderedPart, int* compareCount);
void rotateRight           (int array[], int arraySize, int leftBorder, int rightBorder, int* swapCount);
int  seperateArrayParts    (int array[], int arraySize, int startIndex, int finishIndex, int* compareCount, int* swapCount);

//}
//-----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//{ Main
//----------------------------------------------------------------------------

int main ()
{
    int n = 0;

    SortingAlgorithm sortAlgArray[SORT_ALG_ARRAY_SIZE] =
    {SortingAlgorithm (   bubbleSort, { 12, 205,  90}, n++),
     SortingAlgorithm (selectionSort, {205,  12,  90}, n++),
     SortingAlgorithm (insertionSort, { 12,  90, 205}, n++)};

    Button buttonArray[BUTTON_ARRAY_SIZE] =
    {{  0,   0,  0,  0, 0},
     {  0,   0,  0,  0, 0},
     {  0,   0,  0,  0, 0},
     {200, 420, 70, 15, 0},
     { 32, 380, 28, 13, 0}};

    distributeButtons (buttonArray, BUTTON_ARRAY_SIZE, 3, 654, 140, 954, 440);

    int     mode  = COMPS,
    updateGraphic = 1/*true - updating graphics, false - not */;

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
        rendering    (sortAlgArray, SORT_ALG_ARRAY_SIZE, buttonArray, BUTTON_ARRAY_SIZE,  mode);

        txEnd ();
        txSleep (1000/30);
    }

    txDeleteDC (background);

    return 0;
}

//}
//-----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//{ Calculating and rendering
//----------------------------------------------------------------------------

void calculations (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                             Button  buttonArray[], int  buttonArraySize, int* mode, int* updateGraphic)
{
    assert (sortAlgArray);
    assert (buttonArray);
    assert (mode);
    assert (updateGraphic);

    for (int i = 0; i < sortAlgArraySize; i++)
    {
        assert (sortAlgArray[i].ok ());
        assert (0 <= i && i < sortAlgArraySize);

        if (*updateGraphic) calcGraphic (sortAlgArray[i]);

        modeSwitchButton (buttonArray, buttonArraySize, i, &sortAlgArray[i].graphicDrawn, 2);

        assert (sortAlgArray[i].ok ());
    }

    modeSwitchButton (buttonArray, buttonArraySize, 3,          mode, 3);
    modeSwitchButton (buttonArray, buttonArraySize, 4, updateGraphic, 2);

    assert (sortAlgArray);
    assert (buttonArray);
    assert (mode);
    assert (updateGraphic);
}

void rendering (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                          Button  buttonArray[], int  buttonArraySize, int mode)
{

    for (int i = 0; i < sortAlgArraySize; i++)
    {
        assert (sortAlgArray[i].ok ());
        assert (0 <= i && i < sortAlgArraySize);

        if (sortAlgArray[i].graphicDrawn) drawGraphic (sortAlgArray[i], mode);
    }

    drawButtons (sortAlgArray, sortAlgArraySize, buttonArray, buttonArraySize);

}

//}
//-----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//{ Graphic
//----------------------------------------------------------------------------

void calcGraphic (SortingAlgorithm sortAlg)
{
    assert (sortAlg.ok ());

    int array[1000] = {};

    Point tmp = {};
    int pointInterval = (GP.x1 - GP.x)/GP.stepCount,
        indexInterval = (GP.maxIndex - GP.minIndex)/GP.stepCount;

    double i = GP.minIndex;
    for (int j = 0; j <= GP.stepCount && i <= GP.maxIndex; j++)
    {
        assert (0 <= j && j <= GP.stepCount);
        assert (GP.minIndex <= i && i <= GP.maxIndex);

        fillArray (array, ROUND (i), true);
        Counters curRes = sortAlg.sortFunc (array, ROUND (i));

        tmp = {GP.x + ROUND (j * pointInterval), GP.y1 - ROUND (curRes.compCount * GP.scale)};
        sortAlg.comps[j] = tmp;

        tmp = {GP.x + ROUND (j * pointInterval), GP.y1 - ROUND (curRes.swapCount * GP.scale)};
        sortAlg.swaps[j] = tmp;

        tmp = {GP.x + ROUND (j * pointInterval), GP.y1 - ROUND (curRes.swapCount * GP.scale)};
        sortAlg.time[j] = tmp;

        i += indexInterval;
    }

    assert (sortAlg.ok ());
}

void drawGraphic (SortingAlgorithm sortAlg, int mode)
{
    assert (sortAlg.ok ());

    string nowDrawing = "nothing";

    if (mode == COMPS)
    {
        for (int i = 0; i < GP.stepCount; i++)
        {
            assert (0 <= i && i < GP.stepCount);

            txSetColor (RGB (sortAlg.color.red, sortAlg.color.green, sortAlg.color.blue));
            txLine (sortAlg.comps[i    ].x, sortAlg.comps[i    ].y,
                    sortAlg.comps[i + 1].x, sortAlg.comps[i + 1].y);
        }

        nowDrawing = "comparisons";
    }

    if (mode == SWAPS)
    {
        for (int i = 0; i < GP.stepCount; i++)
        {
            assert (0 <= i && i < GP.stepCount);

            txSetColor (RGB (sortAlg.color.red, sortAlg.color.green, sortAlg.color.blue));
            txLine (sortAlg.swaps[i    ].x, sortAlg.swaps[i    ].y,
                    sortAlg.swaps[i + 1].x, sortAlg.swaps[i + 1].y);
        }

        nowDrawing = "swaps";
    }

    if (mode == TIME)
    {
        for (int i = 0; i < GP.stepCount; i++)
        {
            assert (0 <= i && i < GP.stepCount);

            txSetColor (RGB (sortAlg.color.red, sortAlg.color.green, sortAlg.color.blue));
            txLine (sortAlg.time[i    ].x, sortAlg.time[i    ].y,
                    sortAlg.time[i + 1].x, sortAlg.time[i + 1].y);
        }
    }

    txSetColor (TX_BLACK);
    txDrawText (130, 405, 280, 435, nowDrawing.c_str());

    assert (sortAlg.ok ());
}

//}
//-----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//{ Buttons
//----------------------------------------------------------------------------

void distributeButtons (Button buttonArray[], int buttonArraySize, int buttonCount,
                        int x, int y, int x1, int y1)
{
    assert (buttonArray);
    assert (0 <= buttonCount && buttonCount < buttonArraySize);

    int  width = x1 - x;
    int height = y1 - y;

    assert (0 <=  width);
    assert (0 <= height);

    int radius = ROUND (height/(3 * buttonCount + 1));

    for (int i = 0; i < buttonCount; i++)
    {
        assert (0 <= i && i < buttonCount);

        buttonArray[i] = {x + ROUND (width/2), y + (3 * i + 1) * radius, 2 * radius, 2 * radius, false};
    }

    assert (buttonArray);
}

void drawButtons (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                            Button  buttonArray[], int  /* buttonArraySize */)
{
    assert (buttonArray);
    assert (sortAlgArray);

    for (int i = 0; i < sortAlgArraySize; i++)
    {
        assert (sortAlgArray[i].ok ());

        Button currentButton = buttonArray[sortAlgArray[i].buttonNumber];

        txSetFillColor (RGB (sortAlgArray[i].color.red, sortAlgArray[i].color.green, sortAlgArray[i].color.blue));
        txRectangle    (currentButton.x, currentButton.y,
                        currentButton.x + currentButton.w,
                        currentButton.y + currentButton.h);

        assert (sortAlgArray[i].ok ());
    }

    assert (buttonArray);
    assert (sortAlgArray);
}

void modeSwitchButton  (Button buttonArray[], int buttonArraySize, int buttonNumber, int* mode, int modesCount)
{
    assert (buttonArray);
    assert (mode);
    assert (0 <= buttonNumber && buttonNumber < buttonArraySize);

    if (buttonPressed (buttonArray[buttonNumber]) && (buttonArray[buttonNumber].buttonPressed == false))
    {
        buttonArray[buttonNumber].buttonPressed = true;

        (*mode)++;

        if (modesCount <= *mode) *mode -= modesCount;
    }

    if (!buttonPressed (buttonArray[buttonNumber]))
    {
        buttonArray[buttonNumber].buttonPressed = false;
    }

    printf ("buttonArray[%d].buttonPressed == %d \n", buttonNumber, buttonArray[buttonNumber].buttonPressed);

    assert (buttonArray);
    assert (mode);
}

bool buttonPressed (Button button)
{
    if (button.x - button.rX < txMouseX () &&
        button.x + button.rX > txMouseX () &&
        button.y - button.rY < txMouseY () &&
        button.y + button.rY > txMouseY () &&
        txMouseButtons () == 1)
    {
        puts ("buttonPressed");
        return true;
    }

    printf ("TXMouseX == %d, TXMouseY == %d\n", txMouseX (), txMouseY ());

    return false;
}

//}
//-----------------------------------------------------------------------------

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
//-----------------------------------------------------------------------------

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
//-----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//{ Asserts
//----------------------------------------------------------------------------

bool SortingAlgorithm::ok() const
{
    bool everythingOk = true;

    if (!this)
    {
        printf ("Something is wrong with your Sorting Algorithm");
        everythingOk = false;
    }

    if (!this->sortFunc) return false;

    if (0 > this->color.red   || this->color.red   > 255)
    {
        printf ("Something is wrong with your red colour");
        everythingOk = false;
    }
    if (0 > this->color.green || this->color.green > 255)
    {
        printf ("Something is wrong with your green colour");
        everythingOk = false;
    }
    if (0 > this->color.blue  || this->color.blue  > 255 )
    {
        printf ("Something is wrong with your blue colour");
        everythingOk = false;
    }

    if (!this->comps)
    {
        printf ("Something is wrong with comparison array");
        everythingOk = false;
    }
    if (!this->swaps)
    {
        printf ("Something is wrong with swap array");
        everythingOk = false;
    }
    if (!this->time )
    {
        printf ("Something is wrong with time array");
        everythingOk = false;
    }

    if (this->buttonNumber < 0)
    {
        printf ("Something is wrong with number of buttons");
        everythingOk = false;
    }

    if (this->graphicDrawn < 0 || 1 < this->graphicDrawn)
    {
        printf ("Something is wrong with graphicDrawn");
        everythingOk = false;
    }

    if (everythingOk) return true;
    else return false;
}

//}
//-----------------------------------------------------------------------------



