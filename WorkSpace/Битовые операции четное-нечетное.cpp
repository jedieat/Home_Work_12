
#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
   int a;
   //int b;
   cin >> a;
   bool iseven;
   iseven = a & 1;
   cout << iseven << "  ���� 0-������, 1-��������";
    return 0;
}