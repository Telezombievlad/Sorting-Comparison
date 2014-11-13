

//----------------------------------------------------------------------------
//{ Rendering
//----------------------------------------------------------------------------

void rendering (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                          Button  buttonArray[], int  buttonArraySize, Mode mode)
{
    assert (sortAlgArray);
    assert (buttonArray);

    for (int i = 0; i < sortAlgArraySize; i++)
    {
        assert (sortAlgArray[i].ok ());
        assert (0 <= i && i < sortAlgArraySize);

        if (sortAlgArray[i].getGraphicDrawn ().getMode ()) drawGraphic (sortAlgArray[i], mode);
    }

    drawButtons (sortAlgArray, sortAlgArraySize, buttonArray, buttonArraySize);

    puts ("NOT DEAD YET");

    assert (sortAlgArray);
    assert (buttonArray);

}

void drawGraphic (SortingAlgorithm sortAlg, Mode mode)
{
    assert (sortAlg.ok ());

    string nowDrawing = "nothing";

     txSetColor (RGB (sortAlg.getColor ().getRed   (),
                      sortAlg.getColor ().getGreen (),
                      sortAlg.getColor ().getBlue  ()));

    if (mode.getMode () == COMPS)
    {
        Point* comps = (Point*) calloc (GP.getMaxIndex () - GP.getMinIndex () + 1, sizeof (Point));
        comps = sortAlg.getComps ();

        for (int i = 0; i < GP.getStepCount (); i++)
        {
            assert (0 <= i && i < GP.getStepCount ());

            txLine (comps[i    ].getX (), comps[i    ].getY (),
                    comps[i + 1].getX (), comps[i + 1].getY ());
        }

        free (comps);

        nowDrawing = "comparisons";
    }

    if (mode.getMode () == SWAPS)
    {
        Point* swaps = (Point*) calloc (GP.getMaxIndex () - GP.getMinIndex () + 1, sizeof (Point));
        swaps = sortAlg.getComps ();

        for (int i = 0; i < GP.getStepCount (); i++)
        {
            assert (0 <= i && i < GP.getStepCount ());

            txLine (swaps[i    ].getX (), swaps[i    ].getY (),
                    swaps[i + 1].getX (), swaps[i + 1].getY ());
        }

        free (swaps);

        nowDrawing = "swaps";
    }

    if (mode.getMode () == TIME)
    {
        Point*  time = (Point*) calloc (GP.getMaxIndex () - GP.getMinIndex () + 1, sizeof (Point));
        time = sortAlg.getTime ();

        for (int i = 0; i < GP.getStepCount (); i++)
        {
            assert (0 <= i && i < GP.getStepCount ());

            txLine (time[i    ].getX (), time[i    ].getY (),
                    time[i + 1].getX (), time[i + 1].getY ());
        }

        free (time);

        nowDrawing = "time";
    }

    txSetColor (TX_BLACK);
    txDrawText (130, 405, 280, 435, nowDrawing.c_str ());


    assert (sortAlg.ok ());
}

void drawButtons (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                            Button  buttonArray[], int  buttonArraySize)
{
    assert (buttonArray);
    assert (sortAlgArray);

    for (int i = 0; i < sortAlgArraySize; i++)
    {
        assert (0 <= i && i < sortAlgArraySize);
        assert (0 <= i && i <  buttonArraySize);

        assert (sortAlgArray[i].ok ());

        buttonArray[sortAlgArray[i].getButtonNumber ()].render (sortAlgArray[i].getColor ());

        assert (sortAlgArray[i].ok ());
    }

    assert (buttonArray);
    assert (sortAlgArray);
}

//}
//-----------------------------------------------------------------------------
