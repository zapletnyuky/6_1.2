//рекурсивний спосіб
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int* b, const int size, const int Low, const int High, int i)
{
    b[i] = Low + rand() % (High-Low+1);
    if (i<size-1)
        Create(b, size, Low, High, i+1);
}
void Print(int* b, const int size, int i)
{
    for (int i=0; i<size; i++) cout << setw(4) << b[i];
    cout << endl;
}

int Sum(int* b, const int size, int i, int S)
{
    if (b[i] % 2 ==0 && b[i] % 3 !=0)
        S += b[i];
    if (i<size-1)
        return Sum(b, size, i+1, S);
    else
        return S;
}
int kil(int* b, const int size, int i, int S)
{
    if (b[i] % 2 ==0 && b[i] % 3 !=0)
        S = S +1;
    if (i<size-1)
        return kil(b, size, i+1, S);
    else
        return S;
}
void zam(int* b, const int size, int i)
{
    if (b[i] % 2 ==0 && b[i] % 3 !=0)
        b[i]= 0;
    if (i<size-1)
        zam(b,size,i+1);
    else cout<<endl;
}
    int main()
    {
        srand((unsigned)time(NULL));
        const int n=21;
        int b[n];
        int Low = 10;
        int High = 90;
        Create(b, n, Low, High, 0);
        Print(b, n, 0);
        cout << "S = " << Sum(b, n, 0, 0) << endl;
        cout<<"Kil = "<<kil(b, n, 0, 0)<<endl;
        zam(b,n,0);
        Print(b, n, 0);
        return 0;
    }
