// ----------
// �������� ������� � �������� ���������
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

void Graphic( double (*func) (double x), COLORREF color) //� ������� ��� �������� � ������� , ������ ���� - ��� ������������ ������ (�� ���������); (*func) - ��������� �� ����� �������
{
    txSetColor (color);
    txSetFillColor (color);
    double x = -20;
    while (x <= +20)
    {
        double y = (*func) (x); // �.�. ������� ������ -> ����� ������� (* - �����)

        txCircle (800 / 2 + 50 * x, 600 / 2 - 50 * y, 2);
        x += 0.1;
    }

}

double Sqr (double x) { return x *x; }

double Sin (double x) { return sin (x); }
