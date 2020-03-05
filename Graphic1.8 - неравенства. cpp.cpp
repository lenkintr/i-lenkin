// ----------
// Передача функции в качестве параметра
//----------
#include "TXLib.h"


void DrawParabola();
void DrawCircle(double x0, double y0, COLORREF color, int xx, int yy);
void DrawTR(double x0, double y0, COLORREF color, int xx, int yy);
void DrawT(double x0, double y0, COLORREF color, int xx, int yy);
void DrawS(double x0, double y0, COLORREF color, int xx, int yy);
void DrawS1(double x0, double y0, COLORREF color, int xx, int yy);
int main()
{
  txCreateWindow(800, 600);
  txBegin();

  DrawTR(-2, +2, TX_LIGHTRED, 1, 1);
  DrawS(-2, 0, TX_LIGHTRED, 1, 1);
  DrawCircle(0, 4, TX_GREEN, 1, 1);
  DrawT(0, 0.5, TX_GREEN, 1, 0);
  DrawS1(-2, +2, TX_YELLOW, 1, 1);
  txEnd();

}


void DrawTR(double x0, double y0, COLORREF color, int xx, int yy)
{

   for ( double y = -10; y <= +10; y += 0.04)
   for ( double x = -10; x <= +10; x += 0.04)
   {
      if (y < x - 0.5  && y < - x - 0.5  && y > -4)
        txSetPixel (400 + 50 * x + xx, 300 - 50 * y + yy, color);
   }


}
void DrawT(double x0, double y0, COLORREF color, int xx, int yy)
{
   for ( double y = -10; y <= +10; y += 0.04)
   for ( double x = -10; x <= +10; x += 0.04)
   {
      if ( x * x + (y - y0) * (y - y0) < 6)
        txSetPixel (400 + 50 * x + xx, 300 - 50 * y + yy, color);
   }
}

void DrawCircle(double x0, double y0, COLORREF color, int xx, int yy)
{

   for ( double y = -10; y <= +10; y += 0.04)
   for ( double x = -10; x <= +10; x += 0.04)
   {
      if ((y - y0) * (y - y0) + (x - x0) * (x - x0) < 2)
      txSetPixel (800 / 2 + 50 * x + xx, 600 / 2 - 50 * y + yy, color);
   }


}

void DrawS(double x0, double y0, COLORREF color, int xx, int yy)
{
   for ( double y = -10; y <= +10; y += 0.04)
   for ( double x = -10; x <= +10; x += 0.04)
   {
      if ((y < - 0.6 * x + 2 && (x + 9) * (x + 9)+ (y - 2.3) * (y - 2.3) > 18.5 && y > -1.5) || ( y < 0.6 * x + 2  && (x - 9) * (x - 9)+ (y - 2.3) * (y - 2.3) > 18.5) && y > -1.5)
        txSetPixel (800 / 2 + 50 * x + xx, 600 / 2 - 50 * y + yy, color);
   }


}

void DrawS1(double x0, double y0, COLORREF color, int xx, int yy)
{
   for ( double y = -10; y <= +10; y += 0.04)
   for ( double x = -10; x <= +10; x += 0.04)
   {
      if ( y< 4.3 && x > 0 && 0.2*x + 3.8 < y)
        txSetPixel (800 / 2 + 50 * x + xx, 600 / 2 - 50 * y + yy, color);
      if ( (x + 0.7)*(x + 0.7) + (y - 4.5) * (y - 4.5) < 0.02)
        txSetPixel (800 / 2 + 50 * x + xx, 600 / 2 - 50 * y + yy, color);
      if ( (x - 0.7)*(x - 0.7) + (y - 4.5) * (y - 4.5) < 0.02)
        txSetPixel (800 / 2 + 50 * x + xx, 600 / 2 - 50 * y + yy, color);
   }
}
