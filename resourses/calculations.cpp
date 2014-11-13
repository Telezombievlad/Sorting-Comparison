#include "TXLib.h"
#include "classes.h"

//----------------------------------------------------------------------------
//{ Calculating
//----------------------------------------------------------------------------

void calculations (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                             Button  buttonArray[], int  buttonArraySize,  Mode* mode, Mode* updateGraphic)
{
    assert (sortAlgArray);
    assert (buttonArray);
    assert (mode);
    assert (updateGraphic);

    for (int i = 0; i < sortAlgArraySize; i++)
    {
        assert (sortAlgArray[i].ok ());
        assert (0 <= i && i < sortAlgArraySize);
        assert (0 <= i && i < buttonArraySize);

        if (updateGraphic->getMode ()) calcGraphic (sortAlgArray[i]);


        //printf ("Mode (%d, %d)\n", sortAlgArray[i].getGraphicDrawn ().getMode (), sortAlgArray[i].getGraphicDrawn ().getModesCount ());

        Mode newMode = sortAlgArray[i].getGraphicDrawn ();
        buttonArray[i].modeSwitchButton (&newMode);
        sortAlgArray[i].setGraphicDrawn (newMode);

        //printf ("Mode (%d, %d)\n", sortAlgArray[i].getGraphicDrawn ().getMode (), sortAlgArray[i].getGraphicDrawn ().getModesCount ());

        assert (sortAlgArray[i].ok ());
    }

    buttonArray[4].modeSwitchButton (mode);
    buttonArray[5].modeSwitchButton (updateGraphic);

    assert (sortAlgArray);
    assert (buttonArray);
    assert (mode);
    assert (updateGraphic);
}

void calcGraphic (SortingAlgorithm sortAlg)
{
    assert (sortAlg.ok ());

    int pointInterval = (GP.getRightBottomPoint ().getX () - GP.getLeftTopPoint ().getX ())/GP.getStepCount (),
        indexInterval = (GP.getMaxIndex () - GP.getMinIndex ())/GP.getStepCount ();

    int* array = (int*) calloc (GP.getMaxIndex () + 1, sizeof (int));

    Point* comps = (Point*) calloc (GP.getStepCount () + 1, sizeof (Point));
    Point* swaps = (Point*) calloc (GP.getStepCount () + 1, sizeof (Point));
    Point*  time = (Point*) calloc (GP.getStepCount () + 1, sizeof (Point));

    int x  = GP.getRightBottomPoint ().getX (),
        y1 = GP.getRightBottomPoint ().getY ();

    double i = GP.getMinIndex ();
    for (int j = 0; j <= GP.getStepCount () && i <= GP.getMaxIndex (); j++)
    {
        assert (0 <= j && j <= GP.getStepCount ());
        assert (GP.getMinIndex () <= i && i <= GP.getMaxIndex ());

        fillArray (array, ROUND (i), true);
        Counters curRes = sortAlg.getSortFunc () (array, ROUND (i));

        comps[j] = {x + ROUND (j * pointInterval), y1 - ROUND (curRes.getCompCount ()     * GP.getScale ())};

        swaps[j] = {x + ROUND (j * pointInterval), y1 - ROUND (curRes.getSwapCount ()     * GP.getScale ())};

        time[j]  = {x + ROUND (j * pointInterval), y1 - ROUND (curRes.getExecutionTime () * GP.getScale ())};


        i += indexInterval;
    }

    free (array);
    free (comps);
    free (swaps);
    free (time );

    assert (sortAlg.ok ());
}

void distributeButtons (Button buttonArray[], int buttonArraySize, int buttonCount,
                        Point LTPoint, Point RBPoint)
{
    assert (buttonArray);
    assert (0 <= buttonCount && buttonCount < buttonArraySize);

    int  width = RBPoint.getX () - LTPoint.getX ();
    int height = RBPoint.getY () - LTPoint.getY ();

    assert (0 <=  width);
    assert (0 <= height);

    int radius = ROUND (height/(3 * buttonCount + 1));

    for (int i = 0; i < buttonCount; i++)
    {
        assert (0 <= i && i < buttonCount);

        buttonArray[i].setCoords (Point (LTPoint.getX () + ROUND (width/2) - radius, LTPoint.getY () + (3 * i + 1) * radius));
        buttonArray[i].setWidth  (2 * radius)
                      .setHeight (2 * radius);
    }

    assert (buttonArray);
}


//}
//----------------------------------------------------------------------------
