#include "TXLib.h"
const int SIZEX = 800,
           SIZEY = 600;
struct myHeroes
{
    int countLife;
    int x; int y;
    int anim;
    int cX; int cY;

    void Move(HDC heroImage, int t);
    void player1_Control ();
    void player2_Control ();
    void Draw_life(int playerNumber);
    bool Lose (int player);
    bool Win(HDC backImage, int player);
};

struct wall
{
   int x; int y;
   int speed;

   void DataInput (int number);
   void Draw ();
   void Move ();
};


void Meeting (wall thisWall, myHeroes *thisHero, int player);

void Game_Over ();
int main()
{
    txCreateWindow(SIZEX, SIZEY);
    txBegin();

    HDC mapImage = txLoadImage("fon.bmp");
   // if (mapImage == 0) txMessageBox ("fon.bmp NOT found");

    HDC backImage = txLoadImage("Background.bmp");
    HDC heroImage = txLoadImage("bird.bmp");
    HDC resetImage = txLoadImage("reset.bmp");

  tryAgain:
    const int n = 7;
    wall myWall[n];
    for (int i = 0; i < n; i++)
    {
        myWall[i].DataInput(i);
    }

    myHeroes bird[2];

    bird[0].x = SIZEX / 8, bird[0].y = 70;
    bird[0].anim = 0; bird[0].countLife = 3;

    bird[1].x = 5 * SIZEY / 8, bird[1].y = 70;
    bird[1].anim = 1; bird[1].countLife = 3;

    for (int t = 0; !txGetAsyncKeyState (VK_ESCAPE); t++ )
    {

        txClear ();
        txBitBlt (txDC(), -100, -100, 0, 0, mapImage);

        bird[0].Draw_life (1);
        bird[1].Draw_life (2);

        bool life1 = bird[0].Lose(1);
        bool life2 = bird[1].Lose(2);

        if (life1)
        {
          bird[0].player1_Control ();
          bird[0].Move (heroImage, t);
        }

        if(life2)
        {
            bird[1].player2_Control ();
            bird[1].Move (heroImage, t);
        }

        bool win1 = bird[0].Win (backImage, 1);
        bool win2 = bird[1].Win (backImage, 2);

        if ( win1 && bird[0].countLife > 0) {txSleep(500); break;}
        if ( win2 && bird[0].countLife > 0) {txSleep(500); break;}

        for (int i = 0; i < n; i++)
        {
            myWall[i].Draw();
            myWall[i].Move();
            Meeting (myWall[i], &bird[0], 1);
            Meeting (myWall[i], &bird[1], 2);
        }

        if (!life1 && !life2)
        {
            Game_Over();
            COLORREF color = txGetPixel (txMouseX(), txMouseY(), backImage);

            if (color != RGB (0, 0, 255) || txMouseButtons() != 1)
            {
            txTransparentBlt(txDC(), 3 * SIZEX / 8 , 250, 0, 0, resetImage,
            0, 0, RGB (0, 0, 255));
             }
             else
             {
                 goto tryAgain;
             }

        }

        txSleep (20);
    }
    txEnd();
    txDeleteDC (heroImage);
    txDeleteDC (mapImage);
    txDeleteDC (backImage);
}

void myHeroes :: Move(HDC heroImage, int t)
{
    int frameX = 7, frameY = 3;
    int frameSizeX = txGetExtentX (heroImage) / frameX;
    int frameSizeY = txGetExtentY (heroImage) / frameY;
    this -> cX = this -> x + frameSizeX / 2;
    this -> cY = this -> y + frameSizeY / 2;

    txTransparentBlt(txDC(), x, y, frameSizeX, frameSizeY, heroImage,
     frameSizeX * (t % frameX), this -> anim * frameSizeY, RGB (255, 0, 255));
}

void myHeroes :: player1_Control ()
{

        if (GetAsyncKeyState(VK_RIGHT))
            {
                this -> x +=5; this -> anim = 0;
            }
        if (GetAsyncKeyState(VK_LEFT))
            {
                this -> x -=5; this -> anim = 1;
            }
        if (GetAsyncKeyState(VK_UP)) this -> y -=5;
        if (GetAsyncKeyState(VK_DOWN)) this -> y +=5;
}

void myHeroes :: player2_Control ()
{
        if (GetAsyncKeyState('A'))
            {
                this -> x -=5; this -> anim = 1;
            }
        if (GetAsyncKeyState('D'))
            {
                this -> x +=5; this -> anim = 0;
            }
        if (GetAsyncKeyState('W')) this -> y -=5;
        if (GetAsyncKeyState('S')) this -> y +=5;
}

void wall :: Draw ()
{
    txSetColor (TX_BLACK);
    txSetFillColor (TX_BROWN);
    txRectangle(x, y, x + 80, y + 10);
    this -> x += speed; // vse ravno chto prosto x
    //if (*x >= 520 || *x <= 0) *x = 0;
}

void wall :: Move ()
{
    if ((x >= SIZEX - 80) || x <= 0) speed = - speed;
}

void myHeroes :: Draw_life(int playerNumber)
{
     int ay = 0;// local var
     if (playerNumber == 2 ) ay = 30;
     txSetColor (RGB (255, 255 , 0));
     txSelectFont ("Times New Roman", 20, 10, true, true);
     char st[2];
     txDrawText  (0, 0 + ay, 100, 50,"Player ");
     sprintf(st, "%d", playerNumber);
     st[1] = ':';
     txDrawText  (0, 0 + ay, 180, 50, st);
     sprintf(st, "%d", this -> countLife);
     txDrawText  (0, 0 + ay, 250, 50, st);
}

double Distance(int xwall, int ywall, int xhero, int yhero)
{
    //$$$$
    double dist = sqrt (((xwall + 40) - xhero) * ((xwall + 40) - xhero) + (ywall - yhero) * (ywall - yhero));
    //$$$$
    return dist;
}

void Meeting (wall thisWall, myHeroes *thisHero, int player)
{
    double dist = Distance (thisWall.x, thisWall.y, (*thisHero).cX, (*thisHero).cY);
    //$$$$
    if (abs((thisHero -> y) - (thisWall.y)) <= 50 && dist <= 40)
    {
        if (player == 1)
        {
            thisHero -> x = SIZEX / 8;
            thisHero -> y = 100;
        }
        else
        {
            thisHero -> x = 5* SIZEX / 8;
            thisHero -> y = 100;
        }
        thisHero -> countLife --;
    }

}

bool myHeroes :: Lose (int player)
{
    if (this -> countLife <= 0)
    {
     int ay = 0;
     if (player == 2 ) ay = 35;
     txSetColor (RGB (255, 255 , 0));
     txSelectFont ("Times New Roman", 20, 10, true, true);
     char st[2];
     txDrawText  (3 * SIZEX / 8, 0 + ay, SIZEX / 2, 70,"Player ");
     sprintf(st, "%d", player);
     txDrawText  (3 * SIZEX / 8, 0 + ay, SIZEX / 2 + 80, 70, st);
     txDrawText  (3 * SIZEX / 8, 0 + ay, SIZEX / 2 + 140, 70, " lost!");
     return false;
    }
    else
    {
     return true;
    }
}

bool myHeroes :: Win(HDC backImage, int player)
{
    COLORREF color = txGetPixel (this -> x, this -> y, backImage);
    if (color == RGB (255, 0, 0))
        {
         txSetColor (RGB (255, 0 , 0));
         txSelectFont ("Times New Roman", 35, 25, true, true);
         char st[2];
         txDrawText  (150, 100, 400, 300,"Player ");
         sprintf(st, "%d", player);
         txDrawText  (360, 100, 410, 300, st);
         txDrawText  (350, 100, 600, 300, " WIN!");
         return true;
        }
    else
        {
         return false;
        }
}

    void wall :: DataInput (int number)
{
       if (number % 2 == 0) this -> x = 5;
       else            this -> x = 565;
       this -> y = 150 + rand() % 350;
       if (number % 2 == 0) this -> speed = rand () % 7 + 2;
       else            this -> speed = - rand () % 7 + 2;
}

void Game_Over ()
{
    txSetColor (RGB (255, 0, 0));
    txSelectFont ("Times New Roman", 30, 20, true, true);
    txDrawText  (150, 150, 700, 250,"GAME OVER!");
}
