// ----------
// �������� ������� � �������� ���������
//----------
#include "TXLib.h"


void DrawParabola();
void DrawCircle();

int main()
{
  txCreateWindow(800, 600);
  txBegin();

  DrawParabola();
  DrawCircle();

  txEnd();

}


void DrawParabola() //� ������� ��� �������� � ������� , ������ ���� - ��� ������������ ������ (�� ���������); (*func) - ��������� �� ����� �������
{
   txSetColor (TX_LIGHTRED);
   txSetFillColor (TX_LIGHTRED);

   for ( double y = -10; y <= +10; y += 0.15)
   for ( double x = -10; x <= +10; x += 0.15)
   {
      if (y > x * x)
      txCircle (800 / 2 + 50 * x, 600 / 2 - 50 * y, 2);
   }


}

void DrawCircle() //� ������� ��� �������� � ������� , ������ ���� - ��� ������������ ������ (�� ���������); (*func) - ��������� �� ����� �������
{
   txSetColor (TX_GREEN);
   txSetFillColor (TX_GREEN);

   for ( double y = -10; y <= +10; y += 0.15)
   for ( double x = -10; x <= +10; x += 0.15)
   {
      if (y * y + x * x < 25)
      txCircle (800 / 2 + 50 * x + 4, 600 / 2 - 50 * y, 2);
   }


}

