
#ifndef __SORTING_ALGORITHMS_CLASSES__
#define __SORTING_ALGORITHMS_CLASSES__

//----------------------------------------------------------------------------
//{ Classes
//----------------------------------------------------------------------------


    //----------------------------------------------------------------------------
    //{ Point
    //----------------------------------------------------------------------------

        class Point
        {
            public:
                // Constructor & destructor:

                    Point (int x, int y);
                    ~Point ();

                // Getters & setters:

                    int    getX () const;
                    Point& setX (int x);

                    int    getY () const;
                    Point& setY (int y);

                // Other functions:

                    bool ok () const;

            private:
                int x_, y_;
        };


        //----------------------------------------------------------------------------
        //{ Constructor & destructor
        //----------------------------------------------------------------------------

            Point::Point (int x, int y) :
                x_ (x),
                y_ (y)
                {
                    assert (ok ());
                }

            Point::~Point ()
            {
            }

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Getters & setters
        //----------------------------------------------------------------------------

            //----------------------------------------------------------------------------
            //{ X
            //----------------------------------------------------------------------------


                int Point::getX () const
                {
                    assert (ok ());
                    return x_;
                }

                Point& Point::setX (int x)
                {
                    assert (ok ());
                    x_ = x;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------

            //----------------------------------------------------------------------------
            //{ Y
            //----------------------------------------------------------------------------


                int Point::getY () const
                {
                    assert (ok ());
                    return y_;
                }

                Point& Point::setY (int y)
                {
                    assert (ok ());
                    y_ = y;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Functions
        //----------------------------------------------------------------------------

            bool Point::ok () const
            {
                if (!this)
                {
                    puts ("Your point is empty");
                    return false;
                }

                return true;
            }

        //}
        //----------------------------------------------------------------------------

    //}
    //----------------------------------------------------------------------------

    /* Array, which knows it's length.
    //----------------------------------------------------------------------------
    //{ Array
    //----------------------------------------------------------------------------

        template <class A_Type> class Array
        {
            public:
                // Constructor & destructor:



                // Getters & setters:

                    A_Type* getArray () const;
                    int     getArraySize () const;

                // Other functions:



            private:
                A_Type* array_;
                int arraySize_;
        };


        //----------------------------------------------------------------------------
        //{ Constructor & destructor
        //----------------------------------------------------------------------------

            Array::Array (int arraySize) :
                arraySize_ (arraySize)
            {
                array_ = calloc (arraySize, sizeof (A_Type));

                assert (ok ());
            }

            Array::~Array ()
            {
                free (array_-);
            }

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Getters & setters
        //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Array
            //----------------------------------------------------------------------------

                A_Type* Array::getArray () const
                {
                    assert (ok ());
                    return array_;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ ArraySize
            //----------------------------------------------------------------------------

                int Array::getArraySize () const
                {
                    assert (ok ());
                    return arraySize_;
                }

            //}
            //----------------------------------------------------------------------------

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Functions
        //----------------------------------------------------------------------------


        //}
        //----------------------------------------------------------------------------

    //}
    //----------------------------------------------------------------------------
    */

    //----------------------------------------------------------------------------
    //{ Counters
    //----------------------------------------------------------------------------

        class Counters
        {
            public:
                // Constructor & destructor:

                     Counters (int swapCount, int compCount, int executionTime);
                    ~Counters ();

                // Getters & setters:

                    int       getSwapCount () const;
                    Counters& setSwapCount (int swapCount);

                    int       getCompCount () const;
                    Counters& setCompCount (int compCount);

                    int       getExecutionTime () const;
                    Counters& setExecutionTime (int executionTime);

                // Other functions:

                    bool ok () const;

            private:
                int swapCount_, compCount_, executionTime_;

        };


        //----------------------------------------------------------------------------
        //{ Constructor & destructor
        //----------------------------------------------------------------------------

            Counters::Counters (int swapCount, int compCount, int executionTime) :
                swapCount_     (swapCount    ),
                compCount_     (compCount    ),
                executionTime_ (executionTime)
                {
                    assert (ok ());
                }

            Counters::~Counters ()
            {}



        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Getters & setters
        //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Swaps count
            //----------------------------------------------------------------------------

                int Counters::getSwapCount () const
                {
                    assert (ok ());
                    return swapCount_;
                }

                Counters& Counters::setSwapCount (int swapCount)
                {
                    assert (ok ());
                    swapCount_ = swapCount;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------

            //----------------------------------------------------------------------------
            //{ Comparisons count
            //----------------------------------------------------------------------------

                int Counters::getCompCount () const
                {
                    assert (ok ());
                    return compCount_;
                }

                Counters& Counters::setCompCount (int compCount)
                {
                    assert (ok ());
                    compCount_ = compCount;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------

            //----------------------------------------------------------------------------
            //{ Execution time
            //----------------------------------------------------------------------------

                int Counters::getExecutionTime () const
                {
                    assert (ok ());
                    return executionTime_;
                }

                Counters& Counters::setExecutionTime (int executionTime)
                {
                    assert (ok ());
                    executionTime_ = executionTime;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Functions
        //----------------------------------------------------------------------------

            bool Counters::ok () const
            {
                bool everythingOk = true;

                if (swapCount_ < 0)
                {
                    everythingOk = false;
                    puts ("Sorting algorithm coped in negative swaps.");
                }

                if (compCount_ < 0)
                {
                    everythingOk = false;
                    puts ("Sorting algorithm coped in negative comparisons.");
                }

                if (executionTime_ < 0)
                {
                    everythingOk = false;
                    puts ("Sorting algorithm coped in negative time.");
                }

                return everythingOk;
            }

        //}
        //----------------------------------------------------------------------------

    //}
    //----------------------------------------------------------------------------


    //----------------------------------------------------------------------------
    //{ Color
    //----------------------------------------------------------------------------

        class Color
        {
            public:
                // Constructor & destructor:

                     Color (int red, int green, int blue);
                    ~Color ();

                // Getters & setters:

                    int    getRed () const;
                    Color& setRed (int red);

                    int    getGreen () const;
                    Color& setGreen (int green);

                    int    getBlue () const;
                    Color& setBlue (int blue);

                // Other functions:

                    bool ok () const;

            private:
                int red_, green_, blue_;
        };


        //----------------------------------------------------------------------------
        //{ Constructor & destructor
        //----------------------------------------------------------------------------

            Color::Color (int red, int green, int blue) :
                red_   (red  ),
                green_ (green),
                blue_  (blue )
                {
                    assert (ok ());
                }

            Color::~Color ()
            {}

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Getters & setters
        //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Red
            //----------------------------------------------------------------------------

                int Color::getRed () const
                {
                    assert (ok ());
                    return red_;
                }

                Color& Color::setRed (int red)
                {
                    assert (ok ());
                    red_ = red;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Green
            //----------------------------------------------------------------------------

                int Color::getGreen () const
                {
                    assert (ok ());
                    return green_;
                }

                Color& Color::setGreen (int green)
                {
                    assert (ok ());
                    green_ = green;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Blue
            //----------------------------------------------------------------------------

                int Color::getBlue () const
                {
                    assert (ok ());
                    return blue_;
                }

                Color& Color::setBlue (int blue)
                {
                    assert (ok ());
                    blue_ = blue;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Functions
        //----------------------------------------------------------------------------

            bool Color::ok () const
            {
                bool everythingOk = true;

                if (0 > red_ || red_ > 255)
                {
                    everythingOk = false;
                    puts ("Red component of this color is incorrect.");
                }

                if (0 > green_ || green_ > 255)
                {
                    everythingOk = false;
                    puts ("Green component of this color is incorrect.");
                }

                if (0 > blue_ || blue_ > 255)
                {
                    everythingOk = false;
                    puts ("Blue component of this color is incorrect.");
                }

                return everythingOk;
            }

        //}
        //----------------------------------------------------------------------------

    //}
    //----------------------------------------------------------------------------


    //----------------------------------------------------------------------------
    //{ Mode
    //----------------------------------------------------------------------------

        class Mode
        {
            public:
                // Constructor & destructor:

                     Mode (int mode, int modesCount);
                    ~Mode ();

                // Getters & setters:

                    int getMode ();

                    int getModesCount ();


                // Other functions:

                    bool ok ();
                    void add (int component);

            private:
                int mode_;
                int modesCount_;
        };


        //----------------------------------------------------------------------------
        //{ Constructor & destructor
        //----------------------------------------------------------------------------

            Mode::Mode (int mode, int modesCount) :
                mode_       (mode % modesCount),
                modesCount_ (modesCount       )
                {
                    assert (ok ());
                }

            Mode::~Mode ()
            {}


        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Getters & setters
        //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Mode
            //----------------------------------------------------------------------------

                int Mode::getMode ()
                {
                    assert (ok ());
                    return mode_;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ ModesCount
            //----------------------------------------------------------------------------

                int Mode::getModesCount ()
                {
                    assert (ok ());
                    return modesCount_;
                }

            //}
            //----------------------------------------------------------------------------


        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Functions
        //----------------------------------------------------------------------------

            bool Mode::ok ()
            {
                bool everythingOk = true;

                if (0 > mode_ || mode_ > modesCount_)
                {
                    everythingOk = false;
                    puts ("Mode is incorrect.");
                }

                if (0 > modesCount_)
                {
                    everythingOk = false;
                    puts ("The number of modes is negative.");
                }

                return everythingOk;
            }

            void Mode::add (int component)
            {
                assert (ok ());
                mode_ = (mode_ + component) % modesCount_;
                assert (ok ());
            }

        //}
        //----------------------------------------------------------------------------

    //}
    //----------------------------------------------------------------------------


    //----------------------------------------------------------------------------
    //{ Button
    //----------------------------------------------------------------------------

        class Button
        {
            public:
                // Constructor & destructor:

                     Button (Point coords, int width, int height, string buttonName);
                    ~Button ();

                // Getters & setters:

                    Point   getCoords () const;
                    Button& setCoords (Point coords);

                    int     getWidth () const;
                    Button& setWidth (int width);

                    int     getHeight () const;
                    Button& setHeight (int height);

                    bool    getButtonPressed () const;
                    Button& setButtonPressed (bool buttonPressed);

                    string  getButtonName () const;
                    Button& setButtonName (string buttonName);

                // Other functions:

                    bool ok () const;
                    bool buttonPressed () const;
                    void modeSwitchButton (Mode* mode);
                    void render (Color color) const;

            private:
                Point coords_;

                int w_, h_;

                bool buttonPressed_;

                string buttonName_;
        };


        //----------------------------------------------------------------------------
        //{ Constructor & destructor
        //----------------------------------------------------------------------------

        Button::Button (Point coords, int width, int height, string buttonName) :
            coords_ (coords),
            w_      (width ),
            h_      (height),
            buttonPressed_ (false),
            buttonName_ (buttonName)
            {
                assert (ok ());
            }

        Button::~Button ()
        {}

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Getters & setters
        //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Coordinates
            //---------------------------------------------------------------------------

                Point Button::getCoords () const
                {
                    assert (ok ());
                    return coords_;
                }

                Button& Button::setCoords (Point coords)
                {
                    assert (ok ());
                    coords_ = coords;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Width
            //---------------------------------------------------------------------------

                int Button::getWidth () const
                {
                    assert (ok ());
                    return w_;
                }

                Button& Button::setWidth (int width)
                {
                    assert (ok ());
                    w_ = width;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Height
            //---------------------------------------------------------------------------

                int Button::getHeight () const
                {
                    assert (ok ());
                    return h_;
                }

                Button& Button::setHeight (int height)
                {
                    assert (ok ());
                    h_ = height;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ ButtonPressed
            //---------------------------------------------------------------------------

                bool Button::getButtonPressed () const
                {
                    assert (ok ());
                    return buttonPressed_;
                }

                Button& Button::setButtonPressed (bool buttonPressed)
                {
                    assert (ok ());
                    buttonPressed_ = buttonPressed;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ ButtonName
            //----------------------------------------------------------------------------

                string Button::getButtonName () const
                {
                    assert (ok ());
                    return buttonName_;
                }

                Button& Button::setButtonName (string buttonName)
                {
                    assert (ok ());
                    buttonName_ = buttonName;
                    assert (ok ());
                    return *this;
                }

            //}
            //----------------------------------------------------------------------------


        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Functions
        //----------------------------------------------------------------------------

            bool Button::ok () const
            {
                bool everythingOk = true;

                if (!this)
                {
                     everythingOk = false;
                     puts ("This button is empty.");
                }

                if (!coords_.ok ())
                {
                    puts("Coordinates areen't OK.");
                    everythingOk = false;
                }

                if (0 > w_)
                {
                    everythingOk = false;
                    puts ("Button's width is negative.");
                }

                if (0 > h_)
                {
                    everythingOk = false;
                    puts ("Button's height is negative.");
                }

                return everythingOk;
            }

            bool Button::buttonPressed () const
            {
                assert (ok ());

                if (coords_.getX () >= txMouseX () && txMouseX () < coords_.getX () + w_ &&
                    coords_.getY () >= txMouseY () && txMouseY () < coords_.getY () + h_ &&
                    txMouseButtons () == 1)
                {
                    return true;
                }

                return false;
            }

            void Button::modeSwitchButton (Mode* mode)
            {
                assert (ok ());

                if (!buttonPressed_ && buttonPressed ())
                {
                    buttonPressed_ = true;

                    mode->add (1);
                }

                if (!buttonPressed ()) buttonPressed_ = false;

                assert (ok ());
            }

            void Button::render (Color color) const
            {
                assert (ok ());

                txSetFillColor (RGB (color.getRed (), color.getGreen (), color.getBlue ()));

                txRectangle (coords_.getX ()     , coords_.getY (),
                             coords_.getX () + w_, coords_.getY ());
            }


        //}
        //----------------------------------------------------------------------------

    //}
    //----------------------------------------------------------------------------


    //----------------------------------------------------------------------------
    //{ Graphic
    //----------------------------------------------------------------------------

        class Graphic
        {
            public:
                // Constructor & destructor:
                    Graphic (Point LeftTopPoint, Point RightBottomPoint,
                             int minIndex, int maxIndex, int stepCount,
                             double scale, double timeScale);

                    ~Graphic ();

                // Getters:

                    Point getLeftTopPoint () const;
                    Point getRightBottomPoint () const;

                    int getMinIndex () const;
                    int getMaxIndex () const;

                    int getStepCount () const;

                    double getScale     () const;
                    double getTimeScale () const;

                // Other functions:

                    bool ok () const;

            private:

                Point LTPoint_, RBPoint_;

                int minIndex_, maxIndex_, stepCount_;

                double scale_, timeScale_;
        };


        //----------------------------------------------------------------------------
        //{ Constructor & destructor
        //----------------------------------------------------------------------------

            Graphic::Graphic (Point LeftTopPoint, Point RightBottomPoint, int minIndex, int maxIndex, int stepCount, double scale, double timeScale) :
            LTPoint_   (LeftTopPoint    ),
            RBPoint_   (RightBottomPoint),
            minIndex_  (minIndex ),
            maxIndex_  (maxIndex ),
            stepCount_ (stepCount),
            scale_     (scale    ),
            timeScale_ (timeScale)
            {
                assert (ok ());
            }

            Graphic::~Graphic ()
            {}

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Getters
        //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Left Top Point
            //----------------------------------------------------------------------------


                Point Graphic::getLeftTopPoint () const
                {
                    assert (ok ());
                    return LTPoint_;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Right Bottom Point
            //----------------------------------------------------------------------------

                Point Graphic::getRightBottomPoint () const
                {
                    assert (ok ());
                    return RBPoint_;
                }


            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Indexes
            //----------------------------------------------------------------------------


                //----------------------------------------------------------------------------
                //{ Minimum
                //----------------------------------------------------------------------------

                    int Graphic::getMinIndex () const
                    {
                        assert (ok ());
                        return minIndex_;
                    }

                //}
                //----------------------------------------------------------------------------


                //----------------------------------------------------------------------------
                //{ Maximum
                //----------------------------------------------------------------------------

                    int Graphic::getMaxIndex () const
                    {
                        assert (ok ());
                        return maxIndex_;
                    }

                //}
                //----------------------------------------------------------------------------


            //}
            //-----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Step Count
            //----------------------------------------------------------------------------

                int Graphic::getStepCount () const
                {
                    assert (ok ());
                    return stepCount_;
                }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Scales
            //----------------------------------------------------------------------------


                //----------------------------------------------------------------------------
                //{ Swaps & comparisons
                //----------------------------------------------------------------------------

                    double Graphic::getScale () const
                    {
                        assert (ok ());
                        return scale_;
                    }

                //}
                //-----------------------------------------------------------------------------


                //----------------------------------------------------------------------------
                //{ Time
                //----------------------------------------------------------------------------

                    double Graphic::getTimeScale () const
                    {
                        assert (ok ());
                        return timeScale_;
                    }

                //}
                //-----------------------------------------------------------------------------


            //}
            //----------------------------------------------------------------------------


        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Functions
        //----------------------------------------------------------------------------

            bool Graphic::ok () const
            {
                bool everythingOk = true;

                if (!LTPoint_.ok ()) everythingOk = false;
                if (!RBPoint_.ok ()) everythingOk = false;

                if (0 > minIndex_)
                {
                    everythingOk = false;
                    puts ("Minimum index is negative.");
                }

                if (0 > maxIndex_)
                {
                    everythingOk = false;
                    puts ("Maximum index is negative.");
                }

                if (0 > stepCount_)
                {
                    everythingOk = false;
                    puts ("Graphic has less than 1 points.");
                }

                if (0 > scale_)
                {
                    everythingOk = false;
                    puts ("Scale is negative.");
                }

                if (0 > timeScale_)
                {
                    everythingOk = false;
                    puts ("Scale is negative.");
                }

                return everythingOk;
            }

        //}
        //----------------------------------------------------------------------------


    //}
    //----------------------------------------------------------------------------


    const Graphic GP = Graphic (Point (3, 3), Point (642, 352), 1, 100, 99, 0.03, 0.5);
    // SortingAlgorith's constructor needs this constants and i haven't invented anything better yet.


    //----------------------------------------------------------------------------
    //{ SortingAlgorithm
    //----------------------------------------------------------------------------

    class SortingAlgorithm
    {

        public:
            // Constructor & destructor:

                 SortingAlgorithm (Counters (*sortFunc) (int array[], int arraySize), Color color, int buttonNumber, Mode graphicDrawn);
                ~SortingAlgorithm ();

            // Getters & setters:

                Counters (*getSortFunc())(int array[], int arraySize) const;

                Color getColor () const;

                Point* getComps () const;
                Point* getSwaps () const;
                Point* getTime  () const;

                SortingAlgorithm& setComps (Point* newComps);
                SortingAlgorithm& setSwaps (Point* newSwaps);
                SortingAlgorithm& setTime  (Point* newTime);

                int getButtonNumber () const;

                Mode getGraphicDrawn () const;
                SortingAlgorithm& setGraphicDrawn (Mode newGraphicDrawn);

            // Functions:

                bool ok () const;

        private:
            Counters (*sortFunc_) (int array[], int arraySize);

            Color color_;

            Point* comps_;
            Point* swaps_;
            Point*  time_;

            int buttonNumber_;

            Mode graphicDrawn_; //graphicDrawn is supposed to be int cause it is used with modeSwitchButton
    };


        //----------------------------------------------------------------------------
        //{ Constructors & destructors
        //----------------------------------------------------------------------------

        SortingAlgorithm::SortingAlgorithm(Counters (*sortFunc) (int array[], int arraySize), Color color, int buttonNumber, Mode graphicDrawn) :
            sortFunc_ (sortFunc),
            color_ (color),
            comps_ (NULL),
            swaps_ (NULL),
            time_  (NULL),
            buttonNumber_ (buttonNumber),
            graphicDrawn_ (graphicDrawn)
        {
            comps_ = (Point*) calloc(GP.getStepCount () + 1, sizeof(Point));
            assert(comps_);

            swaps_ = (Point*) calloc(GP.getStepCount () + 1, sizeof(Point));
            assert(swaps_);

            time_  = (Point*) calloc(GP.getStepCount () + 1, sizeof(Point));
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
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Getters/setters
        //----------------------------------------------------------------------------

            //----------------------------------------------------------------------------
            //{ Sorting function
            //----------------------------------------------------------------------------

            Counters (*SortingAlgorithm::getSortFunc ())(int array[], int arraySize) const
            {
                assert (ok ());
                return sortFunc_;
            }

            //}
            //----------------------------------------------------------------------------

            //----------------------------------------------------------------------------
            //{ Color
            //----------------------------------------------------------------------------

            Color SortingAlgorithm::getColor () const
            {
                assert (ok ());
                return color_;
            }

            //}
            //----------------------------------------------------------------------------

            //----------------------------------------------------------------------------
            //{ Point arrays
            //----------------------------------------------------------------------------

                //----------------------------------------------------------------------------
                //{ Comparisons array
                //----------------------------------------------------------------------------

                Point* SortingAlgorithm::getComps () const
                {
                    assert (ok ());
                    return comps_;
                }

                SortingAlgorithm& SortingAlgorithm::setComps (Point* newComps)
                {
                    assert (ok ());
                    comps_ = newComps;
                    return *this;
                }

                //}
                //----------------------------------------------------------------------------

                //----------------------------------------------------------------------------
                //{ Swaps array
                //----------------------------------------------------------------------------

                Point* SortingAlgorithm::getSwaps () const
                {
                    assert (ok ());
                    return swaps_;
                }

                SortingAlgorithm& SortingAlgorithm::setSwaps (Point* newSwaps)
                {
                    assert (ok ());
                    swaps_ = newSwaps;
                    return *this;
                }

                //}
                //----------------------------------------------------------------------------

                //----------------------------------------------------------------------------
                //{ Time array
                //----------------------------------------------------------------------------

                Point* SortingAlgorithm::getTime () const
                {
                    assert (ok ());
                    return time_;
                }

                SortingAlgorithm& SortingAlgorithm::setTime (Point* newTime)
                {
                    assert (ok ());
                    time_ = newTime;
                    return *this;
                }

                //}
                //-----------------------------------------------------------------------------

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ Number of button in button array
            //----------------------------------------------------------------------------

            int SortingAlgorithm::getButtonNumber () const
            {
                assert (ok ());
                return buttonNumber_;
            }

            //}
            //----------------------------------------------------------------------------


            //----------------------------------------------------------------------------
            //{ GraphicDrawn
            //----------------------------------------------------------------------------

            Mode SortingAlgorithm::getGraphicDrawn () const
            {
                assert (ok ());
                return graphicDrawn_;
            }

            SortingAlgorithm& SortingAlgorithm::setGraphicDrawn (Mode newGraphicDrawn)
            {
                assert (ok ());
                graphicDrawn_ = newGraphicDrawn;
                return *this;
            }

            //}
            //----------------------------------------------------------------------------

        //}
        //----------------------------------------------------------------------------


        //----------------------------------------------------------------------------
        //{ Functions
        //----------------------------------------------------------------------------

            bool SortingAlgorithm::ok () const
            {
                bool everythingOk = true;

                if (!sortFunc_)
                {
                    everythingOk = false;
                    puts ("Sorting function is empty.");
                }

                if (!color_.ok ()) everythingOk = false;

                if (!comps_)
                {
                    everythingOk = false;
                    puts ("Comparisons array is empty.");
                }
                if (!swaps_)
                {
                    everythingOk = false;
                    puts ("Swaps array is empty.");
                }

                if (! time_)
                {
                    everythingOk = false;
                    puts ("Time array is empty.");
                }

                if (0 > buttonNumber_)
                {
                    everythingOk = false;
                    puts ("Button's number is negative.");
                }

                return everythingOk;
            }

        //}
        //----------------------------------------------------------------------------

    //}
    //----------------------------------------------------------------------------


//}
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
//{ Prototypes
//----------------------------------------------------------------------------


    //----------------------------------------------------------------------------
    //{ Calculations
    //----------------------------------------------------------------------------

    void calculations (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                                 Button  buttonArray[], int  buttonArraySize,  Mode* mode, Mode* updateGraphic);
    // Does all the calculations in this programm

    void calcGraphic (SortingAlgorithm sortAlg);
    // Fills arrays with points of future graphic

    void distributeButtons (Button buttonArray[], int buttonArraySize, int buttonCount, Point LTPoint, Point RBPoint);
    // Gives the coordinates to buttons (from 0 to buttonCount) in buttonArray.

    //}
    //----------------------------------------------------------------------------


    //----------------------------------------------------------------------------
    //{ Rendering
    //----------------------------------------------------------------------------

    void rendering (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                              Button  buttonArray[], int  buttonArraySize, Mode mode);
    // Renders almost everything in this programm.

    void drawGraphic (SortingAlgorithm sortAlg, Mode mode);
    // Renders the whole graphic.

    void drawButtons (SortingAlgorithm sortAlgArray[], int sortAlgArraySize,
                                Button  buttonArray[], int  buttonArraySize);
    // Renders sorting algorithms' buttons (from 0 to sortAlgArraySize).

    //}
    //-----------------------------------------------------------------------------


    //----------------------------------------------------------------------------
    //{ Sorting algorithms
    //----------------------------------------------------------------------------

    Counters          bubbleSort (int array[], int arraySize);
    Counters       selectionSort (int array[], int arraySize);
    Counters       insertionSort (int array[], int arraySize);
    Counters binaryInsertionSort (int array[], int arraySize);

    //}
    //-----------------------------------------------------------------------------


    //----------------------------------------------------------------------------
    //{ Additional functions
    //----------------------------------------------------------------------------


    void swapVars (int* varA, int* varB);
    // It really swaps two variables'values.

    void fillArray (int array[], int arraySize, bool fillRand);
    // If fillRand is true fills the array with random values, else fills with zeroes.

    int  find (int array[], int arraySize, int toFind, int foundEventNumber, int startIndex, int finishIndex);
    // Returns an index of the (foundEventNumber)th value, which is equal to toFind. Searches in an interval [0;finishIndex].

    int  findMin (int array[], int arraySize, int startIndex, int finishIndex, int* compareCount);
    // Returns the index of smallest value in an interval [startIndex, finishIndex].
    // Also changes compareCount to the count of compares done.

    int  findInsertIndex (int array[], int arraySize, int orderedPart, int* compareCount);
    // Finds an index in sorted array, where should array[orderedPart] be.

    int  findInsertIndexBinary (int array[], int arraySize, int orderedPart, int* compareCount);
    // Finds an index in sorted array, where should array[orderedPart] be, using binary search.

    void rotateRight (int array[], int arraySize, int leftBorder, int rightBorder, int* swapCount);
    // Rotates all elements right.

    //}
    //----------------------------------------------------------------------------


//}
//----------------------------------------------------------------------------

#endif


