#include <iostream>
#include "mat.h"
using namespace std;
int main()
{
    mat<double> A(4, 4),B(3,4),C(4,3),D;
 
    //为A赋值
    cout << "A=" << endl;
    for (unsigned i = 0; i < A.getRow(); i++)
    {
        for (unsigned j = 0; j < A.getCow(); j++)
        {
            A[i][j] = i+j;
            cout << A[i][j]<<"\t";
        }
        cout << endl;
    }
    cout << endl;
 
    //为B赋值
    cout << "B=" << endl;
    for (unsigned i = 0; i < B.getRow(); i++)
    {
        for (unsigned j = 0; j < B.getCow(); j++)
        {
            B[i][j] = i + j;
            cout << B[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
 
    //为C赋值
    cout << "C=" << endl;
    for (unsigned i = 0; i <C.getRow(); i++)
    {
        for (unsigned j = 0; j < C.getCow(); j++)
        {
            C[i][j] = i*j;
            cout << C[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
 
    //D=B*C
    D = B*C;
    cout << "D = B*C=" << endl;
    for (unsigned i = 0; i <D.getRow(); i++)
    {
        for (unsigned j = 0; j < D.getCow(); j++)
        {
            D[i][j] = i*j;
            cout <<D[i][j] << "\t";
        }
        cout << endl;
    }
 
    cin.get();
}
