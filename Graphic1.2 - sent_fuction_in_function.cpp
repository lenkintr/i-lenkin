// ----------
// Передача функции в качестве параметра
//----------
#include "TXLib.h"

void Graphic( double (*func) (double x), COLORREF color);
double Sqr (double x);
double Sin (double x);


int main()
{
  txCreateWindow(800, 600);
  Graphic (&Sin, TX_LIGHTGREEN);
  Graphic(&Sqr, TX_LIGHTRED);
}

void Graphic( double (*func) (double x), COLORREF color) //в скобках что передаем в функцию , вместо типа - тип возвращаемых данных (из прототипа); (*func) - указываем на адрес функции
{
    txSetColor (color);
    txSetFillColor (color);
    double x = -20;
    while (x <= +20)
    {
        double y = (*func) (x); // т.к. сначала скобки -> потом функция (* - адрес)

        txCircle (800 / 2 + 50 * x, 600 / 2 - 50 * y, 2);
        x += 0.1;
    }

}

double Sqr (double x) { return x *x; }

double Sin (double x) { return sin (x); }
