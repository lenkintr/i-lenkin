#include "TXLib.h"
//const double S = 600;
struct XY
{
  double sizeX;
  double sizeY;
  double baisX = 0;
  double baisY = 0;
  double Ox;
  double Oy;
  double step;
void DrawOxy (COLORREF color);
void DrawAll (COLORREF color);
void DrawTextOx (COLORREF color, int startX, int step);
void DrawTextOy (COLORREF color, int startY, int stepY);
};
void drawXY(XY This, COLORREF OxyColor, COLORREF allColor, COLORREF textColor,  int startX, int step, int startY, int stepY);


/*int main()
{
    XY print;
    print.sizeX = 500;
    print.sizeY = 600;
    print.baisX = baisY;
    print.Ox    = sizeX / 25;
    print.Oy    =  9 * sizeY / 10;
    print.step  =  50;
    drawXY(print, TX_RED, TX_BLUE, TX_GREY, 20, 10, 100, 100);
    dXY (500, 500, 100, 400, 50, TX_RED, TX_BLUE, TX_GREEN);

return 0;
}*/

void drawXY(XY This, COLORREF OxyColor, COLORREF allColor, COLORREF textColor,  int startX, int step, int startY, int stepY)
{

    This.DrawOxy(OxyColor);
    This.DrawAll(allColor);
    This.DrawTextOx (textColor, startX, step);
    This.DrawTextOy (textColor, startY, stepY);
}

    void  XY :: DrawOxy (COLORREF color)
{
  txSetColor (color, 2);
  txLine (Ox + baisX, 0  + baisY, Ox + baisX, sizeY  + baisY);
  txLine (0  + baisX, Oy + baisY, sizeX + baisX, Oy + baisY);
  txSetColor (color, 1);
  txDrawText (Ox - 10 + baisX, Oy + baisY, Ox + baisX, Oy + 13 + baisY, "0");
}

void XY :: DrawAll (COLORREF color)
{
  txSetColor (color, 0.5);
  double i = Ox + baisX ;
  while (i <= sizeX + baisX)
  {
  txLine (i, 0  + baisY, i, sizeY  + baisY);
  i += step;
  }

  i = Ox + baisX ;
  while (i >= baisX)
  {
  txLine (i, 0  + baisY, i, sizeY  + baisY);
  i -= step;
  }

  double j = Oy + baisY;
  while (j >= baisY)
  {
      txLine (0  + baisX, j, sizeX + baisX, j);
      j -= step;
  }
  j = Oy + baisY;
  while (j <= sizeY  + baisY)
  {
      txLine (0  + baisX, j, sizeX + baisX, j);
      j += step;
  }

}

void XY :: DrawTextOx (COLORREF color, int startX, int stepX)
{
  char st[4];
  int sX = -startX;
  double i = Ox + baisX + step / 2;
 while (i < sizeX + baisX)
  {
      sprintf(st, "%d", startX);
      txSetColor (color, 1);
      txTextOut (i, Oy + baisY, st);
      i += step;
      startX += stepX;
  }

  i = Ox + baisX - 1.5* step;
if (i >= baisX )
  {
      sprintf(st, "%d", sX);
      txSetColor (color, 1);
      txTextOut (i, Oy + baisY, st);
      i -= step;
      sX -= stepX;
  }
}

void XY :: DrawTextOy (COLORREF color, int startY, int stepY)
{
  char st[4];
  int sY = -startY;
  double i = Oy + baisY - step;

  while (i > 0)
  {
      sprintf(st, "%d", startY);
      txSetColor (color, 1);
      txTextOut (Ox + baisX, i, st);
      i -= step;
      startY += stepY;
  }

  i = Oy + baisY + 2 * step / 3;
 while (i < sizeY  + baisY)
  {
      sprintf(st, "%d", sY);
      txSetColor (color, 1);
      txTextOut (Ox + baisX - 7, i, st);
      i += step;
      sY -= stepY;
  }
}
