//! @file TXM_Lib.cpp
//! @mainpage
//! @ref Draw_Background
//! @ref Draw_SunSimple
//! @ref Draw_House
//! @ref Draw_Tree
//! @ref Draw_Rabbit
//! @ref Draw_Hedgehog
//! @ref Draw_Flower
//! @ref Draw_Sun
//! @ref Becomes_Dark
//! @ref This_is_Rabbit
//! @ref That_is_all
# include "Txlib.h"
const int FPS = 20;
const int X = 1200;
const int Y = 700;
const int meetTimeS = 3;
//=================================================================================================================
//!
//! @brief   ���������� ���������� ��������� ����������� ��������
//}
//=================================================================================================================
const COLORREF PURE_YELLOW = RGB (255, 255, 150);
struct color
{
    COLORREF cloud;
    COLORREF sky;
  //  COLORREF soil;
    double meetX;
    double meetY;
    double hedgX;
    double cloud_Len;
};
//=================================================================================================================
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ ��� ����
//!
//! @param   x ������ ���� ����
//! @param   y ������ ���� ����
//! @param   skyColor ���� ����
//! @param   soilColor ���� �����
//! @see     txSetFillColor (); txSetColor ( ); txRectangle ( , , );
//!
//! @usage ������ �������������: @code
//!          Draw_Background ( 300, 300, TX_BLUE, TX_GREEN)  // �������� ���, ����������� �������, ����� / �������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void Draw_Background (int x, int y, COLORREF skyColor, COLORREF soilColor);
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ ���������� ������� ������
//!
//! @param   x ���������� ������ ���������� �� ��
//! @param   y ���������� ������ ���������� �� ��
//! @param   sunR ������ ����������
//! @param   sunLenght ����� �����
//! @see     Draw_Sun ();
//!
//! @usage ������ �������������: @code
//!            Draw_Sun ( 100, 100, 50, 40)// �������� ������ ������ � ����� (100,100) � �������� 50, ������� ����� 3, ������ 40
//! @endcode
//}
void Draw_SunSimple (int x,int y, int sunR, int sunLenght);
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ ������
//!
//! @param   x ���������� ������ ���������� �� ��
//! @param   y ���������� ������ ���������� �� ��
//! @param   sunR ������ ����������
//! @param   sun ���� ������
//! @param   sunThickness ������� �����
//! @param   sunLenght ����� �����
//! @see     txSetFillColor (); txSetColor ( ); txCircle (, , ); txLine ( , , , );
//!
//! @usage ������ �������������: @code
//!            Draw_Sun ( 100, 100, 50, TX_YELLOW, 5, 40)// �������� ������ ������ � ����� (100,100) � �������� 50, ������� ����� 5, ������ 40
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void Draw_Sun (int x,int y, int sunR, COLORREF sun, int sunThickness, int sunLenght);
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ ���
//!
//! @param   x ���������� ������ �������� ���� �� ��
//! @param   y ���������� ������ �������� ����  �� ��
//! @param   houseHeight ������ ����
//! @param   houseWidth  ������ ����
//! @param   houseColor ���� ����
//! @param   doorWidth ������ �����
//! @param   doorColor ���� �����
//! @param   roofColor ���� �����
//! @param   windowR ������ �������� ����
//! @param   windowColor ���� ����
//! @see     txSetFillColor (); txSetColor ( ); txRectangle ( , , ); txCircle (, , ); txPolygon ( , );
//!
//! @usage ������ �������������: @code
//!              Draw_House( 40, 380, 220, 160, TX_YELLOW, 180, 80, TX_CYAN, 160, TX_RED, 30, TX_WHITE);// �������� ��� � ����� (40,380) ������� 220, ������� 160, � ������� �������, ������� ������ ������� 180 � ������� 80, ����� ����� �������� 30 � ������� ������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void Draw_House (int x, int y, int  houseHeight, int houseWidth, COLORREF houseColor, int doorWidth, COLORREF doorColor, COLORREF roofColor,int windowR, COLORREF windowColor);
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ ���������� ������� ����
//!
//! @param   x ���������� ������ �������� ���� �� ��
//! @param   y ���������� ������ �������� ����  �� ��
//! @param   houseHeight ������ ����
//! @param   houseWidth  ������ ����
//! @see     Draw_House();
//!
//! @usage ������ �������������: @code
//!              Draw_House( 40, 380, 220, 160);// �������� ��� � ����� (40,380) ������� 220, ������� 160, � �������� �������, ������ ������ �������, ������� ����� �������� 10 � ���������� ������
//! @endcode
//}
void Draw_HouseSimple (int x, int y, int  houseHeight, int houseWidth);
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ ������
//!
//! @param   x ���������� ������ ������� ���� ������  �� ��
//! @param   y ���������� ������ ������� ���� ������  �� ��
//! @param   treeHeight ������ ������
//! @param   treeWidth  ������ ������
//! @param   treeColor ���� ������
//! @param   leavesColor ���� ������
//! @param   leavesR ������ �����, ������� �� ������� �����������
//! @see     txSetFillColor (); txSetColor ( ); txRectangle ( , , ); txCircle (, , );
//!
//! @usage ������ �������������: @code
//!              Draw_GrowingTree ( 500,650, 160, 80, TX_BROWN, TX_GREEN, 80);// �������� ������ � ����� (500, 650) ������� 160 � ������� ������ 80, ���� ������ ����������, ������ �������, ������� ������ 80
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void Draw_Tree (int x, int y, int treeHeight, int treeWidth, COLORREF treeColor, COLORREF leavesColor, int leavesR);
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������  ������
//!
//! @param   x ���������� ������ �� ��
//! @param   y ���������� ������ �� ��
//! @param   appleR ������ �����
//! @param   appleColor ���� �����
//! @see     txSetFillColor (); txSetColor ( ); txCircle (, , );
//!
//! @usage ������ �������������: @code
//!          Draw_Apples ( 50, 100, 15, RGB (249, 19, 19)); // ������ ������� ������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void Draw_Apple ( int x, int y, int appleR, COLORREF appleColor);
//{----------------------------------------------------------------------------------------------------------------
//! @brief ������ ������
//!
//! @param   x ���������� ������ ���������� (������������ ������ ������) �� ��
//! @param   y ���������� ������ ���������� (������������ ������ ������) �� ��
//! @param   dogHeadR ������ ������
//! @param   earsHeight ������ ���� ������
//! @param   tail_X ��������� ������
//! @param   tailLength ����� ������
//! @param   dogColor ���� ������
//! @param   dogNose ���� ���� ������
//! @param   dogNoseR ������ ���� ������
//! @see     txSetFillColor (); txSetColor ( ); txCircle (, , ); txLine ( , , ,); txPolygon ( , );
//!
//! @usage ������ �������������: @code
//!   Draw_Dog( 300,600, 30, 18, 12, 60, TX_ORANGE, TX_BLACK, 5); // ������ ������ �������� ��� � ������ ����� � ������� ������� � ����� (300, 600)
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void Draw_Dog (int x, int y, int dogHeadR,int earsHeight, int tail_X, int tailLength,  COLORREF dogColor, COLORREF dogNose, int dogNoseR );
//{----------------------------------------------------------------------------------------------------------------
//! @brief ������ ������� ���������� ������
//!
//! @param   x ���������� ������ ���������� (������������ ������ �������) �� ��
//! @param   y  ���������� ������ ���������� (������������ ������ �������) �� ��
//! @param   rabbitHeadR ������ ������ �������
//! @param   rabbitColor ���� ������� �������
//! @param   secondColor ���� ���� �������
//! @param   noseColor ���� ����
//! @param   eyesColor ���� ����
//! @param   fatRabbit ������� �������
//! @param   tailOffset ��������� ������
//! @see     txSetFillColor (); txSetColor ( ); txCircle (, , ); txLine ( , , ,); txEllipse( , , , );
//!
//!
//! @usage ������ �������������: @code
//!          Draw_Rabbit( 200, 400, 50, RGB ( 255, 100, 231), RGB ( 200, 191, 241), RGB ( 163, 73, 164), RGB ( 136, 0, 21));   // ������ ������ �������� ������ ���������� ������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void Draw_Rabbit( int x, int y, int rabbitHeadR, COLORREF rabbitColor, COLORREF secondColor, COLORREF noseColor, COLORREF eyesColor,int fatRabbit, int tailOffset );
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ ������
//!
//! @param   x ���������� ������ ���������� 1/3 ����� ������  �� ��
//! @param   y ���������� ������ ���������� 1/3 ����� ������ �� ��
//! @param   cloudColor ���� ������
//! @param   cloudLenght ���������� �� ������ ������ (������������� ������)
//! @see     txSetFillColor (); txSetColor ( ); txCircle (, , );
//!
//!
//! @usage ������ �������������: @code
//!             Draw_Cloud ( 100, 200,120, RGB (66,94,145),80 );// ������ ������� �����
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void Draw_Cloud (int x, int y, COLORREF cloudColor, int cloudLenght);
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ �����
//!
//! @param   x ���������� ���� ����� �� ��
//! @param   y ���������� ���� ����� �� �y
//! @param   h_size ������ ����� ������������ ����
//! @param   step ���������� ������ ���� �����
//! @param   eyesOpen ���������� ����������, ���������� ������� - ������� �����
//! @see     txSetFillColor (); txSetColor ( ); txCircle (, , );
//!
//!
//! @usage ������ �������������: @code
//!             Draw_Hedgehog (100, 100, 10, 0, true);// ������ �������� ����� � ����� (100, 100) � ��������� �������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void Draw_Hedgehog (int x, int y, int h_size, int step, bool eyesOpen);
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ ������
//!
//! @param   x ���������� ������ �� ��
//! @param   y ���������� ������ �� �y
//! @param   f_size ������ ������
//! @param   f_color ���� ������
//! @see     txSetFillColor (); txSetColor ( ); txCircle (, , ); txLine (,,,); txArc (,,,,,);
//!
//!
//! @usage ������ �������������: @code
//!           void Draw_Flower ( 100, 100, 10,TX_PINK) ������ ������� ������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void Draw_Flower (int x, int y, double f_size, COLORREF f_color);
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ ������ ����� �����������
//!
//! @param   sunX ���������� ����� �� ��� ��
//! @param   sunY ���������� ����� �� ��� ��
//! @param   cloudX ���������� ������ �� ��� ��
//! @param   cloudY ���������� ������ �� ��� ��
//! @param   meetX ���������� ������� �� ��� ��
//! @param   meetY ���������� ������� �� ��� ��
//! @see     txSetFillColor (); txSetColor ( ); txRectangle ( , , );....
//!
//! @usage ������ �������������: @code
//!       Becomes_Dark (100, 100, 500, 500, 300, 300);  // ����� ���������� ������ � ������, ������� ����������� � ����� (300, 300)
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
struct color Becomes_Dark (double sunX, double sunY, double cloudX, double cloudY, double meetX, double meetY);
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ ������ ����� �����������
//!
//! @param   x ��������� ������ �� ��� ��
//! @param   y ��������� ������ �� ��� �y
//! @param   hedgX ���������� � ��������� �����
//! @param   cloud_Len ������ ������
//! @param   cloud ���� ������
//! @param   sky ���� ����
//! @see     txSetFillColor (); txSetColor ( ); txRectangle ( , , );
//!
//! @usage ������ �������������: @code
//!          This_is_Rabbit ( 300, 300, 150, 100, TX_BLUE, TX_GREEN)  // ������ ����� � ������� � ����� (300,300) ������ � ����� 150 �� ��, ����� ������� � ������� �����
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void This_is_Rabbit (double x, double y,double hedgX, double cloud_Len, COLORREF cloud, COLORREF sky);
//{----------------------------------------------------------------------------------------------------------------
//! @brief   ������ �������� �����
//!
//! @see     txSetFillColor (); txSetColor ( ); txRectangle ( , , );...
//!
//! @usage ������ �������������: @code
//!          That_is_all ();  // ��������� �������� ����� � �������
//! @endcode
//}----------------------------------------------------------------------------------------------------------------
void That_is_all ();



//--------------
void That_is_all ()
{
        for (int j = 1; j <= 700; j++)
    {
        txSetFillColor (TX_BLACK);
        txClear();
        txSetColor (RGB (255, 0 , 0));
        txSelectFont ("Times New Roman", 50, 30, true, true);
        txDrawText  (150, 250 - j * 5, 1000, 600 - j * 5, "There was supposed to be a third scene.\n But time is other!\n And this is the end !!!");
        txSleep(100);
    }

}

void Draw_Background (int x, int y, COLORREF skyColor, COLORREF soilColor)
{
    txSetFillColor (skyColor);
    txSetColor (skyColor);
    txRectangle (x - x, y / 1.5, x, y);
    txSetColor (soilColor);
    txSetFillColor (soilColor);
    txRectangle (x - x, y - y, x, y / 1.5);
}

void Draw_SunSimple (int x,int y, int sunR, int sunLenght)
{
    Draw_Sun (x, y, sunR, PURE_YELLOW, 3, sunLenght);
}

void Draw_Sun (int x,int y, int sunR, COLORREF sun, int sunThickness, int sunLenght)
{
    txSetColor (sun, sunThickness);
    txSetFillColor (sun);
    txCircle (x, y, sunR);
    txLine (x - 2 * sunR - 2*sunLenght, y - 2 * sunR  - 2*sunLenght , x - sunR , y - sunR);
    txLine (x + sunR, y - sunR, x + 2 * sunR + 2 * sunLenght, y - 2 * sunR - 2 * sunLenght);
    txLine (x + 2 * sunR + 2 * sunLenght, y + 2 * sunR + 2 * sunLenght, x + sunR, y + sunR);
    txLine (x - sunR, y + sunR, x - 2 * sunR - 2 * sunLenght, y + 2 * sunR + 2 * sunLenght);
    txLine (x, y - sunR - 0.3 * sunR, x, y - 2 * sunR - sunLenght);
    txLine (x, y + sunR + 0.3 * sunR, x, y + 2 * sunR + sunLenght);
    txLine (x - sunR - 0.3 * sunR, y, x - 2 * sunR - sunLenght, y);
    txLine (x + sunR + 0.3 * sunR, y, x + 2 * sunR + sunLenght, y);

}
void Draw_House (int x, int y, int  houseHeight, int houseWidth, COLORREF houseColor, int doorWidth, COLORREF doorColor, COLORREF roofColor,int windowR, COLORREF windowColor)
{
        //�����
    txSetColor (houseColor);
    txSetFillColor (houseColor);
    txRectangle (x, y, x + houseWidth, y + houseHeight);
        //�����
    txSetColor (doorColor);
    txSetFillColor (doorColor);
    txRectangle (x + houseWidth / 2 - doorWidth / 2, y + houseHeight, x + houseWidth / 2 + doorWidth / 2, y + houseHeight * 0.3);
    txSetColor (roofColor);
    txSetFillColor (roofColor);
    POINT Star[3] = {{x, y}, {x + houseWidth, y}, { x + houseWidth/2, y - houseWidth}};
    txPolygon (Star, 3);
          //����
    txSetColor (windowColor);
    txSetFillColor (windowColor);
    txCircle (x + houseWidth / 2, y - houseWidth / 3, windowR);
}
void Draw_HouseSimple (int x, int y, int  houseHeight, int houseWidth)
{
    Draw_House (x, y, houseHeight, houseWidth, RGB (245, 14, 54), 30, RGB (70, 70, 70), RGB (82, 1, 120), 10, RGB (190, 248, 252));
}
void Draw_Tree (int x, int y, int treeHeight, int treeWidth, COLORREF treeColor, COLORREF leavesColor, int leavesR)
{
    txSetColor (treeColor);
    txSetFillColor (treeColor);
    txRectangle (x, y, x + treeWidth, y - treeHeight);
        //������
    txSetColor (leavesColor);
    txSetFillColor (leavesColor);
    txCircle (x - 0.9* treeWidth, y - 0.8 * treeHeight - 1.7 * leavesR, leavesR);
    txCircle (x + 0.4* treeWidth, y - 0.8 * treeHeight - leavesR, leavesR );
    txCircle (x + 1.7* treeWidth, y - 0.8 * treeHeight - 1.7 * leavesR, leavesR);
    txCircle (x + 0.4* treeWidth, y - 0.8 * treeHeight - 2.5 * leavesR, leavesR);
    }
void Draw_Apple ( int x, int y, int appleR, COLORREF appleColor)
{
    txSetColor (appleColor);
    txSetFillColor (appleColor);
    txCircle (x , y, appleR);
}
void Draw_Dog (int x, int y, int dogHeadR,int earsHeight, int tail_X, int tailLength,  COLORREF dogColor, COLORREF dogNose, int dogNoseR )
{
    txSetColor ( dogColor, 6 );
    txSetFillColor ( dogColor );
    txCircle ( x, y, dogHeadR );
    //��� ����� ������
    txLine ( x, y + dogHeadR, x, y + dogHeadR + 20 );
    txLine ( x, y + dogHeadR + 20, x + 100, y + dogHeadR + 20 );
    txLine ( x, y + dogHeadR + 20, x - 10, y + dogHeadR + 20 + 40 );
    txLine ( x, y + dogHeadR + 20, x + 10, y + dogHeadR + 20 + 40 );
    txLine ( x + 100, y + dogHeadR + 20, x + 100, y + dogHeadR + 20 + 40 );
    txLine ( x + 100, y + dogHeadR + 20, x + 100 + 20, y + dogHeadR + 20 + 40 );
    txSetColor ( dogColor, 4 );
    txLine ( x + 100, y + dogHeadR + 20, x + 100 + tail_X, y + dogHeadR + 20 - tailLength );
    //���
    POINT yxo1[3] = {{ x - dogHeadR , y - dogHeadR}, { x - dogHeadR  + 10, y - dogHeadR + 5}, { x - dogHeadR , y - dogHeadR - earsHeight}};
    txPolygon ( yxo1, 3);
    POINT yxo2[3] = {{ x - dogHeadR + 50, y - dogHeadR + 5}, { x - dogHeadR + 50 + 10, y - dogHeadR }, { x - dogHeadR + 50, y - dogHeadR - earsHeight}}; //{940, 555}, {950, 555}, {940, 535}
    txPolygon ( yxo2, 3 );
    //�����
    txSetColor ( dogNose, 1 );
    txSetFillColor ( dogNose );
    txCircle ( x, y, dogNoseR );
    txCircle ( x - 10, y - 10 , dogNoseR * 0.6 );
    txCircle ( x + 10, y - 10 , dogNoseR * 0.6 );
}

void Draw_Rabbit( int x, int y, int rabbitHeadR, COLORREF rabbitColor, COLORREF secondColor, COLORREF noseColor, COLORREF eyesColor,int fatRabbit, int tailOffset )
{
    txSetColor ( rabbitColor );
    txSetFillColor ( secondColor );
    txCircle ( x,  y , rabbitHeadR );
    txSetColor ( rabbitColor, fatRabbit );
    txEllipse ( x , y + rabbitHeadR, x + 2, y + rabbitHeadR + 4 * rabbitHeadR );
    txSetColor ( rabbitColor, 1 );
            //����
    txEllipse( x - 20, y + rabbitHeadR + 4 * rabbitHeadR, x - 20 + 3 * rabbitHeadR, y + rabbitHeadR + 4 * rabbitHeadR - 10 );
    txEllipse( x - 15, y + rabbitHeadR + 4 * rabbitHeadR - 5, x - 20 + 3 * rabbitHeadR + 5, y + rabbitHeadR + 4 * rabbitHeadR + 5 );
        //���
    txEllipse( x - 0.5 * rabbitHeadR, y - 3 * rabbitHeadR, x, y - rabbitHeadR );
    txEllipse( x - 0.7 * rabbitHeadR, y - 2.8 * rabbitHeadR, x - 0.25 * rabbitHeadR, y - 0.8 * rabbitHeadR );
        //����
    txLine ( x, y + 1.5 * rabbitHeadR, x + 1.5 * rabbitHeadR, y + 2 * rabbitHeadR );
    txLine ( x, y + 1.5 * rabbitHeadR, x + 1.7 * rabbitHeadR, y + 1.7 * rabbitHeadR );
        //�����
     txCircle ( x - 0.5 * rabbitHeadR, y + rabbitHeadR + 3.4 * rabbitHeadR - tailOffset, 0.5 * rabbitHeadR );
        //���
     txSetColor ( noseColor );
     txSetFillColor ( noseColor );
     txCircle ( x + rabbitHeadR, y , 0.25 * rabbitHeadR );
        //����
     txSetColor ( eyesColor );
     txSetFillColor ( eyesColor );
     txCircle ( x + 0.4 * rabbitHeadR, y - 0.5 * rabbitHeadR, 0.16 * rabbitHeadR );
}

void Draw_Cloud (int x, int y, COLORREF cloudColor, int cloudLenght)
{
     txSetColor (cloudColor);
     txSetFillColor (cloudColor);
     txCircle (x, y, cloudLenght / 1.1);
     txCircle (x + cloudLenght, y + 0.5 * cloudLenght, cloudLenght / 1.1);
     txCircle (x + 1.7 * cloudLenght, y - 10, cloudLenght / 1.1);
     txCircle (x + 2.7 * cloudLenght, y + 0.2 * cloudLenght, cloudLenght / 1.1);
}

void Draw_Hedgehog (int x, int y, int h_size, int step, bool eyesOpen)
{
    txSetColor(TX_BLACK);
    txSetFillColor (TX_BLACK);
      POINT needle[19] = {{x - h_size * 20.7, y - h_size * 1.1},
                          {x - h_size * 26.2, y - h_size * 3.5},
                          {x - h_size * 19.2, y - h_size * 2.6},
                          {x - h_size * 22.4, y - h_size * 6.9},
                          {x - h_size * 17.9, y - h_size * 3.2},
                          {x - h_size * 17.9, y - h_size * 9.8},
                          {x - h_size * 15.5, y - h_size * 3.5},
                          {x - h_size * 14.7, y - h_size * 10.7},
                          {x - h_size * 13.6, y - h_size * 3.7},
                          {x - h_size * 11.7, y - h_size * 10.5},
                          {x - h_size * 11.1, y - h_size * 3.7},
                          {x - h_size * 8.3, y - h_size * 10.6},
                          {x - h_size * 9.3, y - h_size * 3.4},
                          {x - h_size * 4.1, y - h_size * 11.7},
                          {x - h_size * 7.6, y - h_size * 3.1},
                          {x - h_size * 2.2, y - h_size * 6.3},
                          {x - h_size * 5.7, y - h_size * 2.5},
                          {x + h_size * 0.4, y - h_size * 5.2},
                          {x - h_size * 4.6, y - h_size * 0.9}};

      txPolygon (needle, 19);
      txSetColor (RGB(128, 64, 64), 2);
      txSetFillColor (RGB( 128, 64, 64));
      txEllipse (x - h_size * 20.8, y - h_size * 3.4, x - h_size * 4.9, y + h_size * 2.5);//318, 352, 10
      POINT nose[3] = {
                       {x - h_size * 4.9, y - h_size * 0.8}, {x, y},
                       {x - h_size * 6.2, y + h_size * 1.2}
                       };
      txPolygon ( nose, 3 );
      txSetFillColor (TX_BLACK);
      txSetColor (TX_BLACK);
      txCircle (x, y, h_size);//318, 352, 10
      if (eyesOpen)
          {
            txCircle (x - h_size*7.4, y - h_size, h_size*0.8);
          }
      else
          {
            txLine (x - h_size*7.4, y - h_size, x - h_size*7.4 + h_size*0.8, y - h_size);
          }
      txSetFillColor (RGB(86, 54, 54));
      txSetColor (RGB(86, 44, 44), 3);
      txEllipse (x - h_size * 19.8, y + h_size * 1.2 - step, x - h_size * 13.5, y + h_size *3.3 - step);
      txEllipse (x - h_size * 11.2, y + h_size * 1.2 + step, x - h_size * 5, y + h_size *3.3 + step);
}

void Draw_Flower (int x, int y, double f_size, COLORREF f_color)
{
      int red = txExtractColor ( f_color, TX_RED );
      int green = txExtractColor ( f_color, TX_GREEN );
      int blue = txExtractColor ( f_color, TX_BLUE );

      txSetColor ( RGB ( red/1.5, green/1.5, blue ), 3 );
      txSetFillColor ( f_color );
      txCircle ( x - f_size * 0.75, y - f_size * 1.25, f_size );
      txCircle ( x + f_size * 1, y - f_size * 1, f_size );
      txCircle ( x - f_size * 1.5, y + f_size * 0.5, f_size );
      txCircle ( x - f_size * 0.5, y + f_size * 1.5, f_size );
      txCircle ( x + f_size, y + f_size, f_size );
      txSetColor ( PURE_YELLOW, 3 );
      txSetFillColor ( PURE_YELLOW );
      txCircle ( x, y, f_size );
      txSetColor ( TX_GREEN, 5 );
      txLine ( x - f_size * 0.25, y + f_size * 2.5, x + f_size * 0.5, y + f_size * 7.5 );
      txArc ( x + f_size * 0.3, y + f_size * 8.35, x + f_size, y + f_size * 3.35, 60, f_size * 4 );
}

struct color Becomes_Dark (double sunX, double sunY, double cloudX, double cloudY, double meetX, double meetY)
{
    int countSteps = 0;
    int i = 0;
    double f_size = 0;
    double hedg_X;
    double ts;
    for (int j = 1; j <= 20; j++)
    {
    txSetColor (TX_WHITE);
    txSelectFont ("Times New Roman", 40, 30, true, true);
    txDrawText  (450, 250, 800, 500, "Scene one..");
    txSleep(100);
    }
    COLORREF colorSky;
    COLORREF colorCloud;
    //COLORREF colorSoil;
    double mtX;
    double mtY;
    while ( i < FPS * meetTimeS + 1 )
    {
        txClear ();
        ts = 1.0 * i / FPS;
        colorSky = RGB (113 + ts * (30 - 113) /  meetTimeS, 154 + ts * (91 - 154) /  meetTimeS, 213 + ts * (185 - 213) /  meetTimeS);
        Draw_Background (X, Y, RGB ( 23, 170, 89 ), colorSky);
        Draw_Sun (sunX + ts * (meetX - sunX) /  meetTimeS,
                  sunY + ts * (meetY - sunY) /  meetTimeS,
                  60,
                  RGB (255 + ts * (237 - 255) /  meetTimeS, 242 + ts * (28 - 242) /  meetTimeS,
                        0 + ts * (36 - 0) /  meetTimeS), 5 - 0.1 * i, 20 - i);
        colorCloud = RGB (62 + ts * (66 - 62) /  meetTimeS, 184 + ts * (94 - 184) /  meetTimeS,
                          216 + ts * (145 - 216) /  meetTimeS);
        mtX = cloudX + ts * (meetX - cloudX ) /  meetTimeS;
        mtY = cloudY + ts * (meetY - cloudY ) /  meetTimeS;
        Draw_Cloud (mtX, mtY, colorCloud, 60 + 0.5*i);
        hedg_X = X / 5 + i * 3;
        Draw_HouseSimple(100, 300, 200, 150);
        Draw_Hedgehog(hedg_X, 500, 6, - 5 + countSteps, true);
        if (countSteps == 10) countSteps = 0;
        else countSteps += 5;


        Draw_Flower (440, 447, f_size, RGB (233, 142, 240));
        Draw_Flower (540, 457, f_size, RGB (0, 142, 240));
        Draw_Flower (480, 477, f_size - 2, RGB (255, 0, 0));
        if (f_size != 10) f_size += 0.2;
        Draw_Tree (700, 500, 140, 40, TX_BROWN, TX_GREEN, 80);
        Draw_Tree (900, 550, 80, 40, TX_BROWN, RGB (0 + i, 255, 100), 60);
        txSleep (1000 / FPS);
        i = i + 1;
    }
    double cloud_Len;
  while (hedg_X <= 550 )
  {
     txClear();
     Draw_Background ( X, Y, RGB ( 23, 170, 89 ), colorSky);
     Draw_Sun (sunX + ts * (meetX - sunX) /  meetTimeS,
                  sunY + ts * (meetY - sunY) /  meetTimeS,
                  60,
                  RGB (255 + ts * (237 - 255) /  meetTimeS, 242 + ts * (28 - 242) /  meetTimeS,
                        0 + ts * (36 - 0) /  meetTimeS), 5 - 0.1 * i, 20 - i);
     cloud_Len = 60 + 0.5 * i;
     Draw_Cloud (mtX, mtY, colorCloud, cloud_Len);
     hedg_X = X / 5 + i * 3;
     Draw_HouseSimple(100, 300, 200, 150);
     Draw_Hedgehog(hedg_X, 500, 6, - 5 + countSteps, true);
     if (countSteps == 10) countSteps = 0;
     else countSteps += 5;
     Draw_Tree (700, 500, 140, 40, TX_BROWN, TX_GREEN, 80);
     Draw_Tree (900, 550, 80, 40, TX_BROWN, RGB (0, 255, 100), 60);
     Draw_Flower (440, 447, f_size, RGB (233, 142, 240));
     Draw_Flower (540, 457, f_size, RGB (0, 142, 240));
     Draw_Flower (480, 477, f_size - 2, RGB (255, 0, 0));
     i ++;
     txSleep (90);
  }
  Draw_Hedgehog (hedg_X, 500, 6, 0, false);
  Draw_Flower (440, 447, f_size, RGB (233, 142, 240));
  Draw_Flower (540, 457, f_size, RGB (0, 142, 240));
  Draw_Flower (480, 477, f_size - 2, RGB (255, 0, 0));



 color cc;
 cc.cloud = colorCloud;
 cc.sky = colorSky;
 cc.meetX =  mtX;
 cc.meetY =  mtY;
 cc.hedgX = hedg_X;
 cc.cloud_Len = cloud_Len;
  return cc;
}
void This_is_Rabbit (double x, double y,double hedgX, double cloud_Len, COLORREF cloud, COLORREF sky)
{
    txSetFillColor(TX_BLACK);
    txSetColor (TX_WHITE);
 for (int j = 1; j <= 20; j++)
 {
    txClear();
    txSelectFont ("Times New Roman", 40, 30, true, true);
    txDrawText  (450, 250, 800, 500, "Scene two..");
    txSleep(100);
 }
 int i = 0;
 int offset = 0;
 bool f = true;
 while (i <= 75)
 {
     Draw_Background(X,Y, RGB ( 23, 170, 89 ), sky);
     Draw_Cloud(x, y, cloud, cloud_Len);
     Draw_HouseSimple(100, 300, 200, 150);
     Draw_Hedgehog (hedgX, 500, 6, 0, false);
     Draw_Tree (700, 500, 140, 40, TX_BROWN, TX_GREEN, 80);
     Draw_Tree (900, 550, 80, 40, TX_BROWN, RGB (0, 255, 100), 60);
     Draw_Flower (440, 447, 12, RGB (233, 142, 240));
     Draw_Flower (540, 457, 12, RGB (0, 142, 240));
     Draw_Flower (480, 477, 10, RGB (255, 0, 0));
     Draw_Rabbit(5 * i, 450, 20, RGB (225, 225, 225), RGB (255, 255, 255), TX_PINK, RGB (135, 0, 64), 1, offset);
     if (offset <= 8 && f) {offset += 3;}
     else {
            f =false;
            offset -= 3;
            if (offset < -8)  {f = true;}
            }
     txSleep(30);
     i ++;
 }

 for (int j = 0; j< 30; j ++)
 {
     Draw_Background(X,Y, RGB ( 23, 170, 89 ), sky);
     Draw_Cloud(x, y, cloud, cloud_Len);
     Draw_HouseSimple(100, 300, 200, 150);
     Draw_Tree (700, 500, 140, 40, TX_BROWN, TX_GREEN, 80);
     Draw_Tree (900, 550, 80, 40, TX_BROWN, RGB (0, 255, 100), 60);
     if (j <= 6)
     {
         Draw_Hedgehog (hedgX, 500, 6, 0, false);
         Draw_Flower (440, 447, 12, RGB (233, 142, 240));
         Draw_Flower (540, 457, 12, RGB (0, 142, 240));
         Draw_Flower (480, 477, 10, RGB (255, 0, 0));
         Draw_Rabbit(5 * i, 450, 20, RGB (225, 225, 225), RGB (255, 255, 255), TX_PINK, RGB (135, 0, 64), 1, offset);
     }
     else if (j <= 15)
     {
         Draw_Hedgehog (hedgX, 500, 6, 0, false);
         Draw_Flower (540, 457, 11, RGB (0, 142, 240));
         Draw_Flower (480, 477, 9, RGB (255, 0, 0));
         Draw_Rabbit(5 * i, 450, 20, RGB (225, 225, 225), RGB (255, 255, 255), TX_PINK, RGB (135, 0, 64), 4, offset);
     }
     else if (j <= 20)
     {
         Draw_Hedgehog (hedgX, 500, 6, 0, true);
         Draw_Flower (540, 457, 11, RGB (0, 142, 240));
         Draw_Rabbit(5 * i + 30, 450, 20, RGB (225, 225, 225), RGB (255, 255, 255), TX_PINK, RGB (135, 0, 64), 7, offset);
     }
     else
     {
         Draw_Hedgehog (hedgX, 500, 6, 0, true);
         Draw_Rabbit(5 * i + 60, 450, 20, RGB (225, 225, 225), RGB (255, 255, 255), TX_PINK, RGB (135, 0, 64), 10, offset);
     }
     txSleep(200);
  }
      int countSteps = 0;
     for (int j = 0; j <= 130; j++)
     {
        Draw_Background(X,Y, RGB ( 23, 170, 89 ), sky);
        Draw_Cloud(x, y, cloud, cloud_Len);
        Draw_HouseSimple(100, 300, 200, 150);
        Draw_Tree (700, 500, 140, 40, TX_BROWN, TX_GREEN, 80);
        Draw_HouseSimple(100, 300, 200, 150);
        Draw_Hedgehog(hedgX + j * 3, 500, 6, - 5 + countSteps, true);
        Draw_Tree (900, 550, 80, 40, TX_BROWN, RGB (0, 255, 100), 60);
        Draw_Rabbit(5 * i + 60, 450, 20, RGB (225, 225, 225), RGB (255, 255, 255), TX_PINK, RGB (135, 0, 64), 7, offset);
        if (countSteps == 10) countSteps = 0;
        else countSteps += 5;
        txSleep(10);
     }

}
