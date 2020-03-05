#include "TXLib.h"
const int SIN = 1,
           SQR = 2;

void Graphic(int func, COLORREF color);
double Sqr (double x);

int main()
{
  txCreateWindow(800, 600);
  Graphic (1, TX_LIGHTGREEN);
  Graphic(2, TX_LIGHTRED);
}

void Graphic(int func, COLORREF color)
{
    txSetColor (color);
    txSetFillColor (color);
    double x = -20;
    while (x <= +20)
    {
        double y = 0;
        switch (func)
        {
            case SIN: { y = Sqr (x); break;}
            case SQR: { y = sin (x); break;}
        }

        txCircle (800 / 2 + 50 * x, 600 / 2 - 50 * y, 2);
        x += 0.1;
    }

}

double Sqr (double x) { return x *x; }
