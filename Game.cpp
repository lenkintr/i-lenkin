#include "TXLib.h"
void First_Game(int sizeX, int sizeY);
void Physics (int sizeX, int sizeY, int *x, int *y, int *vx, int *vy);
void Control(int *vx, int *vy);
int main()
  {
      txCreateWindow (800, 600);

      First_Game(800, 600);
  }

void First_Game(int sizeX, int sizeY)
  {
      int x  = rand() % sizeX, y  = rand() % sizeY;
      int vx = 1, vy = 1;
      int cl = -1;
      int shadow = 3;

      COLORREF color;
      int red = rand() % 256;
      int green = rand() % 256;
      int blue = rand() % 256;
      bool f = false;
      while (!txGetAsyncKeyState (VK_ESCAPE))
          {
          txSetFillColor (RGB (red / 3, green / 3, blue / 3));
          txCircle ((double) x - shadow, (double) y - shadow, 20.);
          //txClear();
          txSetColor     (RGB (red / 2, green / 2, blue / 2));
          txSetFillColor (RGB (red += cl, green += cl, blue += cl));
          if (red == 255 || red == 0 || green == 255 || green == 0 || blue == 250 || blue == 0 ) cl = -cl;
          txCircle ((double) x, (double) y, 20.);
          if (f)
            {
                color = RGB (rand() % 256, rand() % 256, rand() % 256);
                red = txExtractColor(color, TX_RED);
                green = txExtractColor(color, TX_GREEN);
                blue = txExtractColor(color, TX_BLUE);
                f = false;
            }

          Physics (sizeX, sizeY, &x, &y, &vx, &vy);

          if (x == 0 || x == sizeX) {shadow = - shadow;}
          if (x == 0 || x == sizeX || y == 0 || y == sizeY) {f = true;}
          Control(&vx, &vy);
          txSleep (15);
        }
  }
void Physics (int sizeX, int sizeY, int *x, int *y, int *vx, int *vy)
{
      bool f = false;
      int ax = 0, ay = 1;
      int dt = 1;
      *vx += ax * dt;
      *vy += ay * dt;

      *x += *vx * dt;
      *y += *vy * dt;

      if (*x > sizeX)
        {*vx = -*vx; *x = sizeX;}
      if (*x < 0)
        {*vx = -*vx; *x = 0;}
      if (*y > sizeY)
        {*vy = -*vy; *y = sizeY;}
      if (*y < 0)
        {*vy = -*vy; *y = 0;}

}
void Control (int *vx, int *vy)
{

      if (txGetAsyncKeyState (VK_LEFT))  -- *vx;
      if (txGetAsyncKeyState (VK_RIGHT)) ++ *vx;
      if (txGetAsyncKeyState (VK_UP))    -- *vy;
      if (txGetAsyncKeyState (VK_DOWN))  ++ *vy;
      if (txGetAsyncKeyState (VK_SPACE)) {*vx = 0; *vy = 0;}
}
