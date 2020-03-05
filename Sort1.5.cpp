#include "TXLib.h"
#include "Oxy.cpp"
const int sizeX = 1000;
const int sizeY = 600;
const int buttonHight = 190;
const int buttonWeight = 40;

struct Button
{
    int x, y;
    COLORREF color;
    char st[15];

void Draw();
bool MouseClick();
};

struct graphStat
{
    int countChange;
    int countIt;
};
typedef graphStat nowSort (int arr[], int sizeArr);

void InputArray (int *arr,int sizeArr);
void ArrayShuffle (int *arr,int sizeArr);
int SelectMenu (int NumberButton);
bool Menu (int sizeX, int sizeY, bool *doMenu);
void DrawMenu ();
int SelectButton (Button button[], int countButton);
graphStat Bsort (int arr[], int sizeArr);
graphStat Ssort (int arr[], int sizeArr);
graphStat Isort (int arr[], int sizeArr);
graphStat Msort (int arr[], int sizeArr);
void PrintStat (nowSort* thisSort, COLORREF color);
void DrawGraph(int countIt,int n, COLORREF color, int x0, int y0);
void mySwap(int *first, int *second);
void DrawPicture (double baisX, double baisY);

main ()
{
    srand(time(NULL));

    txCreateWindow (sizeX, sizeY);

    txBegin();
    txSetFillColor(TX_WHITE);
    txClear();
    bool doMenu = true;
    while (Menu (sizeX, sizeY, &doMenu) == true) {}
    txEnd();

}

void InputArray (int *arr,int sizeArr)
{

   for (int i = 0; i < sizeArr; i++)
    {
       assert(0 <= i && i < sizeArr);
       arr[i] = 5 * i;

    }
}

void ArrayShuffle (int *arr,int sizeArr)
{
  for (int i = 0; i < sizeArr - 1; i++)
  {
        assert(0 <= i && i < sizeArr);
        assert(0 <= i && (i + 1 + rand() % (sizeArr - i - 1)) < sizeArr);
        mySwap (&arr[i], &arr[i + 1 + rand() % (sizeArr - i - 1)]);
  }
}

int SelectMenu (int NumberButton)
{ int res = 4;
switch (NumberButton)
    {
     case 0: { PrintStat(&Bsort, TX_BLUE); break;}
     case 1: { PrintStat(&Ssort, TX_RED); break;}
     case 2: { PrintStat(&Isort, TX_GREEN); break;}
     case 3: { PrintStat(&Msort, RGB(255, 255, 0)); break;}
     case 4: {res = 5; txSetFillColor(TX_WHITE); txClear(); break;}
     default: {/*$("ERROR: ")*/};
    }
   return res;
}

bool Menu (int sizeX, int sizeY,bool *doMenu)
{
    txSetFillColor(TX_WHITE);

    if (*doMenu == true)
    {
        DrawPicture (0, 0);
        DrawPicture (500, 0);
        DrawMenu();
    }
    Button buttons[5] = {{sizeX / 150, sizeY / 100, TX_BLUE, "Bubble"},
                         {sizeX / 150 + buttonHight + 10, sizeY / 100, TX_RED, "Selection"},
                         {sizeX / 150 + (buttonHight + 10) * 2, sizeY / 100, TX_GREEN, "Insertion"},
                         {sizeX / 150 + (buttonHight + 10) * 3, sizeY / 100,  TX_YELLOW, "Merge"},
                         {sizeX / 150 + (buttonHight + 10) * 4, sizeY / 100, TX_BLACK, "Restart"},
                         };

    for (int NumbButt = 0; NumbButt < 5; NumbButt ++)
    {
        buttons[NumbButt].Draw();
    }
    int it = SelectButton (buttons, 5);
    bool esc = txGetAsyncKeyState(VK_ESCAPE);

    if ( esc )     { return false;}

    int Iit = SelectMenu(it);
    if ( Iit == 4) {*doMenu = false;}
    if ( Iit == 5) { *doMenu = true;}

    txSleep (5);
    return true;

}

void Button :: Draw()
{
    txSetFillColor (RGB(151, 232, 234));
    txSetColor     (RGB(56, 209, 214));
    txRectangle    (this -> x, this -> y, this -> x + buttonHight , this -> y + buttonWeight);
    txSetColor     (color);
    txSelectFont   ("Times New Roman", 20, 0, true, true);
    txDrawText     (this -> x,this -> y, this -> x + buttonHight , this -> y + buttonWeight, this -> st);
}

bool Button :: MouseClick()
{
 bool inButton = (txMousePos().x >= this -> x && txMousePos().x <= (this -> x + buttonHight) && txMousePos().y >= this -> y && txMousePos().y <= (this -> y + buttonWeight));

 if (inButton &&  txMouseButtons () == 1) {return true;}
    else return false;
}

int SelectButton (Button button[], int countButton)
{
    int res = -1;

    for (int i = 0; i <  countButton; i ++)
    {
      assert(0 <= i && i < countButton);
      if  (button[i].MouseClick()) res = i;
    }

    //$(res);
    return res;
}

graphStat Bsort (int arr[], int sizeArr)
{
    graphStat res = {0, 0};
    //bool flag = true;
   // while (flag)
    for (int j = 0; j < sizeArr; j ++)
    {
       assert(0 <= j && j < sizeArr);
       for(int i = sizeArr - 1; i > 0; i--)
            {
                assert(0 <= i && i < sizeArr);
                //flag = false;
                if( arr[i] < arr[ i- 1])
                {
                    mySwap(&arr[i], &arr[i - 1]);
                    ++ (res.countChange);
                    //flag = true;
                }

                res.countIt ++;
            }
    }

     return res;
}

graphStat Ssort (int arr[], int sizeArr)
{
 graphStat res = {0, 0};

 for (int i = 0; i < sizeArr -1; i++)
 {
     int n_min = i;
     assert(0 <= i && i < sizeArr);
     for (int j = i + 1; j < sizeArr; j ++)
     {
        assert(0 <= j && j < sizeArr);
        if (arr[j] < arr[n_min]) {n_min = j;}
        res.countIt ++;
     }
     if (n_min != i) { mySwap(&arr[i], &arr[n_min]); ++ res.countChange;}
 }

 return res;
}

graphStat Isort (int arr[], int sizeArr)
{
  graphStat res = {0, 0};
  int key = 0;
  int i = 0;

  for(int j = 1; j < sizeArr; j++)
    {
        assert(0 <= j && j < sizeArr);
        key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key)
            {
              assert(0 <= i && i < sizeArr);
              arr[i+1] = arr[i];
              i --;
              arr[i+1] = key;
              ++ res.countChange;
            res.countIt ++;
            }
        res.countIt ++;
    }
   return res;
  }

graphStat Msort (int arr[],  int sizeArr)
{
///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  graphStat res = {0, 0};
  int mid = sizeArr / 2;
  if (sizeArr % 2 == 1) { mid++; }
  int h = 1;

  int c [sizeArr];

  int step;
  while (h < sizeArr)
  {
    step = h;
    int i = 0;
    int j = mid;
    int k = 0;
    while (step <= mid)
    {
      assert(0 <= i && i < sizeArr);
      while ((i < step) && (j < sizeArr) && (j < (mid + step)))
      {
        assert(0 <= i && i < sizeArr);
        assert(0 <= j && j < sizeArr);
        if (arr[i] < arr[j])
        {
          c[k] = arr[i];
          i++; k++;
        }
        else
        {
          c[k] = arr[j];
          j++; k++;
        }
        res.countIt ++;
      }
      while (i < step)
      {
        assert(0 <= i && i < sizeArr);
        c[k] = arr[i];
        i++; k++;
        res.countIt ++;
      }
      while ((j < (mid + step)) && (j < sizeArr))
      {
        assert(0 <= j && j < sizeArr);
        c[k] = arr[j];
        j++; k++;
        res.countIt ++;
      }
      step = step + h;
    }
    h = h * 2;
    for (i = 0; i < sizeArr; i++)
     {
       assert(0 <= i && i < sizeArr);
       arr[i] = c[i];
       ++ res.countChange;
       res.countIt ++;
     }
   }

 return res;
}

void PrintStat (nowSort* thisSort, COLORREF color)
{
    txBegin();

    int n = 20;
    bool doDraw = true;

    while (n < 1130 && doDraw)
    {
        int countChange = 0;
        int mas [n]; // = {0};

        InputArray   (mas, n);
        ArrayShuffle (mas, n);

        graphStat stat = (*thisSort) (mas, n);

        double y = sizeY - 100 - stat.countIt / 1000;
        if (y > sizeY / 12)
            {
                DrawGraph (stat.countIt,     n, color, 50, 5);
                DrawGraph (stat.countChange, n, color, 550, 1);
            }
        else
            doDraw = false;

        txSleep(0);
        //$ (countIt);

        n += 10;
    }
    txEnd();
}

void DrawGraph(int countIt,int n, COLORREF color, int x0, int y0)
{
    txSetFillColor(color);
    txSetColor(color);
    txCircle( n / y0 + x0, sizeY - 100 - countIt / 1000, 3);
}

void DrawMenu ()
{
    txSetFillColor(RGB(128, 255, 128));
    txSetColor(RGB(36, 255, 36));
    txRectangle(0, 0, sizeX, sizeY/12);
}

void mySwap(int *first, int *second)
{
    *first += *second;
    *second = *first - *second;
    *first -= *second;
}

void DrawPicture ( double baisX, double baisY)
{
    XY print;
    print.sizeX = sizeX / 2 - 25;
    print.sizeY = sizeY;
    print.baisX = baisX;
    print.baisY = baisY;
    print.Ox    = sizeX / 25;
    print.Oy    =  9 * sizeY / 10;
    print.step  =  50;
    drawXY(print, TX_RED, TX_BLUE, TX_GREY, 20, 10, 100, 100);
}
