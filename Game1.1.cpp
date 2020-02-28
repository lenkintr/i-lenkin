#include "TXLib.h"
#include "TXMult.h"
//#include <iostream>
struct ball
{
    int x, y;
    int vx; int vy;
    int red; int green; int blue;
    int shadow; int gradient;
    bool catchBall;
};
void First_Game(int sizeX, int sizeY);
void Physics (int sizeX, int sizeY,  ball *b);
void Control(ball *b);
void Draw_ball(int sizeX, int sizeY, ball *b);
double Distance (double x1, double y1, double x2, double y2);


int main()
  {
      txCreateWindow (800, 600);
      txBegin();
      First_Game(800, 600);
      txEnd();
  }

void First_Game(int sizeX, int sizeY)
  {
      srand (time (0));
      int n = 24;
      ball Myball[n];

      for (int i = 0; i < n; i++)
      {
        //$(i);??????
        //assert(0 <= i && i < 4);!!!!!!!!!!!!!!!!!

        Myball[i].x  = rand() % sizeX,  Myball[i].y  = rand() % sizeY;
        Myball[i].vx = rand() % 10, Myball[i].vy = rand() % 10;
        Myball[i].red = rand() % 256;
        Myball[i].green = rand() % 256;
        Myball[i].blue = rand() % 256;
        Myball[i].gradient = -1;
        Myball[i].shadow = 2;
        Myball[i].catchBall = false;
     }
     int k = 0;
     int xh = 40;
     while (!txGetAsyncKeyState (VK_ESCAPE))
          {

          txClear();

          Draw_Hedgehog(xh, sizeY - 10,5,0,true);
          if (txGetAsyncKeyState ('N')) xh +=5;
          if (txGetAsyncKeyState ('B')) xh -=5;

          for (int i = 0; i < n; i++)
          {

              if (!Myball[i].catchBall)
               {
                   Draw_ball(800, 600, &Myball[i]);
                   Physics (sizeX, sizeY, &Myball[i]);
               }
               else
               {
                   Myball[i].x = xh;
                   Myball[i].y = sizeY - 35;
                   Draw_ball(800, 600, &Myball[i]);
               }
              Control(&Myball[i]);

              //txSetFillColor (TX_PINK);
              //txCircle (xh - 50, sizeY - 10, 5);
              if (!Myball[i].catchBall)
              {
                  double distHedg = Distance (Myball[i].x, Myball[i].y, xh, sizeY - 10);
                  if (distHedg <= 40)
                    {

                        //Myball[i].x = xh;  Myball[i].y = sizeY - 35;
                       // Myball[i].vx = 0;
                        //Myball[i].vy = 0;
                        Myball[i].catchBall = true;
                        k ++;

                    }
              }
              for (int j = 0; j < n; j ++)
              {
                double dist = Distance (Myball[i].x, Myball[i].y, Myball[j].x, Myball[j].y);
                if (dist <= 20 + 20 && i != j && !Myball[j].catchBall)
                    {
                       std:: swap(Myball[i].vx, Myball[j].vx);
                       std:: swap(Myball[i].vy, Myball[j].vy);

                    }
              }
          }
          if (xh >= sizeX) xh = 10;

          if (k == n)
            {
                txSetColor (RGB (255, 0 , 0));
                txSelectFont ("Times New Roman", 50, 30, true, true);
                txDrawText  (sizeX / 4, sizeY / 3,  sizeX , 2 * sizeY / 3, "Win!..ή-υσσσσ");
                txSleep(100);
                break;
            }
          txSetFillColor (TX_WHITE);
          txSetColor (RGB (255, 255 , 0));
          txSelectFont ("Times New Roman", 30, 20, true, true);
          char st[12];
          sprintf(st, "%d", k);
          txDrawText  (sizeX /300, sizeY / 300, 3 * sizeX / 10, 2 * sizeY / 10, "count: ");
          txDrawText  (sizeX /300 + 70, sizeY / 300, 3 * sizeX / 10 + 70, 2 * sizeY / 10, st);

          txSleep (15);
        }
  }
void Physics (int sizeX, int sizeY, ball *b)
{
      int ax = 0, ay = 1;
      int dt = 1;
      (*b).vx += ax * dt;
      (*b).vy += ay * dt;

      (*b).x += (*b).vx * dt;
      (*b).y += (*b).vy * dt;

      if ((*b).x > sizeX)
        {(*b).vx = -(*b).vx; (*b).x = sizeX;} // (*b).vx   === s ->x
      if (b -> x < 0)
        {b -> vx = -(*b).vx; b -> x = 0;}
      if (b -> y > sizeY)
        {b -> vy = -(*b).vy; b -> y = sizeY;}
      if (b -> y < 0)
        {b -> vy = -(*b).vy; b -> y = 0;}

}
void Control (ball *b)
{

      if (txGetAsyncKeyState (VK_LEFT))  -- b -> vx;
      if (txGetAsyncKeyState (VK_RIGHT)) ++ b -> vx;
      if (txGetAsyncKeyState (VK_UP))    -- b -> vy;
      if (txGetAsyncKeyState (VK_DOWN))  ++ b -> vy;
      if (txGetAsyncKeyState (VK_SPACE)) {b -> vx = 0; b -> vy = 0;}
}
void Draw_ball(int sizeX, int sizeY, ball *b)
{
      bool f = false;
      if ((*b).x == 0 || (*b).x == sizeX) {(*b).shadow = - (*b).shadow;}
      if ((*b).x == 0 || (*b).x == sizeX || (*b).y == 0 || (*b).y == sizeY) {f = true;}

      txSetFillColor (RGB ((*b).red / 3, (*b).green / 3, (*b).blue / 3));
      txCircle ((double) (*b).x - (*b).shadow, (double) (*b).y - (*b).shadow, 20.);
      txSetFillColor (RGB ((*b).red / 4, (*b).green / 4, (*b).blue / 4));
      txCircle ((double) (*b).x - (*b).shadow * 2, (double) (*b).y - (*b).shadow * 2, 20.);
      txSetColor     (RGB ((*b).red / 2, (*b).green / 2, (*b).blue / 2));
      txSetFillColor (RGB ((*b).red += (*b).gradient, (*b).green += (*b).gradient, (*b).blue += (*b).gradient));
      if ((*b).red == 255 || (*b).red == 0 || (*b).green == 255 || (*b).green == 0 || (*b).blue == 250 || (*b).blue == 0 ) (*b).gradient = -(*b).gradient;
      txCircle ((*b).x, (*b).y, 20);
      if (f)
        {
            COLORREF color = RGB (rand() % 256, rand() % 256, rand() % 256);
            (*b).red = txExtractColor(color, TX_RED);
            (*b).green = txExtractColor(color, TX_GREEN);
            (*b).blue = txExtractColor(color, TX_BLUE);
            f = false;
        }
}
double Distance (double x1, double y1, double x2, double y2)
{
    double dist = sqrt( (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return dist;
}
