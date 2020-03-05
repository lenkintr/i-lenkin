#include "TXLib.h"
#include <iostream>

void InputArray  (      int arr[], int sizeArr);
void OutputArray (const int arr[], int sizeArr);
int FindInArray  (int arr[],int n, int k);
int RunTest ();
int main ()
{
    const int n = 10;
    int mas[n] = {};
    RunTest();
    //FindInArray (mas, n, k);
    //InputArray  (mas, n);
    //OutputArray (mas, n);
}
int RunTest ()
    {
        int mas[6] = {5,4,3,2,1,0};
        $unittest (FindInArray (mas, 6, 5), 0);

        $unittest (FindInArray (mas, 6, 6), -1);//смотри атрибуты символов консоли TXLib

    }

void InputArray (int arr[], int sizeArr)
{
   for (int i = 0; i < sizeArr; i++)
    {
       assert(0 <= i && i < sizeArr);
       arr[i] = 5 * i;
    }
}

void OutputArray (const int arr[],int sizeArr)
{
   for (int i = 0; i < sizeArr; i++)
    {
        $C; std::cout << "[" << i << "] = ";
        $c; std::cout << arr[i] << ", ";
        $d;
    }
}
int FindInArray  (int arr[],int n, int k)
{ int res = -1;
   for (int i = 0; i < n; i++)
    {
     if (arr[i] == k) {res = i;}
    }
   return res;
}
